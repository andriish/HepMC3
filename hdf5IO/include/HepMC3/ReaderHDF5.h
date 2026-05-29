// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2023 The HepMC collaboration (see AUTHORS for details)
//
#ifndef HEPMC3_READERHDF5_H
#define HEPMC3_READERHDF5_H

#include "HepMC3/Reader.h"
#include "HepMC3/highfive/H5File.hpp"
#include <string>
#include <vector>

namespace HepMC3 {

class ReaderHDF5 : public Reader {
public:
    ReaderHDF5(const std::string &filename);
    ~ReaderHDF5() override;

    bool read_event(GenEvent &evt) override;
    bool skip(const int n) override;
    bool failed() override;
    void close() override;

private:
    bool m_failed = false;
    HighFive::File m_file;
    std::vector<std::string> m_object_names;
    std::size_t m_next_index = 0;
};

} // namespace HepMC3

#endif
