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

class ReaderLHEFHDF5 : public Reader {
public:
    explicit ReaderLHEFHDF5(const std::string &filename);
    ~ReaderLHEFHDF5() override;

    bool read_event(GenEvent &event) override;
    bool skip(const int n) override;
    bool failed() override;
    void close() override;

private:
    void init();

    std::unique_ptr<LHEFHDF5::Reader> m_reader;
    int m_neve = 0;
};

} // namespace HepMC3

#endif