// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2023 The HepMC collaboration (see AUTHORS for details)
//
#ifndef HEPMC3_WRITERHDF5_H
#define HEPMC3_WRITERHDF5_H

#include "HepMC3/Writer.h"
#include "HepMC3/hdf5Utils.h"
#include <memory>
#include <string>

namespace HighFive {
class File;
}

namespace HepMC3 {

class GenRunInfo;

class WriterHDF5 : public Writer {
public:
    WriterHDF5(const std::string &filename);
    WriterHDF5(const std::string &filename, std::shared_ptr<GenRunInfo> run);
    ~WriterHDF5() override;

    void write_event(const GenEvent &evt) override;
    bool failed() override;
    void close() override;

private:
    void initializeDatasets();
    void writeRunInfoToRoot(const HDF5Utils::H5RunInfo &run_info);

    bool m_failed = false;
    int m_event_counter = 0;
    bool m_initialized = false;
    bool m_run_info_written = false;
    std::unique_ptr<HighFive::File> m_file;
    std::shared_ptr<GenRunInfo> m_run;
    HighFive::DataSet m_event_index_ds;
    HighFive::DataSet m_particles_ds;
    HighFive::DataSet m_vertices_ds;
    HighFive::DataSet m_weights_ds;
    HighFive::DataSet m_links1_ds;
    HighFive::DataSet m_links2_ds;
    HighFive::DataSet m_attribute_id_ds;
    HighFive::DataSet m_attribute_name_ds;
    HighFive::DataSet m_attribute_string_ds;
    uint64_t m_particles_offset = 0;
    uint64_t m_vertices_offset = 0;
    uint64_t m_weights_offset = 0;
    uint64_t m_links1_offset = 0;
    uint64_t m_links2_offset = 0;
    uint64_t m_attribute_id_offset = 0;
    uint64_t m_attribute_name_offset = 0;
    uint64_t m_attribute_string_offset = 0;
};

} // namespace HepMC3

#endif
