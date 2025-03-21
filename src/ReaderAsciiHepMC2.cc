// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2023 The HepMC collaboration (see AUTHORS for details)
//
/**
 *  @file ReaderAsciiHepMC2.cc
 *  @brief Implementation of \b class ReaderAsciiHepMC2
 *
 */
#include <array>
#include <cstdlib>
#include <cstring>

#include "HepMC3/GenEvent.h"
#include "HepMC3/GenHeavyIon.h"
#include "HepMC3/GenParticle.h"
#include "HepMC3/GenPdfInfo.h"
#include "HepMC3/GenVertex.h"
#include "HepMC3/ReaderAsciiHepMC2.h"
#include "HepMC3/Setup.h"

namespace HepMC3 {

ReaderAsciiHepMC2::ReaderAsciiHepMC2(const std::string& filename):
    m_file(filename), m_isstream(false) {
    if ( !m_file.is_open() ) {
        HEPMC3_ERROR_LEVEL(100,"ReaderAsciiHepMC2: could not open input file: " << filename )
    }
    set_run_info(std::make_shared<GenRunInfo>());
    m_event_ghost = new GenEvent();
}

ReaderAsciiHepMC2::ReaderAsciiHepMC2(std::istream & stream)
    : m_stream(&stream), m_isstream(true)
{
    if ( !m_stream->good() ) {
        HEPMC3_ERROR_LEVEL(100,"ReaderAsciiHepMC2: could not open input stream ")
    }
    set_run_info(std::make_shared<GenRunInfo>());
    m_event_ghost = new GenEvent();
}

ReaderAsciiHepMC2::ReaderAsciiHepMC2(std::shared_ptr<std::istream> s_stream)
    : m_shared_stream(s_stream), m_stream(s_stream.get()), m_isstream(true)
{
    if ( !m_stream->good() ) {
        HEPMC3_ERROR_LEVEL(100,"ReaderAsciiHepMC2: could not open input stream ")
    }
    set_run_info(std::make_shared<GenRunInfo>());
    m_event_ghost = new GenEvent();
}


ReaderAsciiHepMC2::~ReaderAsciiHepMC2() { if (m_event_ghost) { m_event_ghost->clear(); delete m_event_ghost; m_event_ghost=nullptr; } if (!m_isstream) close(); }

bool ReaderAsciiHepMC2::skip(const int n)
{
    std::array<char, 262144> buf{};
    int nn = n;
    while (!failed()) {
        char peek(0);
        if ( (!m_file.is_open()) && (!m_isstream) ) return false;
        m_isstream ? peek = m_stream->peek() : peek = m_file.peek();
        if ( peek =='E' ) nn--;
        if (nn < 0) { return true; }
        m_isstream ? m_stream->getline(buf.data(), buf.size()) : m_file.getline(buf.data(), buf.size());
    }
    return true;
}

bool ReaderAsciiHepMC2::read_event(GenEvent &evt) {
    if ( (!m_file.is_open()) && (!m_isstream) ) return false;

    char               peek = 0;
    std::array<char, 262144> buf{};
    bool          parsed_event_header            = false;
    bool          is_parsing_successful          = true;
    int           parsing_result                 = 0;
    unsigned int  vertices_count                 = 0;
    unsigned int  current_vertex_particles_count = 0;
    unsigned int  current_vertex_particles_parsed = 0;

    evt.clear();
    evt.set_run_info(run_info());

    // Empty cache
    m_vertex_cache.clear();
    m_vertex_barcodes.clear();

    m_particle_cache.clear();
    m_end_vertex_barcodes.clear();
    m_particle_cache_ghost.clear();
    m_vertex_cache_ghost.clear();
    //
    // Parse event, vertex and particle information
    //
    while (!failed()) {
        m_isstream ? m_stream->getline(buf.data(), buf.size()) : m_file.getline(buf.data(), buf.size());
        if ( strlen(buf.data()) == 0 ) continue;
        // Check for IO_GenEvent header/footer
        if ( strncmp(buf.data(), "HepMC", 5) == 0 ) {
            if ( strncmp(buf.data(), "HepMC::Version", 14) != 0 && strncmp(buf.data(), "HepMC::IO_GenEvent", 18) != 0 )
            {
                HEPMC3_WARNING_LEVEL(500,"ReaderAsciiHepMC2: found unsupported expression in header. Will close the input.")
                std::cout <<buf.data() << std::endl;
                m_isstream ? m_stream->clear(std::ios::eofbit) : m_file.clear(std::ios::eofbit);
            }
            if (parsed_event_header) {
                is_parsing_successful = true;
                break;
            }
            continue;
        }
        switch (buf[0]) {
        case 'E':
            parsing_result = parse_event_information(evt, buf.data());
            if (parsing_result < 0) {
                is_parsing_successful = false;
                HEPMC3_ERROR_LEVEL(600,"ReaderAsciiHepMC2: HEPMC3_ERROR parsing event information")
            }
            else {
                vertices_count = parsing_result;
                m_vertex_cache.reserve(vertices_count);
                m_particle_cache.reserve(vertices_count*3);
                m_vertex_cache_ghost.reserve(vertices_count);
                m_particle_cache_ghost.reserve(vertices_count*3);
                m_vertex_barcodes.reserve(vertices_count);
                m_end_vertex_barcodes.reserve(vertices_count*3);
                // Here we make a trick: reserve for this event the vertices_count*3 or the number of particles in the prev. event.
                evt.reserve(vertices_count, m_particle_cache_ghost.capacity());
                is_parsing_successful = true;
            }
            parsed_event_header = true;
            break;
        case 'V':
            // If starting new vertex: verify if previous was fully parsed

            /** HepMC2 files produced with Pythia8 are known to have wrong
                     information about number of particles in vertex. Hence '<' sign */
            if (current_vertex_particles_parsed < current_vertex_particles_count) {
                is_parsing_successful = false;
                break;
            }
            current_vertex_particles_parsed = 0;

            parsing_result = parse_vertex_information(buf.data());

            if (parsing_result < 0) {
                is_parsing_successful = false;
                HEPMC3_ERROR_LEVEL(600,"ReaderAsciiHepMC2: HEPMC3_ERROR parsing vertex information")
            }
            else {
                current_vertex_particles_count = parsing_result;
                is_parsing_successful = true;
            }
            break;
        case 'P':

            parsing_result   = parse_particle_information(buf.data());

            if (parsing_result < 0) {
                is_parsing_successful = false;
                HEPMC3_ERROR_LEVEL(600,"ReaderAsciiHepMC2: HEPMC3_ERROR parsing particle information")
            }
            else {
                ++current_vertex_particles_parsed;
                is_parsing_successful = true;
            }
            break;
        case 'U':
            is_parsing_successful = parse_units(evt, buf.data());
            break;
        case 'F':
            is_parsing_successful = parse_pdf_info(evt, buf.data());
            break;
        case 'H':
            is_parsing_successful = parse_heavy_ion(evt, buf.data());
            break;
        case 'N':
            is_parsing_successful = parse_weight_names(buf.data());
            break;
        case 'C':
            is_parsing_successful = parse_xs_info(evt, buf.data());
            break;
        default:
            HEPMC3_WARNING_LEVEL(500,"ReaderAsciiHepMC2: skipping unrecognised prefix: " << buf[0])
            is_parsing_successful = true;
            break;
        }

        if ( !is_parsing_successful ) break;

        // Check for next event
        m_isstream ? peek = m_stream->peek() : peek = m_file.peek();
        if ( parsed_event_header && peek == 'E' ) break;
    }

    // Check if all particles in last vertex were parsed
    /** HepMC2 files produced with Pythia8 are known to have wrong
             information about number of particles in vertex. Hence '<' sign */
    if (is_parsing_successful && current_vertex_particles_parsed < current_vertex_particles_count) {
        HEPMC3_ERROR_LEVEL(600,"ReaderAsciiHepMC2: not all particles parsed")
        is_parsing_successful = false;
    }
    // Check if all vertices were parsed
    else if (is_parsing_successful && m_vertex_cache.size() != vertices_count) {
        HEPMC3_ERROR_LEVEL(600,"ReaderAsciiHepMC2: not all vertices parsed")
        is_parsing_successful = false;
    }

    if ( !is_parsing_successful ) {
        HEPMC3_ERROR_LEVEL(600,"ReaderAsciiHepMC2: event parsing failed. Returning empty event")
        HEPMC3_DEBUG(1, "Parsing failed at line:" << std::endl << buf.data())
        evt.clear();
        m_isstream ? m_stream->clear(std::ios::badbit) : m_file.clear(std::ios::badbit);
        return false;
    }
    if (run_info() && run_info()->weight_names().empty() ) {
        run_info()->set_weight_names(std::vector<std::string> {"Default"});
    }
    if (evt.weights().empty()) {
        HEPMC3_WARNING_LEVEL(600,"ReaderAsciiHepMC2: weights are empty, an event weight 1.0 will be added.")
        evt.weights().push_back(1.0);
    }

    // Restore production vertex pointers
    for (unsigned int i = 0; i < m_particle_cache.size(); ++i) {
        if ( !m_end_vertex_barcodes[i] ) continue;

        for (unsigned int j = 0; j < m_vertex_cache.size(); ++j) {
            if ( m_vertex_barcodes[j] == m_end_vertex_barcodes[i] ) {
                m_vertex_cache[j]->add_particle_in(m_particle_cache[i]);
                break;
            }
        }
    }

    // Remove vertices with no incoming particles or no outgoing particles
    for (unsigned int i = 0; i < m_vertex_cache.size(); ++i) {
        if ( m_vertex_cache[i]->particles_in().empty() ) {
            HEPMC3_DEBUG(30, "ReaderAsciiHepMC2::read_event - found a vertex without incoming particles: " << m_vertex_cache[i]->id() );
            //Sometimes the root vertex has no incoming particles.  Here we try to save the event.
            std::vector<GenParticlePtr> beams;
            beams.reserve(2);
            for (const auto& p: m_vertex_cache[i]->particles_out()) if (p->status() == 4 && !(p->end_vertex())) beams.emplace_back(p);
            for (auto& p: beams)
            {
                m_vertex_cache[i]->add_particle_in(p);
                m_vertex_cache[i]->remove_particle_out(p);
                HEPMC3_DEBUG(30, "ReaderAsciiHepMC2::read_event - moved particle with status=4 from the outgoing to the incoming particles of vertex: " << m_vertex_cache[i]->id());
            }
            if (beams.empty()) {
                HEPMC3_DEBUG(30, "ReaderAsciiHepMC2::read_event - removed vertex without incoming particles: " << m_vertex_cache[i]->id() );
                m_vertex_cache[i] = nullptr;
            }
        }
        else if ( m_vertex_cache[i]->particles_out().empty() ) {
            m_vertex_cache[i] = nullptr;
            HEPMC3_DEBUG(30, "ReaderAsciiHepMC2::read_event - removed vertex without outgoing particles: " << m_vertex_cache[i]->id());
        }
    }

    // Reserve memory for the event
    evt.reserve(m_particle_cache.size(), m_vertex_cache.size());

    // Add whole event tree in topological order
    evt.add_tree(m_particle_cache);

    if (m_options.count("event_random_states_are_separated") != 0)
    {
        std::shared_ptr<VectorLongIntAttribute> random_states_a = evt.attribute<VectorLongIntAttribute>("random_states");
        if (random_states_a) {
            std::vector<long int> random_states_v = random_states_a->value();
            for (size_t i = 0; i < random_states_v.size(); ++i ) {
                evt.add_attribute("random_states" + std::to_string(static_cast<long long unsigned int>(i)), std::make_shared<IntAttribute>(random_states_v[i]));
            }
            evt.remove_attribute("random_states");
        }

    }

    std::map< std::string, std::map<int, std::shared_ptr<Attribute> > > cached_attributes = m_event_ghost->attributes();
    if (cached_attributes.count("flows") != 0) {
        const std::map<int, std::shared_ptr<Attribute> >& flows = cached_attributes.at("flows");
        if (m_options.count("particle_flows_are_separated") == 0) {
            for (const auto& f: flows) if (f.first > 0 && f.first <= static_cast<int>(m_particle_cache.size())) {  m_particle_cache[f.first-1]->add_attribute("flows", f.second);}
        } else  {
            for (const auto& f: flows) {
                if (f.first > 0 && f.first <= static_cast<int>(m_particle_cache.size())) {
                    std::shared_ptr<VectorIntAttribute>  casted = std::dynamic_pointer_cast<VectorIntAttribute>(f.second);
                    if (!casted) continue;//Should not happen
                    std::vector<int> this_p_flow = casted->value();
                    for (size_t i = 0; i<this_p_flow.size(); i++) m_particle_cache[f.first-1]->add_attribute("flow" + std::to_string(i + 1), std::make_shared<IntAttribute>(this_p_flow[i]));
                }
            }
        }
    }

    if (cached_attributes.count("phi") != 0) {
        const std::map<int, std::shared_ptr<Attribute> >& phi = cached_attributes.at("phi");
        for (const auto& f: phi) if (f.first > 0 &&f.first <= static_cast<int>(m_particle_cache.size()))  m_particle_cache[f.first-1]->add_attribute("phi", f.second);
    }

    if (cached_attributes.count("theta") != 0) {
        const std::map<int, std::shared_ptr<Attribute> >& theta = cached_attributes.at("theta");
        for (const auto& f: theta) if (f.first > 0 && f.first <= static_cast<int>(m_particle_cache.size()))  m_particle_cache[f.first-1]->add_attribute("theta", f.second);
    }

    if (cached_attributes.count("weights") != 0) {
        const std::map<int, std::shared_ptr<Attribute> >& weights = cached_attributes.at("weights");
        if (m_options.count("vertex_weights_are_separated") == 0) {
            for (const auto& f: weights) { if (f.first < 0 && f.first >= -static_cast<int>(m_vertex_cache.size()))  m_vertex_cache[-f.first-1]->add_attribute("weights", f.second);}
        } else {
            for (const auto& f: weights) {
                if (f.first < 0 && f.first >= -static_cast<int>(m_vertex_cache.size())) {
                    std::shared_ptr<VectorDoubleAttribute>  casted = std::dynamic_pointer_cast<VectorDoubleAttribute>(f.second);
                    if (!casted) continue;//Should not happen
                    std::vector<double> this_v_weight = casted->value();
                    for (size_t i = 0; i < this_v_weight.size(); i++) m_particle_cache[-f.first-1]->add_attribute("weight"+std::to_string(i), std::make_shared<DoubleAttribute>(this_v_weight[i]));
                }
            }
        }
    }
    std::shared_ptr<IntAttribute> signal_process_vertex_barcode = evt.attribute<IntAttribute>("signal_process_vertex");
    if (signal_process_vertex_barcode) {
        int signal_process_vertex_barcode_value = signal_process_vertex_barcode->value();
        for (unsigned int i = 0; i < m_vertex_cache.size(); ++i)
        {
            if (i >= m_vertex_barcodes.size()) continue;//this should not happen!
            if (signal_process_vertex_barcode_value != m_vertex_barcodes.at(i)) continue;
            std::shared_ptr<IntAttribute> signal_process_vertex = std::make_shared<IntAttribute>(m_vertex_cache.at(i)->id());
            evt.add_attribute("signal_process_vertex", signal_process_vertex);
            break;
        }
    }
    m_particle_cache_ghost.clear();
    m_vertex_cache_ghost.clear();
    m_event_ghost->clear();
    return true;
}

int ReaderAsciiHepMC2::parse_event_information(GenEvent &evt, const char *buf) {
    const char          *cursor             = buf;
    size_t               vertices_count     = 0;
    int                  random_states_size = 0;
    int                  weights_size       = 0;
    std::vector<long>    random_states(0);
    std::vector<double>  weights(0);

    // event number
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    evt.set_event_number(atoi(cursor));

    //mpi
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    evt.add_attribute("mpi", std::make_shared<IntAttribute>(atoi(cursor)));

    //event scale
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    evt.add_attribute("event_scale", std::make_shared<DoubleAttribute>(atof(cursor)));

    //alpha_qcd
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    evt.add_attribute("alphaQCD", std::make_shared<DoubleAttribute>(atof(cursor)));

    //alpha_qed
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    evt.add_attribute("alphaQED", std::make_shared<DoubleAttribute>(atof(cursor)));

    //signal_process_id
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    evt.add_attribute("signal_process_id", std::make_shared<IntAttribute>(atoi(cursor)));

    //signal_process_vertex
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    evt.add_attribute("signal_process_vertex", std::make_shared<IntAttribute>(atoi(cursor)));

    // num_vertices
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    vertices_count = atoi(cursor);

    // SKIPPED: beam 1
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;

    // SKIPPED: beam 2
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;

    //random states
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    random_states_size = atoi(cursor);
    if (random_states_size >= 0 ) {
        random_states.resize(random_states_size);
    } else {
        HEPMC3_DEBUG(0, "ReaderAsciiHepMC2: E: " << evt.event_number() << " (" << vertices_count << "V, "  << random_states_size << "RS)")
    }
    for ( int i = 0; i < random_states_size; ++i ) {
        if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
        random_states[i] = atoi(cursor);
    }

    if (!random_states.empty()) evt.add_attribute("random_states", std::make_shared<VectorLongIntAttribute>(random_states));

    // weights
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    weights_size = atoi(cursor);
    if (weights_size >= 0 ) {
        weights.resize(weights_size);
    } else {
        HEPMC3_DEBUG(0, "ReaderAsciiHepMC2: E: " << evt.event_number() << " (" << vertices_count << "V, " << weights_size << "WS)")
    }
    for ( int i = 0; i < weights_size; ++i ) {
        if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
        weights[i] = atof(cursor);
    }

    evt.weights() = weights;

    HEPMC3_DEBUG(10, "ReaderAsciiHepMC2: E: " << evt.event_number() << " (" << vertices_count << "V, " << weights_size << "W, " << random_states_size << "RS)")

    return vertices_count;
}

bool ReaderAsciiHepMC2::parse_units(GenEvent &evt, const char *buf) {
    const char *cursor  = buf;

    // momentum
    if ( !(cursor = strchr(cursor+1, ' ')) ) return false;
    ++cursor;
    Units::MomentumUnit momentum_unit = Units::momentum_unit(cursor);

    // length
    if ( !(cursor = strchr(cursor+1, ' ')) ) return false;
    ++cursor;
    Units::LengthUnit length_unit = Units::length_unit(cursor);

    evt.set_units(momentum_unit, length_unit);

    HEPMC3_DEBUG(10, "ReaderAsciiHepMC2: U: " << Units::name(evt.momentum_unit()) << " " << Units::name(evt.length_unit()))

    return true;
}

int ReaderAsciiHepMC2::parse_vertex_information(const char *buf) {
    GenVertexPtr  data = std::make_shared<GenVertex>();
    GenVertexPtr  data_ghost = std::make_shared<GenVertex>();
    const char   *cursor            = buf;
    int           barcode           = 0;
    int           num_particles_out = 0;
    int                  weights_size       = 0;
    std::vector<double>  weights(0);
    // barcode
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    barcode = atoi(cursor);

    // status
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    data->set_status(atoi(cursor));

    // x
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    double X(atof(cursor));

    // y
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    double Y(atof(cursor));

    // z
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    double Z(atof(cursor));

    // t
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    double T(atof(cursor));
    data->set_position(FourVector(X,Y,Z,T));

    // SKIPPED: num_orphans_in
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;

    // num_particles_out
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    num_particles_out = atoi(cursor);

    //  weights
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    weights_size = atoi(cursor);
    weights.resize(weights_size);

    for ( int i = 0; i < weights_size; ++i ) {
        if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
        weights[i] = atof(cursor);
    }



    // Add original vertex barcode to the cache
    m_vertex_cache.emplace_back(data);
    m_vertex_barcodes.emplace_back(barcode);

    m_event_ghost->add_vertex(data_ghost);

    if (!weights.empty()) data_ghost->add_attribute("weights", std::make_shared<VectorDoubleAttribute>(weights));

    m_vertex_cache_ghost.emplace_back(data_ghost);

    HEPMC3_DEBUG(10, "ReaderAsciiHepMC2: V: " << -static_cast<int>(m_vertex_cache.size()) << " (old barcode " << barcode << ") " << num_particles_out << " particles)")

    return num_particles_out;
}

int ReaderAsciiHepMC2::parse_particle_information(const char *buf) {
    GenParticlePtr  data = std::make_shared<GenParticle>();
    GenParticlePtr  data_ghost = std::make_shared<GenParticle>();
    m_event_ghost->add_particle(data_ghost);
    const char     *cursor  = buf;
    int             end_vtx = 0;

    /// @note barcode is ignored
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;

    // id
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    data->set_pid(atoi(cursor));

    // px
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    double Px(atof(cursor));

    // py
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    double Py(atof(cursor));

    // pz
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    double Pz(atof(cursor));

    // pe
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    double E(atof(cursor));
    data->set_momentum(FourVector(Px,Py,Pz,E));

    // m
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    data->set_generated_mass(atof(cursor));

    // status
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    data->set_status(atoi(cursor));

    //theta
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    double theta_v = atof(cursor);
    if (theta_v != 0.0) data_ghost->add_attribute("theta", std::make_shared<DoubleAttribute>(theta_v));

    //phi
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    double phi_v = atof(cursor);
    if (phi_v != 0.0) data_ghost->add_attribute("phi", std::make_shared<DoubleAttribute>(phi_v));

    // end_vtx_code
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    end_vtx = atoi(cursor);

    //flow
    if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
    int flowsize = atoi(cursor);

    std::map<int, int> flows;
    for (int i = 0; i < flowsize; i++)
    {
        if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
        int  flowindex = atoi(cursor);
        if ( !(cursor = strchr(cursor+1, ' ')) ) return -1;
        int flowvalue = atoi(cursor);
        flows[flowindex] = flowvalue;
    }
    if (flowsize)
    {
        std::vector<int> vectorflows;
        vectorflows.reserve(flows.size());
        for (const auto& f: flows) { vectorflows.emplace_back(f.second); }
        data_ghost->add_attribute("flows", std::make_shared<VectorIntAttribute>(vectorflows));
    }
    // Set prod_vtx link
    if (m_vertex_cache.empty()) {HEPMC3_DEBUG(1, "The first particle in event appears before the first vertex"); return -1;}
    if ( end_vtx == m_vertex_barcodes.back() ) {
        m_vertex_cache.back()->add_particle_in(data);
        end_vtx = 0;
    }
    else {
        m_vertex_cache.back()->add_particle_out(data);
    }

    m_particle_cache.emplace_back(data);
    m_particle_cache_ghost.emplace_back(data_ghost);
    m_end_vertex_barcodes.emplace_back(end_vtx);

    HEPMC3_DEBUG(10, "ReaderAsciiHepMC2: P: " << m_particle_cache.size() << " ( pid: " << data->pid() << ") end vertex: " << end_vtx)

    return 0;
}

bool ReaderAsciiHepMC2::parse_xs_info(GenEvent &evt, const char *buf) {
    const char *cursor  = buf;
    std::shared_ptr<GenCrossSection>  xs     = std::make_shared<GenCrossSection>();

    if ( !(cursor = strchr(cursor+1, ' ')) ) return false;
    const double xs_val  = atof(cursor);

    if ( !(cursor = strchr(cursor+1, ' ')) ) return false;
    const double xs_err = atof(cursor);
    const size_t all = m_options.count("disable_pad_cross_sections") ? size_t{1} :
                       std::max(evt.weights().size(),size_t{1});
    const double xs_val_dummy = m_options.count("pad_cross_section_value") ? std::strtod(m_options.at("pad_cross_section_value").c_str(),nullptr) : 0.0;
    const double xs_err_dummy = m_options.count("pad_cross_section_error") ? std::strtod(m_options.at("pad_cross_section_error").c_str(),nullptr) : 0.0;
    xs->set_cross_section(std::vector<double>(all,xs_val_dummy), std::vector<double>(all,xs_err_dummy));
    xs->set_xsec(0,xs_val);
    xs->set_xsec_err(0,xs_err);
    evt.add_attribute("GenCrossSection", xs);
    return true;
}

bool ReaderAsciiHepMC2::parse_weight_names(const char *buf) {
    const char     *cursor  = buf;
    const char     *cursor2 = buf;
    int             w_count = 0;
    std::vector<std::string>  w_names;

    // Ignore weight names if no GenRunInfo object
    if ( !run_info() ) return true;

    if ( !(cursor = strchr(cursor+1, ' ')) ) return false;
    w_count = atoi(cursor);

    if ( w_count <= 0 ) return false;

    w_names.resize(w_count);

    for ( int i=0; i < w_count; ++i ) {
        // Find pair of '"' characters
        if ( !(cursor  = strchr(cursor+1, '"')) ) return false;
        if ( !(cursor2 = strchr(cursor+1, '"')) ) return false;

        // Strip cursor of leading '"' character
        ++cursor;

        w_names[i].assign(cursor, cursor2-cursor);

        cursor = cursor2;
    }

    run_info()->set_weight_names(w_names);

    return true;
}

bool ReaderAsciiHepMC2::parse_heavy_ion(GenEvent &evt, const char *buf) {
    std::shared_ptr<GenHeavyIon>  hi     = std::make_shared<GenHeavyIon>();
    const char              *cursor = buf;

    if ( !(cursor = strchr(cursor+1, ' ')) ) return false;
    hi->Ncoll_hard = atoi(cursor);

    if ( !(cursor = strchr(cursor+1, ' ')) ) return false;
    hi->Npart_proj = atoi(cursor);

    if ( !(cursor = strchr(cursor+1, ' ')) ) return false;
    hi->Npart_targ = atoi(cursor);

    if ( !(cursor = strchr(cursor+1, ' ')) ) return false;
    hi->Ncoll = atoi(cursor);

    if ( !(cursor = strchr(cursor+1, ' ')) ) return false;
    hi->spectator_neutrons = atoi(cursor);

    if ( !(cursor = strchr(cursor+1, ' ')) ) return false;
    hi->spectator_protons = atoi(cursor);

    if ( !(cursor = strchr(cursor+1, ' ')) ) return false;
    hi->N_Nwounded_collisions = atoi(cursor);

    if ( !(cursor = strchr(cursor+1, ' ')) ) return false;
    hi->Nwounded_N_collisions = atoi(cursor);

    if ( !(cursor = strchr(cursor+1, ' ')) ) return false;
    hi->Nwounded_Nwounded_collisions = atoi(cursor);

    if ( !(cursor = strchr(cursor+1, ' ')) ) return false;
    hi->impact_parameter = atof(cursor);

    if ( !(cursor = strchr(cursor+1, ' ')) ) return false;
    hi->event_plane_angle = atof(cursor);

    if ( !(cursor = strchr(cursor+1, ' ')) ) return false;
    hi->eccentricity = atof(cursor);

    if ( !(cursor = strchr(cursor+1, ' ')) ) return false;
    hi->sigma_inel_NN = atof(cursor);

    // Not in HepMC2:
    hi->centrality = 0.0;

    evt.add_attribute("GenHeavyIon", hi);

    return true;
}

bool ReaderAsciiHepMC2::parse_pdf_info(GenEvent &evt, const char *buf) {
    std::shared_ptr<GenPdfInfo>  pi     = std::make_shared<GenPdfInfo>();
    const char             *cursor = buf;

    if ( !(cursor = strchr(cursor+1, ' ')) ) return false;
    pi->parton_id[0] = atoi(cursor);

    if ( !(cursor = strchr(cursor+1, ' ')) ) return false;
    pi->parton_id[1] = atoi(cursor);

    if ( !(cursor = strchr(cursor+1, ' ')) ) return false;
    pi->x[0] = atof(cursor);

    if ( !(cursor = strchr(cursor+1, ' ')) ) return false;
    pi->x[1] = atof(cursor);

    if ( !(cursor = strchr(cursor+1, ' ')) ) return false;
    pi->scale = atof(cursor);

    if ( !(cursor = strchr(cursor+1, ' ')) ) return false;
    pi->xf[0] = atof(cursor);

    if ( !(cursor = strchr(cursor+1, ' ')) ) return false;
    pi->xf[1] = atof(cursor);

    //For compatibility with original HepMC2
    bool pdfids = true;
    if ( !(cursor = strchr(cursor+1, ' ')) ) pdfids = false;
    if (pdfids) {pi->pdf_id[0] = atoi(cursor);}
    else  {pi->pdf_id[0] = 0;}

    if (pdfids) if ( !(cursor = strchr(cursor+1, ' ')) )  pdfids = false;
    if (pdfids) { pi->pdf_id[1] = atoi(cursor);}
    else  {pi->pdf_id[1] = 0;}

    evt.add_attribute("GenPdfInfo", pi);

    return true;
}
bool ReaderAsciiHepMC2::failed() { return m_isstream ? static_cast<bool>(m_stream->rdstate()) : static_cast<bool>(m_file.rdstate()); }

void ReaderAsciiHepMC2::close() {
    if (m_event_ghost) { m_event_ghost->clear(); delete m_event_ghost; m_event_ghost = nullptr;}
    if ( !m_file.is_open() ) return;
    m_file.close();
}

} // namespace HepMC3
