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

/** @brief Reads native HepMC3 HDF5 files. */
class ReaderHDF5 : public Reader {
public:
    /** @brief Open a native HepMC3 HDF5 file. */
    ReaderHDF5(const std::string &filename);
    /** @brief Close the HDF5 reader. */
    ~ReaderHDF5() override;

    /** @brief Read the next event. */
    bool read_event(GenEvent &evt) override;
    /** @brief Skip input events. */
    bool skip(const int n) override;
    /** @brief Return reader failure state. */
    bool failed() override;
    /** @brief Release HDF5 resources. */
    void close() override;

private:
    /** @brief Read run information at the given dataset index. */
    GenRunInfo readRunInfoFromDatasets(uint64_t index);

    /** @brief Reader failure state. */
    bool m_failed = false;
    /** @brief Open HDF5 file. */
    std::unique_ptr<HighFive::File> m_file;
    /** @brief Event index dataset. */
    std::unique_ptr<HighFive::DataSet> m_events_ds;
    /** @brief Particle dataset. */
    std::unique_ptr<HighFive::DataSet> m_particles_ds;
    /** @brief Vertex dataset. */
    std::unique_ptr<HighFive::DataSet> m_vertices_ds;
    /** @brief Weight dataset. */
    std::unique_ptr<HighFive::DataSet> m_weights_ds;
    /** @brief First link-index dataset. */
    std::unique_ptr<HighFive::DataSet> m_links1_ds;
    /** @brief Second link-index dataset. */
    std::unique_ptr<HighFive::DataSet> m_links2_ds;
    /** @brief Attribute identifier dataset. */
    std::unique_ptr<HighFive::DataSet> m_attribute_id_ds;
    /** @brief Attribute name dataset. */
    std::unique_ptr<HighFive::DataSet> m_attribute_name_ds;
    /** @brief Attribute value dataset. */
    std::unique_ptr<HighFive::DataSet> m_attribute_string_ds;
    /** @brief Run information index dataset. */
    std::unique_ptr<HighFive::DataSet> m_run_info_index_ds;
    /** @brief Run weight-name dataset. */
    std::unique_ptr<HighFive::DataSet> m_run_info_weight_names_ds;
    /** @brief Run tool-name dataset. */
    std::unique_ptr<HighFive::DataSet> m_run_info_tool_name_ds;
    /** @brief Run tool-version dataset. */
    std::unique_ptr<HighFive::DataSet> m_run_info_tool_version_ds;
    /** @brief Run tool-description dataset. */
    std::unique_ptr<HighFive::DataSet> m_run_info_tool_description_ds;
    /** @brief Run attribute-name dataset. */
    std::unique_ptr<HighFive::DataSet> m_run_info_attribute_name_ds;
    /** @brief Run attribute-value dataset. */
    std::unique_ptr<HighFive::DataSet> m_run_info_attribute_string_ds;
    /** @brief Index of the next event. */
    std::size_t m_next_index = 0;
    /** @brief Total number of events. */
    std::size_t m_event_count = 0;
    /** @brief Native HDF5 format version. */
    uint32_t m_scheme_version = 0;
};

} // namespace HepMC3

#endif
