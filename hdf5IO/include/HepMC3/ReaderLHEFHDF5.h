// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2026 The HepMC collaboration (see AUTHORS for details)
//
#ifndef HEPMC3_READERLHEFHDF5_H
#define HEPMC3_READERLHEFHDF5_H

#include "HepMC3/Reader.h"
#include "HepMC3/LHEFHDF5.h"

#include <memory>
#include <string>

namespace HepMC3 {

/**
 * @brief Reads LHEF-HDF5 events and converts them to GenEvent objects.
 */
class ReaderLHEFHDF5 : public Reader {
public:
    /** @brief Open an LHEF-HDF5 file. */
    explicit ReaderLHEFHDF5(const std::string &filename);
    /** @brief Close the LHEF-HDF5 reader. */
    ~ReaderLHEFHDF5() override;

    /** @brief Read and convert the next event. */
    bool read_event(GenEvent &event) override;
    /** @brief Skip the requested number of input events. */
    bool skip(const int n) override;
    /** @brief Return whether reading has failed or reached end of file. */
    bool failed() override;
    /** @brief Release the input file resources. */
    void close() override;

private:
    /** @brief Initialize run information from the LHEF header. */
    void init();

    /** @brief Underlying LHEF-HDF5 reader. */
    std::unique_ptr<LHEFHDF5::Reader> m_reader;
    /** @brief Number assigned to the next output event. */
    int m_neve = 0;
};

} // namespace HepMC3

#endif