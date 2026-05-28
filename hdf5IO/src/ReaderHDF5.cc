// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2023 The HepMC collaboration (see AUTHORS for details)
//

#include "HepMC3/ReaderHDF5.h"
#include "HepMC3/GenEvent.h"

namespace HepMC3 {

ReaderHDF5::ReaderHDF5(const std::string &filename)
    : m_failed(false)
    , m_filename(filename)
{
}

ReaderHDF5::~ReaderHDF5() = default;

bool ReaderHDF5::read_event(GenEvent &evt) {
    (void)evt;
    m_failed = true;
    return false;
}

bool ReaderHDF5::failed() {
    return m_failed;
}

void ReaderHDF5::close() {
    // No-op stub
}

} // namespace HepMC3
