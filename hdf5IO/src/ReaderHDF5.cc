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

GenRunInfo ReaderHDF5::readRunInfoFromDatasets(uint64_t index) {
    Hdf5Utils::H5RunInfo run_info;
    std::vector<Hdf5Utils::H5RunInfoIndex> records(1);
    m_run_info_index_ds->select(std::vector<size_t>{static_cast<size_t>(index)}, std::vector<size_t>{1}).read_raw(records.data(), Hdf5Utils::createRunInfoIndexType());
    const Hdf5Utils::H5RunInfoIndex &record = records[0];

    Hdf5Utils::readVector(*m_run_info_weight_names_ds, record.weight_names_offset, record.weight_names_count, run_info.weight_names);
    Hdf5Utils::readVector(*m_run_info_tool_name_ds, record.tool_offset, record.tool_count, run_info.tool_name);
    Hdf5Utils::readVector(*m_run_info_tool_version_ds, record.tool_offset, record.tool_count, run_info.tool_version);
    Hdf5Utils::readVector(*m_run_info_tool_description_ds, record.tool_offset, record.tool_count, run_info.tool_description);
    Hdf5Utils::readVector(*m_run_info_attribute_name_ds, record.attribute_offset, record.attribute_count, run_info.attribute_name);
    Hdf5Utils::readVector(*m_run_info_attribute_string_ds, record.attribute_offset, record.attribute_count, run_info.attribute_string);

    GenRunInfo result;
    GenRunInfoData rd = Hdf5Utils::fromH5(run_info);
    result.read_data(rd);
    return result;
}


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
    m_events_ds = std::make_unique<HighFive::DataSet>(ds);
    auto dims = ds.getSpace().getDimensions();
    if (!dims.empty()) {
        m_event_count = dims[0];
    }

    m_particles_ds = std::make_unique<HighFive::DataSet>(m_file->getDataSet("event_particles"));
    m_vertices_ds = std::make_unique<HighFive::DataSet>(m_file->getDataSet("event_vertices"));
    m_weights_ds = std::make_unique<HighFive::DataSet>(m_file->getDataSet("event_weights"));
    m_links1_ds = std::make_unique<HighFive::DataSet>(m_file->getDataSet("event_links1"));
    m_links2_ds = std::make_unique<HighFive::DataSet>(m_file->getDataSet("event_links2"));
    m_attribute_id_ds = std::make_unique<HighFive::DataSet>(m_file->getDataSet("event_attribute_id"));
    m_attribute_name_ds = std::make_unique<HighFive::DataSet>(m_file->getDataSet("event_attribute_name"));
    m_attribute_string_ds = std::make_unique<HighFive::DataSet>(m_file->getDataSet("event_attribute_string"));

    m_run_info_index_ds = std::make_unique<HighFive::DataSet>(m_file->getDataSet("run_infos"));
    m_run_info_weight_names_ds = std::make_unique<HighFive::DataSet>(m_file->getDataSet("run_info_weight_names"));
    m_run_info_tool_name_ds = std::make_unique<HighFive::DataSet>(m_file->getDataSet("run_info_tool_name"));
    m_run_info_tool_version_ds = std::make_unique<HighFive::DataSet>(m_file->getDataSet("run_info_tool_version"));
    m_run_info_tool_description_ds = std::make_unique<HighFive::DataSet>(m_file->getDataSet("run_info_tool_description"));
    m_run_info_attribute_name_ds = std::make_unique<HighFive::DataSet>(m_file->getDataSet("run_info_attribute_name"));
    m_run_info_attribute_string_ds = std::make_unique<HighFive::DataSet>(m_file->getDataSet("run_info_attribute_string"));
}

ReaderHDF5::~ReaderHDF5() = default;

bool ReaderHDF5::read_event(GenEvent &evt) {
    if (m_next_index >= m_event_count) {
        m_failed = true;
        return false;
    }

    std::vector<Hdf5Utils::H5EventIndex> index_record(1);
    m_events_ds->select(std::vector<size_t>{m_next_index}, std::vector<size_t>{1}).read_raw(index_record.data(), Hdf5Utils::createEventIndexType());
    const Hdf5Utils::H5EventIndex &record_index = index_record[0];

    Hdf5Utils::H5EventRecord record;
    record.event_number = record_index.event_number;
    record.momentum_unit = record_index.momentum_unit;
    record.length_unit = record_index.length_unit;
    record.event_pos = record_index.event_pos;

    Hdf5Utils::readVector(*m_particles_ds, record_index.particles_offset, record_index.particles_count, record.particles);
    Hdf5Utils::readVector(*m_vertices_ds, record_index.vertices_offset, record_index.vertices_count, record.vertices);
    Hdf5Utils::readVector(*m_weights_ds, record_index.weights_offset, record_index.weights_count, record.weights);
    Hdf5Utils::readVector(*m_links1_ds, record_index.links_offset, record_index.links_count, record.links1);
    Hdf5Utils::readVector(*m_links2_ds, record_index.links_offset, record_index.links_count, record.links2);
    Hdf5Utils::readVector(*m_attribute_id_ds, record_index.attribute_offset, record_index.attribute_count, record.attribute_id);
    Hdf5Utils::readVector(*m_attribute_name_ds, record_index.attribute_offset, record_index.attribute_count, record.attribute_name);
    Hdf5Utils::readVector(*m_attribute_string_ds, record_index.attribute_offset, record_index.attribute_count, record.attribute_string);

    GenEventData ev = Hdf5Utils::fromH5(record);
    evt.read_data(ev);

    if (record_index.run_info_index != std::numeric_limits<uint64_t>::max()) {
        GenRunInfo run = readRunInfoFromDatasets(record_index.run_info_index);
        evt.set_run_info(std::make_shared<GenRunInfo>(run));
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

