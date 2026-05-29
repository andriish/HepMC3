// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2023 The HepMC collaboration (see AUTHORS for details)
//

#include "HepMC3/ReaderHDF5.h"
#include "HepMC3/GenEvent.h"
#include "HepMC3/GenRunInfo.h"
#include "HepMC3/Data/GenEventData.h"
#include "HepMC3/Data/GenRunInfoData.h"
#include "HepMC3/hdf5Utils.h"

#include <highfive/H5File.hpp>
#include <memory>
#include <string>
#include <vector>

namespace HepMC3 {

namespace {

using namespace HDF5Utils;

bool is_event_group_name(const std::string &name) {
    return name.rfind("event_", 0) == 0;
}

std::string choose_event_group(const HighFive::File &file) {
    for (const auto &name : file.listObjectNames()) {
        if (is_event_group_name(name)) {
            return name;
        }
    }
    return std::string();
}

void readRunInfoFromGroup(const HighFive::Group &g, GenRunInfo &run) {
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

void readEventFromGroup(const HighFive::Group &g, GenEvent &evt) {
    GenEventData ev;

    g.getAttribute("event_number").read(ev.event_number);

    int mu = 0, lu = 0;
    g.getAttribute("momentum_unit").read(mu);
    g.getAttribute("length_unit").read(lu);
    ev.momentum_unit = static_cast<Units::MomentumUnit>(mu);
    ev.length_unit = static_cast<Units::LengthUnit>(lu);

    {
        H5FourVector pos;
        auto ds = g.getDataSet("event_pos");
        ds.read_raw(&pos, createFourVectorType());
        ev.event_pos = fromH5(pos);
    }

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
        for (const auto &p : pvec) {
            ev.particles.push_back(fromH5(p));
        }
    }

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
        for (const auto &v : vvec) {
            ev.vertices.push_back(fromH5(v));
        }
    }

    if (g.exist("weights"))
        g.getDataSet("weights").read(ev.weights);

    if (g.exist("links1"))
        g.getDataSet("links1").read(ev.links1);

    if (g.exist("links2"))
        g.getDataSet("links2").read(ev.links2);

    if (g.exist("attribute_id"))
        g.getDataSet("attribute_id").read(ev.attribute_id);

    if (g.exist("attribute_name"))
        g.getDataSet("attribute_name").read(ev.attribute_name);

    if (g.exist("attribute_string"))
        g.getDataSet("attribute_string").read(ev.attribute_string);

    evt.read_data(ev);
}

} // namespace

ReaderHDF5::ReaderHDF5(const std::string &filename)
    : m_failed(false)
    , m_file(filename, HighFive::File::ReadOnly)
{
}

ReaderHDF5::~ReaderHDF5() = default;

bool ReaderHDF5::read_event(GenEvent &evt) {
    std::string group_name = choose_event_group(m_file);
    if (group_name.empty()) {
        m_failed = true;
        return false;
    }

    HighFive::Group g = m_file.getGroup(group_name);
    readEventFromGroup(g, evt);

    auto run_info = std::make_shared<GenRunInfo>();
    readRunInfoFromGroup(g, *run_info);
    evt.set_run_info(run_info);

    m_failed = false;
    return true;
}

bool ReaderHDF5::failed() {
    return m_failed;
}

void ReaderHDF5::close() {
    // No-op stub
}

} // namespace HepMC3
