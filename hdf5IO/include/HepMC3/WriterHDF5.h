// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2023 The HepMC collaboration (see AUTHORS for details)
//
#ifndef HEPMC3_WRITERHDF5_H
#define HEPMC3_WRITERHDF5_H

#include "HepMC3/Writer.h"
#include <memory>
#include <string>

namespace HighFive {
class File;
class DataSet;
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
    uint64_t writeRunInfo(const GenRunInfo &run);

    bool m_failed = false;
    int m_event_counter = 0;
    std::unique_ptr<HighFive::File> m_file;
    std::shared_ptr<GenRunInfo> m_run;
    uint64_t m_run_info_count = 0;
    std::unique_ptr<HighFive::DataSet> m_event_index_ds;
    std::unique_ptr<HighFive::DataSet> m_particles_ds;
    std::unique_ptr<HighFive::DataSet> m_vertices_ds;
    std::unique_ptr<HighFive::DataSet> m_weights_ds;
    std::unique_ptr<HighFive::DataSet> m_links1_ds;
    std::unique_ptr<HighFive::DataSet> m_links2_ds;
    std::unique_ptr<HighFive::DataSet> m_attribute_id_ds;
    std::unique_ptr<HighFive::DataSet> m_attribute_name_ds;
    std::unique_ptr<HighFive::DataSet> m_attribute_string_ds;

    std::unique_ptr<HighFive::DataSet> m_run_info_index_ds;
    std::unique_ptr<HighFive::DataSet> m_run_info_weight_names_ds;
    std::unique_ptr<HighFive::DataSet> m_run_info_tool_name_ds;
    std::unique_ptr<HighFive::DataSet> m_run_info_tool_version_ds;
    std::unique_ptr<HighFive::DataSet> m_run_info_tool_description_ds;
    std::unique_ptr<HighFive::DataSet> m_run_info_attribute_name_ds;
    std::unique_ptr<HighFive::DataSet> m_run_info_attribute_string_ds;
    uint64_t m_particles_offset = 0;
    uint64_t m_vertices_offset = 0;
    uint64_t m_weights_offset = 0;
    uint64_t m_links_offset = 0;
    uint64_t m_attribute_offset = 0;
    uint64_t m_run_info_weight_names_offset = 0;
    uint64_t m_run_info_tool_offset = 0;
    uint64_t m_run_info_attribute_offset = 0;
};

} // namespace HepMC3

#endif
