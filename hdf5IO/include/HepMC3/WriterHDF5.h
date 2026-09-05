// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2023 The HepMC collaboration (see AUTHORS for details)
//
#ifndef HEPMC3_WRITERHDF5_H
#define HEPMC3_WRITERHDF5_H

#include "HepMC3/Writer.h"
#include <cstdint>
#include <memory>
#include <string>

namespace HighFive {
class File;
class DataSet;
}

namespace HepMC3 {

class GenRunInfo;

/** @brief Writes native HepMC3 HDF5 files. */
class WriterHDF5 : public Writer {
public:
    /** @brief Create a writer for a file. */
    WriterHDF5(const std::string &filename);
    /** @brief Create a writer with run information. */
    WriterHDF5(const std::string &filename, std::shared_ptr<GenRunInfo> run);
    /** @brief Create a writer with run information and chunk size. */
    WriterHDF5(const std::string &filename, std::shared_ptr<GenRunInfo> run, uint64_t chunking_size);
    /** @brief Close the writer. */
    ~WriterHDF5() override;

    /** @brief Write an event. */
    void write_event(const GenEvent &evt) override;
    /** @brief Return writer failure state. */
    bool failed() override;
    /** @brief Release HDF5 resources. */
    void close() override;

private:
    /** @brief Write run information and return its index. */
    uint64_t writeRunInfo(const GenRunInfo &run);

    /** @brief Writer failure state. */
    bool m_failed = false;
    /** @brief Number assigned to the next event. */
    int m_event_counter = 0;
    /** @brief Open output file. */
    std::unique_ptr<HighFive::File> m_file;
    /** @brief Current run information. */
    std::shared_ptr<GenRunInfo> m_run;
    /** @brief Number of stored run information records. */
    uint64_t m_run_info_count = 0;
    /** @brief Event index dataset. */
    std::unique_ptr<HighFive::DataSet> m_event_index_ds;
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
    /** @brief Current particle dataset offset. */
    uint64_t m_particles_offset = 0;
    /** @brief Current vertex dataset offset. */
    uint64_t m_vertices_offset = 0;
    /** @brief Current weight dataset offset. */
    uint64_t m_weights_offset = 0;
    /** @brief Current link dataset offset. */
    uint64_t m_links_offset = 0;
    /** @brief Current attribute dataset offset. */
    uint64_t m_attribute_offset = 0;
    /** @brief Current run weight-name dataset offset. */
    uint64_t m_run_info_weight_names_offset = 0;
    /** @brief Current run tool dataset offset. */
    uint64_t m_run_info_tool_offset = 0;
    /** @brief Current run attribute dataset offset. */
    uint64_t m_run_info_attribute_offset = 0;
    /** @brief Native HDF5 format version. */
    uint32_t m_scheme_version = 1;
    /** @brief Number of records in each HDF5 chunk. */
    uint64_t m_chunking_size = 1024;
};

} // namespace HepMC3

#endif
