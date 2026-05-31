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

namespace HepMC3 {
HEPMC3_DECLARE_WRITER_FILE(WriterHDF5)

namespace {

using namespace HDF5Utils;

template <typename T>
void appendVector(HighFive::DataSet &dataset, const std::vector<T> &data) {
    std::vector<size_t> current_dims = dataset.getDimensions();
    std::size_t offset = current_dims.empty() ? 0 : current_dims[0];
    std::vector<size_t> new_dims{offset + data.size()};
    dataset.resize(new_dims);
    if (!data.empty()) {
        dataset.select(std::vector<size_t>{offset}, std::vector<size_t>{data.size()}).write(data);
    }
}

template <typename T>
void appendVector(HighFive::DataSet &dataset, const std::vector<T> &data, const HighFive::DataType &dtype) {
    std::vector<size_t> current_dims = dataset.getDimensions();
    std::size_t offset = current_dims.empty() ? 0 : current_dims[0];
    std::vector<size_t> new_dims{offset + data.size()};
    dataset.resize(new_dims);
    if (data.empty()) {
        return;
    }
    dataset.select(std::vector<size_t>{offset}, std::vector<size_t>{data.size()}).write_raw(data.data(), dtype);
}

void appendRaw(HighFive::DataSet &dataset, const void *data, uint64_t count, const HighFive::DataType &dtype) {
    std::vector<size_t> current_dims = dataset.getDimensions();
    uint64_t offset = current_dims.empty() ? 0 : current_dims[0];
    std::vector<size_t> new_dims{offset + count};
    dataset.resize(new_dims);
    if (count == 0) {
        return;
    }
    dataset.select(std::vector<size_t>{offset}, std::vector<size_t>{static_cast<size_t>(count)}).write_raw(data, dtype);
}

} // namespace

void WriterHDF5::initializeDatasets() {
    if (m_initialized) {
        return;
    }

    HighFive::DataSpace scalar_space(std::vector<size_t>{0}, std::vector<size_t>{HighFive::DataSpace::UNLIMITED});
    HighFive::DataSetCreateProps props;
    props.add(HighFive::Chunking(std::vector<hsize_t>{1024}));

    m_event_index_ds = std::make_unique<HighFive::DataSet>(m_file->createDataSet("events", scalar_space, HDF5Utils::createEventIndexType(), props));
    m_particles_ds = std::make_unique<HighFive::DataSet>(m_file->createDataSet("particles", scalar_space, createParticleType(), props));
    m_vertices_ds = std::make_unique<HighFive::DataSet>(m_file->createDataSet("vertices", scalar_space, createVertexType(), props));
    m_weights_ds = std::make_unique<HighFive::DataSet>(m_file->createDataSet<double>("weights", scalar_space, props));
    m_links1_ds = std::make_unique<HighFive::DataSet>(m_file->createDataSet<int>("links1", scalar_space, props));
    m_links2_ds = std::make_unique<HighFive::DataSet>(m_file->createDataSet<int>("links2", scalar_space, props));
    m_attribute_id_ds = std::make_unique<HighFive::DataSet>(m_file->createDataSet<int>("attribute_id", scalar_space, props));
    m_attribute_name_ds = std::make_unique<HighFive::DataSet>(m_file->createDataSet<std::string>("attribute_name", scalar_space, props));
    m_attribute_string_ds = std::make_unique<HighFive::DataSet>(m_file->createDataSet<std::string>("attribute_string", scalar_space, props));

    m_initialized = true;
}

void WriterHDF5::writeRunInfoToRoot(const GenRunInfo &run) {
    if (m_file->exist("run_info")) {
        m_run_info_written = true;
        return;
    }

    GenRunInfoData rd;
    run.write_data(rd);
    HDF5Utils::H5RunInfo run_info = HDF5Utils::toH5(rd);

    HighFive::Group rg = m_file->createGroup("run_info");

    if (!run_info.weight_names.empty())
        rg.createDataSet("weight_names", run_info.weight_names);

    if (!run_info.tool_name.empty())
        rg.createDataSet("tool_name", run_info.tool_name);

    if (!run_info.tool_version.empty())
        rg.createDataSet("tool_version", run_info.tool_version);

    if (!run_info.tool_description.empty())
        rg.createDataSet("tool_description", run_info.tool_description);

    if (!run_info.attribute_name.empty())
        rg.createDataSet("attribute_name", run_info.attribute_name);

    if (!run_info.attribute_string.empty())
        rg.createDataSet("attribute_string", run_info.attribute_string);

    m_run_info_written = true;
}

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
    initializeDatasets();

    GenEventData ev;
    evt.write_data(ev);

    
    auto rr = evt.run_info();
    if (!rr) rr = m_run;

    HDF5Utils::H5RunInfo run_info;
    if (rr) {
        GenRunInfoData rd;
        rr->write_data(rd);
        run_info = HDF5Utils::toH5(rd);
        if (!m_run_info_written) {
            writeRunInfoToRoot(*rr);
        }
    }

    HDF5Utils::H5EventRecord record = HDF5Utils::toH5(ev, run_info);
    HepMC3::HDF5Utils::H5EventIndex index;
    index.event_number = record.event_number;
    index.momentum_unit = record.momentum_unit;
    index.length_unit = record.length_unit;
    index.event_pos = record.event_pos;
    index.particles_offset = m_particles_offset;
    index.particles_count = record.particles.size();
    index.vertices_offset = m_vertices_offset;
    index.vertices_count = record.vertices.size();
    index.weights_offset = m_weights_offset;
    index.weights_count = record.weights.size();
    index.links1_offset = m_links1_offset;
    index.links1_count = record.links1.size();
    index.links2_offset = m_links2_offset;
    index.links2_count = record.links2.size();
    index.attribute_id_offset = m_attribute_id_offset;
    index.attribute_id_count = record.attribute_id.size();
    index.attribute_name_offset = m_attribute_name_offset;
    index.attribute_name_count = record.attribute_name.size();
    index.attribute_string_offset = m_attribute_string_offset;
    index.attribute_string_count = record.attribute_string.size();

    appendRaw(*m_event_index_ds, &index, 1, createEventIndexType());
    auto particle_type = createParticleType();
    appendVector(*m_particles_ds, record.particles, particle_type);
    auto vertex_type = createVertexType();
    appendVector(*m_vertices_ds, record.vertices, vertex_type);
    appendVector(*m_weights_ds, record.weights);
    appendVector(*m_links1_ds, record.links1);
    appendVector(*m_links2_ds, record.links2);
    appendVector(*m_attribute_id_ds, record.attribute_id);
    appendVector(*m_attribute_name_ds, record.attribute_name);
    appendVector(*m_attribute_string_ds, record.attribute_string);

    m_particles_offset += record.particles.size();
    m_vertices_offset += record.vertices.size();
    m_weights_offset += record.weights.size();
    m_links1_offset += record.links1.size();
    m_links2_offset += record.links2.size();
    m_attribute_id_offset += record.attribute_id.size();
    m_attribute_name_offset += record.attribute_name.size();
    m_attribute_string_offset += record.attribute_string.size();

    ++m_event_counter;
    m_failed = false;
}

bool WriterHDF5::failed() {
    return m_failed;
}

void WriterHDF5::close() {
    // No-op stub
}

} // namespace HepMC3

