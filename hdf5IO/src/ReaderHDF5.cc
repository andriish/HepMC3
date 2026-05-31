// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2023 The HepMC collaboration (see AUTHORS for details)
//

#include "HepMC3/ReaderHDF5.h"
#include "HepMC3/Version.h"
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

HEPMC3_DECLARE_READER_FILE(ReaderHDF5)

namespace {

using namespace HDF5Utils;


template <typename T>
void readVector(const HighFive::DataSet &ds, uint64_t offset, uint64_t count, std::vector<T> &out) {
    out.clear();
    if (count == 0) {
        return;
    }
    out.resize(count);
    ds.select(std::vector<size_t>{static_cast<size_t>(offset)}, std::vector<size_t>{static_cast<size_t>(count)}).read(out);
}

template <>
void readVector<HDF5Utils::H5EventIndex>(const HighFive::DataSet &ds, uint64_t offset, uint64_t count, std::vector<HDF5Utils::H5EventIndex> &out) {
    out.clear();
    if (count == 0) {
        return;
    }
    out.resize(count);
    ds.select(std::vector<size_t>{static_cast<size_t>(offset)}, std::vector<size_t>{static_cast<size_t>(count)}).read_raw(out.data(), createEventIndexType());
}

template <>
void readVector<HDF5Utils::H5Particle>(const HighFive::DataSet &ds, uint64_t offset, uint64_t count, std::vector<HDF5Utils::H5Particle> &out) {
    out.clear();
    if (count == 0) {
        return;
    }
    out.resize(count);
    ds.select(std::vector<size_t>{static_cast<size_t>(offset)}, std::vector<size_t>{static_cast<size_t>(count)}).read_raw(out.data(), createParticleType());
}

template <>
void readVector<HDF5Utils::H5Vertex>(const HighFive::DataSet &ds, uint64_t offset, uint64_t count, std::vector<HDF5Utils::H5Vertex> &out) {
    out.clear();
    if (count == 0) {
        return;
    }
    out.resize(count);
    ds.select(std::vector<size_t>{static_cast<size_t>(offset)}, std::vector<size_t>{static_cast<size_t>(count)}).read_raw(out.data(), createVertexType());
}


void readRunInfoFromGroup(const HighFive::Group &g, H5RunInfo &run) {
    if (!g.exist("run_info")) return;
    HighFive::Group rg = g.getGroup("run_info");

    if (rg.exist("weight_names")) rg.getDataSet("weight_names").read(run.weight_names);
    if (rg.exist("tool_name")) rg.getDataSet("tool_name").read(run.tool_name);
    if (rg.exist("tool_version")) rg.getDataSet("tool_version").read(run.tool_version);
    if (rg.exist("tool_description")) rg.getDataSet("tool_description").read(run.tool_description);
    if (rg.exist("attribute_name")) rg.getDataSet("attribute_name").read(run.attribute_name);
    if (rg.exist("attribute_string")) rg.getDataSet("attribute_string").read(run.attribute_string);
}

void readRunInfoFromGroup(const HighFive::Group &g, GenRunInfo &run) {
    if (!g.exist("run_info")) return;
    HighFive::Group rg = g.getGroup("run_info");

    H5RunInfo h5run;
    readRunInfoFromGroup(rg, h5run);

    GenRunInfoData rd = fromH5(h5run);
    run.read_data(rd);
}

void readEventFromGroup(const HighFive::Group &g, GenEvent &evt, H5RunInfo &run_info) {
    H5EventRecord record;

    g.getAttribute("event_number").read(record.event_number);

    int mu = 0, lu = 0;
    g.getAttribute("momentum_unit").read(mu);
    g.getAttribute("length_unit").read(lu);
    record.momentum_unit = mu;
    record.length_unit = lu;

    {
        auto ds = g.getDataSet("event_pos");
        ds.read_raw(&record.event_pos, createFourVectorType());
    }

    {
        auto ds = g.getDataSet("particles");
        const std::vector<size_t> dims = ds.getSpace().getDimensions();
        record.particles.clear();
        if (!dims.empty()) {
            record.particles.resize(dims[0]);
            ds.read_raw(record.particles.data(), createParticleType());
        }
    }

    {
        auto ds = g.getDataSet("vertices");
        const std::vector<size_t> dims = ds.getSpace().getDimensions();
        record.vertices.clear();
        if (!dims.empty()) {
            record.vertices.resize(dims[0]);
            ds.read_raw(record.vertices.data(), createVertexType());
        }
    }

    if (g.exist("weights"))
        g.getDataSet("weights").read(record.weights);

    if (g.exist("links1"))
        g.getDataSet("links1").read(record.links1);

    if (g.exist("links2"))
        g.getDataSet("links2").read(record.links2);

    if (g.exist("attribute_id"))
        g.getDataSet("attribute_id").read(record.attribute_id);

    if (g.exist("attribute_name"))
        g.getDataSet("attribute_name").read(record.attribute_name);

    if (g.exist("attribute_string"))
        g.getDataSet("attribute_string").read(record.attribute_string);

    readRunInfoFromGroup(g, run_info);

    GenEventData ev = fromH5(record);
    evt.read_data(ev);
}

void readEventFromDatasets(const HighFive::File &file, std::size_t index, GenEvent &evt, const std::shared_ptr<GenRunInfo> &global_run_info, bool has_global_run_info) {
    auto events = file.getDataSet("events");
    std::vector<H5EventIndex> index_record(1);
    events.select(std::vector<size_t>{index}, std::vector<size_t>{1}).read_raw(index_record.data(), createEventIndexType());
    const H5EventIndex &record_index = index_record[0];

    H5EventRecord record;
    record.event_number = record_index.event_number;
    record.momentum_unit = record_index.momentum_unit;
    record.length_unit = record_index.length_unit;
    record.event_pos = record_index.event_pos;

    auto particles_ds = file.getDataSet("particles");
    readVector(particles_ds, record_index.particles_offset, record_index.particles_count, record.particles);

    auto vertices_ds = file.getDataSet("vertices");
    readVector(vertices_ds, record_index.vertices_offset, record_index.vertices_count, record.vertices);

    auto weights_ds = file.getDataSet("weights");
    readVector(weights_ds, record_index.weights_offset, record_index.weights_count, record.weights);

    auto links1_ds = file.getDataSet("links1");
    readVector(links1_ds, record_index.links1_offset, record_index.links1_count, record.links1);

    auto links2_ds = file.getDataSet("links2");
    readVector(links2_ds, record_index.links2_offset, record_index.links2_count, record.links2);

    auto attribute_id_ds = file.getDataSet("attribute_id");
    readVector(attribute_id_ds, record_index.attribute_id_offset, record_index.attribute_id_count, record.attribute_id);

    auto attribute_name_ds = file.getDataSet("attribute_name");
    readVector(attribute_name_ds, record_index.attribute_name_offset, record_index.attribute_name_count, record.attribute_name);

    auto attribute_string_ds = file.getDataSet("attribute_string");
    readVector(attribute_string_ds, record_index.attribute_string_offset, record_index.attribute_string_count, record.attribute_string);

    if (has_global_run_info && global_run_info) {
        GenRunInfoData rd;
        global_run_info->write_data(rd);
        record.run_info = toH5(rd);
    }

    GenEventData ev = fromH5(record);
    evt.read_data(ev);
}

} // namespace

