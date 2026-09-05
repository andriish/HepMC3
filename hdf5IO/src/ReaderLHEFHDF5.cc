// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2026 The HepMC collaboration (see AUTHORS for details)
//

#include "HepMC3/ReaderLHEFHDF5.h"

#include "HepMC3/GenCrossSection.h"
#include "HepMC3/GenEvent.h"
#include "HepMC3/GenParticle.h"
#include "HepMC3/GenPdfInfo.h"
#include "HepMC3/GenRunInfo.h"
#include "HepMC3/GenVertex.h"
#include "HepMC3/LHEFAttributes.h"

#include <cmath>
#include <map>
#include <memory>
#include <utility>
#include <vector>

namespace HepMC3 {

ReaderLHEFHDF5::ReaderLHEFHDF5(const std::string &filename)
    : m_reader(new LHEFHDF5::Reader(filename)) {
    init();
}

ReaderLHEFHDF5::~ReaderLHEFHDF5() {
    close();
}

void ReaderLHEFHDF5::init() {
    std::shared_ptr<HEPRUPAttribute> hepr(new HEPRUPAttribute());
    hepr->heprup = m_reader->heprup;

    set_run_info(std::make_shared<GenRunInfo>());
    run_info()->add_attribute("HEPRUP", hepr);
    run_info()->add_attribute("NPRUP", std::make_shared<IntAttribute>(hepr->heprup.NPRUP));
    run_info()->add_attribute("XSECUP", std::make_shared<VectorDoubleAttribute>(hepr->heprup.XSECUP));
    run_info()->add_attribute("XERRUP", std::make_shared<VectorDoubleAttribute>(hepr->heprup.XERRUP));
    run_info()->add_attribute("LPRUP", std::make_shared<VectorIntAttribute>(hepr->heprup.LPRUP));
    run_info()->add_attribute("PDFGUP1", std::make_shared<IntAttribute>(hepr->heprup.PDFGUP.first));
    run_info()->add_attribute("PDFGUP2", std::make_shared<IntAttribute>(hepr->heprup.PDFGUP.second));
    run_info()->add_attribute("PDFSUP1", std::make_shared<IntAttribute>(hepr->heprup.PDFSUP.first));
    run_info()->add_attribute("PDFSUP2", std::make_shared<IntAttribute>(hepr->heprup.PDFSUP.second));
    run_info()->add_attribute("IDBMUP1", std::make_shared<IntAttribute>(hepr->heprup.IDBMUP.first));
    run_info()->add_attribute("IDBMUP2", std::make_shared<IntAttribute>(hepr->heprup.IDBMUP.second));
    run_info()->add_attribute("EBMUP1", std::make_shared<DoubleAttribute>(hepr->heprup.EBMUP.first));
    run_info()->add_attribute("EBMUP2", std::make_shared<DoubleAttribute>(hepr->heprup.EBMUP.second));

    std::vector<std::string> weight_names;
    weight_names.push_back("Default");
    for (std::size_t index = 0; index < hepr->heprup.weightinfo.size(); ++index)
        weight_names.push_back(hepr->heprup.weightNameHepMC(index));
    run_info()->set_weight_names(weight_names);
}

bool ReaderLHEFHDF5::read_event(GenEvent &event) {
    if (!m_reader->readEvent()) return false;

    const LHEF::HEPEUP &hepeup = m_reader->hepeup;
    const LHEF::HEPRUP &heprup = m_reader->heprup;
    event.clear();
    event.set_run_info(run_info());
    event.set_event_number(m_neve++);
    std::shared_ptr<HEPEUPAttribute> hepe(new HEPEUPAttribute());
    hepe->hepeup = hepeup;
    event.add_attribute("HEPEUP", hepe);
    event.add_attribute("AlphaQCD", std::make_shared<DoubleAttribute>(hepeup.AQCDUP));
    event.add_attribute("AlphaEM", std::make_shared<DoubleAttribute>(hepeup.AQEDUP));
    event.add_attribute("NUP", std::make_shared<IntAttribute>(hepeup.NUP));
    event.add_attribute("IDPRUP", std::make_shared<LongAttribute>(hepeup.IDPRUP));

    std::vector<GenParticlePtr> particles;
    particles.reserve(hepeup.NUP);
    std::map<std::pair<int, int>, GenVertexPtr> vertices;
    for (int index = 0; index < hepeup.NUP; ++index) {
        const FourVector momentum(hepeup.PUP[index][0], hepeup.PUP[index][1],
                                  hepeup.PUP[index][2], hepeup.PUP[index][3]);
        particles.push_back(std::make_shared<GenParticle>(momentum, hepeup.IDUP[index], hepeup.ISTUP[index]));
        if (index < 2) continue;
        const std::pair<int, int> vertex_index(hepeup.MOTHUP[index].first, hepeup.MOTHUP[index].second);
        if (vertices.count(vertex_index) == 0) vertices[vertex_index] = std::make_shared<GenVertex>();
        vertices[vertex_index]->add_particle_out(particles.back());
    }
    for (std::map<std::pair<int, int>, GenVertexPtr>::iterator iterator = vertices.begin(); iterator != vertices.end(); ++iterator)
        for (int index = iterator->first.first - 1; index < iterator->first.second; ++index)
            if (index >= 0 && index < static_cast<int>(particles.size())) iterator->second->add_particle_in(particles[index]);

    const std::pair<int, int> initial_vertex(0, 0);
    if (vertices.count(initial_vertex) == 0) vertices[initial_vertex] = std::make_shared<GenVertex>();
    for (std::size_t index = 0; index < particles.size(); ++index)
        if (!particles[index]->end_vertex() && !particles[index]->production_vertex()) {
            if (index < 2) vertices[initial_vertex]->add_particle_in(particles[index]);
            else vertices[initial_vertex]->add_particle_out(particles[index]);
        }
    for (std::map<std::pair<int, int>, GenVertexPtr>::iterator iterator = vertices.begin(); iterator != vertices.end(); ++iterator)
        if (!iterator->second->particles_in().empty() && !iterator->second->particles_out().empty()) event.add_vertex(iterator->second);

    const long beam_ids[] = {heprup.IDBMUP.first, heprup.IDBMUP.second};
    const double beam_energies[] = {heprup.EBMUP.first, heprup.EBMUP.second};
    std::size_t incoming_index = 0;
    for (int beam_index = 0; beam_index < 2; ++beam_index) {
        if (beam_ids[beam_index] == 0) continue;
        if (incoming_index >= particles.size() || particles[incoming_index]->status() != -1) {
            HEPMC3_ERROR("ReaderLHEFHDF5::read_event: missing incoming beam particle.")
            return false;
        }
        const double pz = beam_index == 0 ? beam_energies[beam_index] : -beam_energies[beam_index];
        GenParticlePtr beam = std::make_shared<GenParticle>(FourVector(0, 0, pz, beam_energies[beam_index]), beam_ids[beam_index], 4);
        GenVertexPtr beam_vertex = std::make_shared<GenVertex>();
        beam_vertex->add_particle_in(beam);
        beam_vertex->add_particle_out(particles[incoming_index++]);
        event.add_beam_particle(beam);
        event.add_vertex(beam_vertex);
    }

    std::vector<double> weights;
    for (std::size_t index = 0; index < hepeup.weights.size(); ++index) weights.push_back(hepeup.weights[index].first);
    event.weights() = weights;

    std::shared_ptr<GenCrossSection> cross_section = std::make_shared<GenCrossSection>();
    cross_section->set_cross_section(heprup.XSECUP, heprup.XERRUP);
    event.add_attribute("GenCrossSection", cross_section);

    if (particles.size() >= 2 && heprup.EBMUP.first != 0.0 && heprup.EBMUP.second != 0.0) {
        std::shared_ptr<GenPdfInfo> pdf_info = std::make_shared<GenPdfInfo>();
        pdf_info->parton_id[0] = particles[0]->pdg_id();
        pdf_info->parton_id[1] = particles[1]->pdg_id();
        pdf_info->x[0] = std::abs(particles[0]->momentum().pz() / heprup.EBMUP.first);
        pdf_info->x[1] = std::abs(particles[1]->momentum().pz() / heprup.EBMUP.second);
        pdf_info->scale = hepeup.pdfinfo.scale;
        pdf_info->xf[0] = 1;
        pdf_info->xf[1] = 1;
        pdf_info->pdf_id[0] = heprup.PDFSUP.first;
        pdf_info->pdf_id[1] = heprup.PDFSUP.second;
        event.add_attribute("GenPdfInfo", pdf_info);
    }
    return true;
}

bool ReaderLHEFHDF5::skip(const int n) {
    return m_reader->skip(n);
}

bool ReaderLHEFHDF5::failed() {
    return m_reader->failed();
}

void ReaderLHEFHDF5::close() {
    if (m_reader) m_reader->close();
}

} // namespace HepMC3