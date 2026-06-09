// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2023 The HepMC collaboration (see AUTHORS for details)
//
#ifndef HEPMC3_READERHDF5_H
#define HEPMC3_READERHDF5_H

#include "HepMC3/Reader.h"
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace HighFive {
class File;
class DataSet;
}

namespace HepMC3 {

class GenRunInfo;

class ReaderHDF5 : public Reader {
public:
    ReaderHDF5(const std::string &filename);
    ~ReaderHDF5() override;

    bool read_event(GenEvent &evt) override;
    bool skip(const int n) override;
    bool failed() override;
    void close() override;

private:
    GenRunInfo readRunInfoFromDatasets(uint64_t index);

    bool m_failed = false;
    std::unique_ptr<HighFive::File> m_file;
    std::unique_ptr<HighFive::DataSet> m_events_ds;
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
    std::size_t m_next_index = 0;
    std::size_t m_event_count = 0;
    uint32_t m_scheme_version = 0;
};

} // namespace HepMC3

#endif
