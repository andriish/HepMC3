// g++ -std=c++17 -I/path/to/highfive/include -lhdf5 main.cpp -o main

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

#include <highfive/H5File.hpp>
#include "HepMC3/GenEvent.h"
#include "HepMC3/GenParticle.h"
#include "HepMC3/GenVertex.h"
#include "HepMC3/GenRunInfo.h"
#include "HepMC3/Data/GenEventData.h"
#include "HepMC3/Data/GenRunInfoData.h"
#include "HepMC3/hdf5Utils.h"

using namespace HepMC3;
using namespace HDF5Utils;

// ======================= Write GenEvent =======================

void writeEvent(HighFive::Group& g, const GenEvent& evt) {
    GenEventData ev;
    evt.write_data(ev);

    // Scalars as attributes
    g.createAttribute("event_number", ev.event_number);

    int mu = static_cast<int>(ev.momentum_unit);
    int lu = static_cast<int>(ev.length_unit);
    g.createAttribute("momentum_unit", mu);
    g.createAttribute("length_unit", lu);

    // Event position as dataset
    H5FourVector pos = toH5(ev.event_pos);
    {
        HighFive::DataSet ds = g.createDataSet(
            "event_pos",
            HighFive::DataSpace::From(pos),
            createFourVectorType()
        );
        ds.write_raw(&pos, createFourVectorType());
    }

    // Particles
    std::vector<H5Particle> pvec;
    pvec.reserve(ev.particles.size());
    for (const auto& p : ev.particles) {
        pvec.push_back(toH5(p));
    }
    {
        HighFive::DataSet ds = g.createDataSet(
            "particles",
            HighFive::DataSpace::From(pvec),
            createParticleType()
        );
        ds.write_raw(pvec.data(), createParticleType());
    }

    // Vertices
    std::vector<H5Vertex> vvec;
    vvec.reserve(ev.vertices.size());
    for (const auto& v : ev.vertices) {
        vvec.push_back(toH5(v));
    }
    {
        HighFive::DataSet ds = g.createDataSet(
            "vertices",
            HighFive::DataSpace::From(vvec),
            createVertexType()
        );
        ds.write_raw(vvec.data(), createVertexType());
    }

    // Simple numeric vectors
    if (!ev.weights.empty())
        g.createDataSet("weights", ev.weights);
    else
        g.createDataSet<double>("weights", HighFive::DataSpace::From(ev.weights));

    if (!ev.links1.empty())
        g.createDataSet("links1", ev.links1);
    else
        g.createDataSet<int>("links1", HighFive::DataSpace::From(ev.links1));

    if (!ev.links2.empty())
        g.createDataSet("links2", ev.links2);
    else
        g.createDataSet<int>("links2", HighFive::DataSpace::From(ev.links2));

    if (!ev.attribute_id.empty())
        g.createDataSet("attribute_id", ev.attribute_id);
    else
        g.createDataSet<int>("attribute_id", HighFive::DataSpace::From(ev.attribute_id));

    // Strings (HighFive handles variable-length strings)
    if (!ev.attribute_name.empty())
        g.createDataSet("attribute_name", ev.attribute_name);

    if (!ev.attribute_string.empty())
        g.createDataSet("attribute_string", ev.attribute_string);
}

// ======================= Write GenRunInfo =======================

void writeRunInfo(HighFive::Group& g, const GenRunInfo& run) {
    GenRunInfoData rd;
    run.write_data(rd);

    HighFive::Group rg = g.createGroup("run_info");

    if (!rd.weight_names.empty())
        rg.createDataSet("weight_names", rd.weight_names);

    if (!rd.tool_name.empty())
        rg.createDataSet("tool_name", rd.tool_name);

    if (!rd.tool_version.empty())
        rg.createDataSet("tool_version", rd.tool_version);

    if (!rd.tool_description.empty())
        rg.createDataSet("tool_description", rd.tool_description);

    if (!rd.attribute_name.empty())
        rg.createDataSet("attribute_name", rd.attribute_name);

    if (!rd.attribute_string.empty())
        rg.createDataSet("attribute_string", rd.attribute_string);
}

// ======================= Read GenRunInfo =======================

void readRunInfo(const HighFive::Group& g, GenRunInfo& run) {
    if (!g.exist("run_info")) return;
    HighFive::Group rg = g.getGroup("run_info");
    GenRunInfoData rd;

    if (rg.exist("weight_names")) rg.getDataSet("weight_names").read(rd.weight_names);
    if (rg.exist("tool_name")) rg.getDataSet("tool_name").read(rd.tool_name);
    if (rg.exist("tool_version")) rg.getDataSet("tool_version").read(rd.tool_version);
    if (rg.exist("tool_description")) rg.getDataSet("tool_description").read(rd.tool_description);
    if (rg.exist("attribute_name")) rg.getDataSet("attribute_name").read(rd.attribute_name);
    if (rg.exist("attribute_string")) rg.getDataSet("attribute_string").read(rd.attribute_string);

    run.read_data(rd);
}

