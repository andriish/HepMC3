// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2023 The HepMC collaboration (see AUTHORS for details)
//

#include "HepMC3/WriterHDF5.h"
#include "HepMC3/GenEvent.h"

namespace HepMC3 {

WriterHDF5::WriterHDF5(const std::string &filename)
    : m_failed(false)
    , m_filename(filename)
{
}

WriterHDF5::~WriterHDF5() = default;

void WriterHDF5::write_event(const GenEvent &evt) {
    (void)evt;
    m_failed = true;
}

bool WriterHDF5::failed() {
    return m_failed;
}

void WriterHDF5::close() {
    // No-op stub
}

} // namespace HepMC3
