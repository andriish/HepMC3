// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2023 The HepMC collaboration (see AUTHORS for details)
//
#ifndef HEPMC3_READERHDF5_H
#define HEPMC3_READERHDF5_H

#include "HepMC3/Reader.h"
#include <memory>
#include <string>
#include <vector>

namespace HighFive {
class File;
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
    bool m_failed = false;
    std::unique_ptr<HighFive::File> m_file;
    std::size_t m_next_index = 0;
    std::size_t m_event_count = 0;
};

} // namespace HepMC3

#endif