// ======================= Read GenEventData =======================

void readEvent(const HighFive::Group& g, GenEvent& e) {
    GenEventData ev;

    // Scalars
    g.getAttribute("event_number").read(ev.event_number);

    int mu = 0, lu = 0;
    g.getAttribute("momentum_unit").read(mu);
    g.getAttribute("length_unit").read(lu);
    ev.momentum_unit = static_cast<Units::MomentumUnit>(mu);
    ev.length_unit   = static_cast<Units::LengthUnit>(lu);

    // Event position
    {
        H5FourVector pos;
        auto ds = g.getDataSet("event_pos");
        ds.read_raw(&pos, createFourVectorType());
        ev.event_pos = fromH5(pos);
    }

    // Particles
    {
        auto ds = g.getDataSet("particles");
        const std::vector<size_t> dims = ds.getSpace().getDimensions();
        std::vector<H5Particle> pvec;
        if (!dims.empty()) {
            pvec.resize(dims[0]);
            ds.read_raw(pvec.data(), createParticleType());
        }
        ev.particles.clear();
        ev.particles.reserve(pvec.size());
        for (const auto& p : pvec) {
            ev.particles.push_back(fromH5(p));
        }
    }

    // Vertices
    {
        auto ds = g.getDataSet("vertices");
        const std::vector<size_t> dims = ds.getSpace().getDimensions();
        std::vector<H5Vertex> vvec;
        if (!dims.empty()) {
            vvec.resize(dims[0]);
            ds.read_raw(vvec.data(), createVertexType());
        }
        ev.vertices.clear();
        ev.vertices.reserve(vvec.size());
        for (const auto& v : vvec) {
            ev.vertices.push_back(fromH5(v));
        }
    }

    // Simple numeric vectors
    if (g.exist("weights"))
        g.getDataSet("weights").read(ev.weights);

    if (g.exist("links1"))
        g.getDataSet("links1").read(ev.links1);

    if (g.exist("links2"))
        g.getDataSet("links2").read(ev.links2);

    if (g.exist("attribute_id"))
        g.getDataSet("attribute_id").read(ev.attribute_id);

    // Strings
    if (g.exist("attribute_name"))
        g.getDataSet("attribute_name").read(ev.attribute_name);

    if (g.exist("attribute_string"))
        g.getDataSet("attribute_string").read(ev.attribute_string);

    e.read_data(ev);
}

static GenEvent createSampleEvent() {
    GenEvent evt(Units::MomentumUnit::GEV, Units::LengthUnit::MM);
    evt.set_event_number(42);
    evt.shift_position_to(FourVector{0.1, 0.2, 0.3, 1.0});

    auto p1 = std::make_shared<GenParticle>(FourVector{1.0, 0.0, 0.0, 1.0}, 11, 1);
    p1->set_generated_mass(0.000511);
    auto p2 = std::make_shared<GenParticle>(FourVector{-1.0, 0.0, 0.0, 1.0}, -11, 1);
    p2->set_generated_mass(0.000511);

    auto v1 = std::make_shared<GenVertex>(FourVector{0.0, 0.0, 0.0, 0.0});
    v1->set_status(0);
    v1->add_particle_out(p1);
    v1->add_particle_out(p2);
    evt.add_vertex(v1);

    evt.weights() = {1.0, 0.5};

    auto run = std::make_shared<GenRunInfo>();
    run->set_weight_names({"w0", "w1"});
    evt.set_run_info(run);

    return evt;
}

// ======================= Example main =======================

int main() {
    try {
        GenEvent evt = createSampleEvent();
        auto run = evt.run_info();

        // Write
        HighFive::File file("event.h5", HighFive::File::Overwrite);
        HighFive::Group g = file.createGroup("/event_0001");
        writeEvent(g, evt);
        if (run) writeRunInfo(g, *run);

        // Read back into a HepMC3 GenEvent
        HighFive::File file_in("event.h5", HighFive::File::ReadOnly);
        HighFive::Group g_in = file_in.getGroup("/event_0001");
        GenEvent evt2(Units::MomentumUnit::GEV, Units::LengthUnit::MM);
        auto run2 = std::make_shared<GenRunInfo>();
        readRunInfo(g_in, *run2);
        evt2.set_run_info(run2);
        readEvent(g_in, evt2);

        std::cout << "Read event_number = " << evt2.event_number() << "\n";
        std::cout << "Particles: " << evt2.particles().size() << "\n";
        std::cout << "Vertices: " << evt2.vertices().size() << "\n";
        std::cout << "Weights: " << evt2.weights().size() << "\n";
        std::cout << "Attributes: " << evt2.attribute_names().size() << "\n";
        std::cout << "Run weight names: ";
        for (const auto &name : evt2.run_info()->weight_names()) std::cout << name << " ";
        std::cout << "\n";
    } catch (const HighFive::Exception& e) {
        std::cerr << "HighFive error: " << e.what() << "\n";
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Std error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
