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
    bool m_failed = false;
    int m_event_counter = 0;
    std::unique_ptr<HighFive::File> m_file;
    std::shared_ptr<GenRunInfo> m_run;
};

} // namespace HepMC3

#endif
