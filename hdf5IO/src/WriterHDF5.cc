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
#include <limits>
#include <sstream>

namespace HepMC3 {
HEPMC3_DECLARE_WRITER_FILE(WriterHDF5)

uint64_t WriterHDF5::writeRunInfo(const GenRunInfo &run) {
    GenRunInfoData rd;
    run.write_data(rd);
    Hdf5Utils::H5RunInfo run_info = Hdf5Utils::toH5(rd);

    Hdf5Utils::H5RunInfoIndex index;
    index.weight_names_offset = m_run_info_weight_names_offset;
    index.weight_names_count = run_info.weight_names.size();
    index.tool_offset = m_run_info_tool_offset;
    index.tool_count = run_info.tool_name.size();
    index.attribute_offset = m_run_info_attribute_offset;
    index.attribute_count = run_info.attribute_name.size();

    Hdf5Utils::appendRaw(*m_run_info_index_ds, &index, 1, Hdf5Utils::createRunInfoIndexType());
    Hdf5Utils::appendVector(*m_run_info_weight_names_ds, run_info.weight_names);
    Hdf5Utils::appendVector(*m_run_info_tool_name_ds, run_info.tool_name);
    Hdf5Utils::appendVector(*m_run_info_tool_version_ds, run_info.tool_version);
    Hdf5Utils::appendVector(*m_run_info_tool_description_ds, run_info.tool_description);
    Hdf5Utils::appendVector(*m_run_info_attribute_name_ds, run_info.attribute_name);
    Hdf5Utils::appendVector(*m_run_info_attribute_string_ds, run_info.attribute_string);

    m_run_info_weight_names_offset += run_info.weight_names.size();
    m_run_info_tool_offset += run_info.tool_name.size();
    m_run_info_attribute_offset += run_info.attribute_name.size();

    return m_run_info_count++;
}

WriterHDF5::WriterHDF5(const std::string &filename)
    : WriterHDF5(filename, nullptr)
{
}

WriterHDF5::WriterHDF5(const std::string &filename, std::shared_ptr<GenRunInfo> run)
    : WriterHDF5(filename, std::move(run), 1024)
{
}

WriterHDF5::WriterHDF5(const std::string &filename, std::shared_ptr<GenRunInfo> run, uint64_t chunking_size)
    : m_failed(false)
    , m_event_counter(0)
    , m_file(std::make_unique<HighFive::File>(filename, HighFive::File::Overwrite))
    , m_run(std::move(run))
    , m_chunking_size(chunking_size)
{
    HighFive::DataSpace scalar_space(std::vector<size_t>{0}, std::vector<size_t>{HighFive::DataSpace::UNLIMITED});
    HighFive::DataSetCreateProps props;
    props.add(HighFive::Chunking(std::vector<hsize_t>{static_cast<hsize_t>(m_chunking_size)}));

    auto scheme_version_ds = m_file->createDataSet<uint32_t>("HepMC3HDF5SchemeVersion", HighFive::DataSpace::Scalar());
    scheme_version_ds.write(m_scheme_version);

    m_event_index_ds = std::make_unique<HighFive::DataSet>(m_file->createDataSet("events", scalar_space, Hdf5Utils::createEventIndexType(), props));

    m_particles_ds = std::make_unique<HighFive::DataSet>(m_file->createDataSet("event_particles", scalar_space, Hdf5Utils::createParticleType(), props));
    m_vertices_ds = std::make_unique<HighFive::DataSet>(m_file->createDataSet("event_vertices", scalar_space, Hdf5Utils::createVertexType(), props));
    m_weights_ds = std::make_unique<HighFive::DataSet>(m_file->createDataSet<double>("event_weights", scalar_space, props));
    m_links1_ds = std::make_unique<HighFive::DataSet>(m_file->createDataSet<int>("event_links1", scalar_space, props));
    m_links2_ds = std::make_unique<HighFive::DataSet>(m_file->createDataSet<int>("event_links2", scalar_space, props));
    m_attribute_id_ds = std::make_unique<HighFive::DataSet>(m_file->createDataSet<int>("event_attribute_id", scalar_space, props));
    m_attribute_name_ds = std::make_unique<HighFive::DataSet>(m_file->createDataSet<std::string>("event_attribute_name", scalar_space, props));
    m_attribute_string_ds = std::make_unique<HighFive::DataSet>(m_file->createDataSet<std::string>("event_attribute_string", scalar_space, props));

    m_run_info_index_ds = std::make_unique<HighFive::DataSet>(m_file->createDataSet("run_infos", scalar_space, Hdf5Utils::createRunInfoIndexType(), props));
    m_run_info_weight_names_ds = std::make_unique<HighFive::DataSet>(m_file->createDataSet<std::string>("run_info_weight_names", scalar_space, props));
    m_run_info_tool_name_ds = std::make_unique<HighFive::DataSet>(m_file->createDataSet<std::string>("run_info_tool_name", scalar_space, props));
    m_run_info_tool_version_ds = std::make_unique<HighFive::DataSet>(m_file->createDataSet<std::string>("run_info_tool_version", scalar_space, props));
    m_run_info_tool_description_ds = std::make_unique<HighFive::DataSet>(m_file->createDataSet<std::string>("run_info_tool_description", scalar_space, props));
    m_run_info_attribute_name_ds = std::make_unique<HighFive::DataSet>(m_file->createDataSet<std::string>("run_info_attribute_name", scalar_space, props));
    m_run_info_attribute_string_ds = std::make_unique<HighFive::DataSet>(m_file->createDataSet<std::string>("run_info_attribute_string", scalar_space, props));
}

WriterHDF5::~WriterHDF5() = default;

void WriterHDF5::write_event(const GenEvent &evt) {
    GenEventData ev;
    evt.write_data(ev);

    
    auto rr = evt.run_info();
    if (!rr) rr = m_run;

    uint64_t run_info_index = std::numeric_limits<uint64_t>::max();
    if (rr) {
        if (!m_run || rr != m_run) {
            m_run = rr;
            writeRunInfo(*m_run);
        } else if (m_run_info_count == 0) {
            writeRunInfo(*m_run);
        }
        run_info_index = m_run_info_count - 1;
    }

    Hdf5Utils::H5EventRecord record = Hdf5Utils::toH5(ev);
    HepMC3::Hdf5Utils::H5EventIndex index;
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
    index.links_offset = m_links_offset;
    index.links_count = record.links1.size();
    index.attribute_offset = m_attribute_offset;
    index.attribute_count = record.attribute_id.size();
    index.run_info_index = run_info_index;

    Hdf5Utils::appendRaw(*m_event_index_ds, &index, 1, Hdf5Utils::createEventIndexType());
    auto particle_type = Hdf5Utils::createParticleType();
    Hdf5Utils::appendVector(*m_particles_ds, record.particles, particle_type);
    auto vertex_type = Hdf5Utils::createVertexType();
    Hdf5Utils::appendVector(*m_vertices_ds, record.vertices, vertex_type);
    Hdf5Utils::appendVector(*m_weights_ds, record.weights);
    Hdf5Utils::appendVector(*m_links1_ds, record.links1);
    Hdf5Utils::appendVector(*m_links2_ds, record.links2);
    Hdf5Utils::appendVector(*m_attribute_id_ds, record.attribute_id);
    Hdf5Utils::appendVector(*m_attribute_name_ds, record.attribute_name);
    Hdf5Utils::appendVector(*m_attribute_string_ds, record.attribute_string);

    m_particles_offset += record.particles.size();
    m_vertices_offset += record.vertices.size();
    m_weights_offset += record.weights.size();
    m_links_offset += record.links1.size();
    m_attribute_offset += record.attribute_id.size();

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

