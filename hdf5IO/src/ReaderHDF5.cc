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
#include <iomanip>
#include <limits>
#include <memory>
#include <sstream>
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

void readRunInfoFromDatasets(const HighFive::File &file, uint64_t index, H5RunInfo &run) {
    auto run_info_index_ds = file.getDataSet("run_infos");
    std::vector<H5RunInfoIndex> records(1);
    run_info_index_ds.select(std::vector<size_t>{static_cast<size_t>(index)}, std::vector<size_t>{1}).read_raw(records.data(), createRunInfoIndexType());
    const H5RunInfoIndex &record = records[0];

    readVector(file.getDataSet("run_info_weight_names"), record.weight_names_offset, record.weight_names_count, run.weight_names);
    readVector(file.getDataSet("run_info_tool_name"), record.tool_offset, record.tool_count, run.tool_name);
    readVector(file.getDataSet("run_info_tool_version"), record.tool_offset, record.tool_count, run.tool_version);
    readVector(file.getDataSet("run_info_tool_description"), record.tool_offset, record.tool_count, run.tool_description);
    readVector(file.getDataSet("run_info_attribute_name"), record.attribute_offset, record.attribute_count, run.attribute_name);
    readVector(file.getDataSet("run_info_attribute_string"), record.attribute_offset, record.attribute_count, run.attribute_string);
}


void readEventFromDatasets(const HighFive::File &file, std::size_t index, GenEvent &evt) {
    auto events = file.getDataSet("events");
    std::vector<H5EventIndex> index_record(1);
    events.select(std::vector<size_t>{index}, std::vector<size_t>{1}).read_raw(index_record.data(), createEventIndexType());
    const H5EventIndex &record_index = index_record[0];

    H5EventRecord record;
    H5RunInfo run_info;
    record.event_number = record_index.event_number;
    record.momentum_unit = record_index.momentum_unit;
    record.length_unit = record_index.length_unit;
    record.event_pos = record_index.event_pos;

    auto particles_ds = file.getDataSet("event_particles");
    readVector(particles_ds, record_index.particles_offset, record_index.particles_count, record.particles);

    auto vertices_ds = file.getDataSet("event_vertices");
    readVector(vertices_ds, record_index.vertices_offset, record_index.vertices_count, record.vertices);

    auto weights_ds = file.getDataSet("event_weights");
    readVector(weights_ds, record_index.weights_offset, record_index.weights_count, record.weights);

    auto links1_ds = file.getDataSet("event_links1");
    readVector(links1_ds, record_index.links_offset, record_index.links_count, record.links1);

    auto links2_ds = file.getDataSet("event_links2");
    readVector(links2_ds, record_index.links_offset, record_index.links_count, record.links2);

    auto attribute_id_ds = file.getDataSet("event_attribute_id");
    readVector(attribute_id_ds, record_index.attribute_offset, record_index.attribute_count, record.attribute_id);

    auto attribute_name_ds = file.getDataSet("event_attribute_name");
    readVector(attribute_name_ds, record_index.attribute_offset, record_index.attribute_count, record.attribute_name);

    auto attribute_string_ds = file.getDataSet("event_attribute_string");
    readVector(attribute_string_ds, record_index.attribute_offset, record_index.attribute_count, record.attribute_string);

    if (record_index.run_info_index != std::numeric_limits<uint64_t>::max()) {
        readRunInfoFromDatasets(file, record_index.run_info_index, run_info);
    }

    GenEventData ev = fromH5(record);
    evt.read_data(ev);

    if (!run_info.weight_names.empty() ||
        !run_info.tool_name.empty() ||
        !run_info.tool_version.empty() ||
        !run_info.tool_description.empty() ||
        !run_info.attribute_name.empty() ||
        !run_info.attribute_string.empty()) {
        auto run = std::make_shared<GenRunInfo>();
        GenRunInfoData rd = fromH5(run_info);
        run->read_data(rd);
        evt.set_run_info(run);
    }
}

} // namespace

ReaderHDF5::ReaderHDF5(const std::string &filename)
    : m_failed(false)
    , m_file(std::make_unique<HighFive::File>(filename, HighFive::File::ReadOnly))
    , m_next_index(0)
    , m_event_count(0)
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
}

ReaderHDF5::~ReaderHDF5() = default;

bool ReaderHDF5::read_event(GenEvent &evt) {
    if (m_next_index >= m_event_count) {
        m_failed = true;
        return false;
    }
    readEventFromDatasets(*m_file, m_next_index, evt);
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