ReaderHDF5::ReaderHDF5(const std::string &filename)
    : m_failed(false)
    , m_file(std::make_unique<HighFive::File>(filename, HighFive::File::ReadOnly))
    , m_next_index(0)
    , m_event_count(0)
    , m_has_global_run_info(false)
{
    if (!m_file->exist("events")) {
        m_failed = true;
        return;
    }

    auto ds = m_file->getDataSet("events");
    auto dims = ds.getSpace().getDimensions();
    if (!dims.empty()) {
        m_event_count = dims[0];
    }
    if (m_file->exist("run_info")) {
        m_run_info = std::make_shared<GenRunInfo>();
        HighFive::Group rg = m_file->getGroup("run_info");
        readRunInfoFromGroup(rg, *m_run_info);
        m_has_global_run_info = true;
    }
}

ReaderHDF5::~ReaderHDF5() = default;

bool ReaderHDF5::read_event(GenEvent &evt) {
    if (m_next_index >= m_event_count) {
        m_failed = true;
        return false;
    }

    readEventFromDatasets(*m_file, m_next_index, evt, m_run_info, m_has_global_run_info);
    if (m_has_global_run_info && m_run_info) {
        evt.set_run_info(m_run_info);
    }
    ++m_next_index;
    m_failed = false;
    return true;
}

bool ReaderHDF5::skip(const int n) {
    if (n < 0) {
        return false;
    }
    if (m_next_index >= m_event_count) {
        m_failed = true;
        return false;
    }

    std::size_t remaining = m_event_count - m_next_index;
    if (static_cast<std::size_t>(n) > remaining) {
        m_next_index = m_event_count;
        return false;
    }

    m_next_index += static_cast<std::size_t>(n);
    return true;
}

bool ReaderHDF5::failed() {
    return m_failed;
}

void ReaderHDF5::close() {
    // No-op stub
}

} // namespace HepMC3

