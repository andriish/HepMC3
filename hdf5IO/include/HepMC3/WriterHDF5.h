// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2023 The HepMC collaboration (see AUTHORS for details)
//
#ifndef HEPMC3_WRITERHDF5_H
#define HEPMC3_WRITERHDF5_H

#include "HepMC3/Writer.h"
#include <string>

namespace HepMC3 {

class WriterHDF5 : public Writer {
public:
    WriterHDF5(const std::string &filename);
    ~WriterHDF5() override;

    void write_event(const GenEvent &evt) override;
    bool failed() override;
    void close() override;

private:
    bool m_failed = false;
    std::string m_filename;
};

} // namespace HepMC3

#endif
