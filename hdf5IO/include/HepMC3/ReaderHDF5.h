// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2023 The HepMC collaboration (see AUTHORS for details)
//
#ifndef HEPMC3_READERHDF5_H
#define HEPMC3_READERHDF5_H

#include "HepMC3/Reader.h"
#include <highfive/H5File.hpp>
#include <string>

namespace HepMC3 {

class ReaderHDF5 : public Reader {
public:
    ReaderHDF5(const std::string &filename);
    ~ReaderHDF5() override;

    bool read_event(GenEvent &evt) override;
    bool failed() override;
    void close() override;

private:
    bool m_failed = false;
    HighFive::File m_file;
};

} // namespace HepMC3

#endif
