// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2023 The HepMC collaboration (see AUTHORS for details)
//

#include "HepMC3/WriterHDF5.h"
#include "HepMC3/Version.h"
#include "HepMC3/GenEvent.h"
#include "HepMC3/GenRunInfo.h"
#include "HepMC3/Data/GenEventData.h"
#include "HepMC3/hdf5Utils.h"

#include <highfive/H5File.hpp>
#include <iomanip>
#include <sstream>

namespace HepMC3 {
HEPMC3_DECLARE_WRITER_FILE(WriterHDF5)

namespace {

using namespace HDF5Utils;

void writeRunInfoToGroup(HighFive::Group &g, const GenRunInfo &run) {
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

void writeEventToGroup(HighFive::Group &g, const GenEvent &evt, const std::shared_ptr<GenRunInfo> &fallback_run_info) {
    GenEventData ev;
    evt.write_data(ev);

    g.createAttribute("event_number", ev.event_number);

    int mu = static_cast<int>(ev.momentum_unit);
    int lu = static_cast<int>(ev.length_unit);
    g.createAttribute("momentum_unit", mu);
    g.createAttribute("length_unit", lu);

    H5FourVector pos = toH5(ev.event_pos);
    {
        HighFive::DataSet ds = g.createDataSet(
            "event_pos",
            HighFive::DataSpace::From(pos),
            createFourVectorType()
        );
        ds.write_raw(&pos, createFourVectorType());
    }

    std::vector<H5Particle> pvec;
    pvec.reserve(ev.particles.size());
    for (const auto &p : ev.particles) {
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

    std::vector<H5Vertex> vvec;
    vvec.reserve(ev.vertices.size());
    for (const auto &v : ev.vertices) {
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

    if (!ev.attribute_name.empty())
        g.createDataSet("attribute_name", ev.attribute_name);

    if (!ev.attribute_string.empty())
        g.createDataSet("attribute_string", ev.attribute_string);

    auto run_info = evt.run_info();
    if (!run_info) run_info = fallback_run_info;
    if (run_info)
        writeRunInfoToGroup(g, *run_info);
}

} // namespace

WriterHDF5::WriterHDF5(const std::string &filename)
    : WriterHDF5(filename, nullptr)
{
}

WriterHDF5::WriterHDF5(const std::string &filename, std::shared_ptr<GenRunInfo> run)
    : m_failed(false)
    , m_event_counter(0)
    , m_file(std::make_unique<HighFive::File>(filename, HighFive::File::Overwrite))
    , m_run(std::move(run))
{
}

WriterHDF5::~WriterHDF5() = default;

void WriterHDF5::write_event(const GenEvent &evt) {
    std::ostringstream os;
    os << "/event_" << std::setw(4) << std::setfill('0') << m_event_counter;
    std::string group_name = os.str();
    ++m_event_counter;
    HighFive::Group g = m_file->createGroup(group_name);
    writeEventToGroup(g, evt, m_run);
    m_failed = false;
}

bool WriterHDF5::failed() {
    return m_failed;
}

void WriterHDF5::close() {
    // No-op stub
}

} // namespace HepMC3

