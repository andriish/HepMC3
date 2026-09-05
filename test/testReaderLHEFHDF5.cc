// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2026 The HepMC collaboration (see AUTHORS for details)
//

#include "HepMC3/GenEvent.h"
#include "HepMC3/ReaderLHEFHDF5.h"

#include <iostream>

using namespace HepMC3;

int main() {
    ReaderLHEFHDF5 reader("inputReaderLHEFHDF5.hdf5");
    if (reader.failed()) {
        std::cerr << "Failed to open LHEF-HDF5 fixture\n";
        return 1;
    }
    if (!reader.run_info()) {
        std::cerr << "Missing run information\n";
        return 1;
    }

    int event_count = 0;
    GenEvent event;
    while (reader.read_event(event)) {
        if (event.particles().empty()) {
            std::cerr << "Converted event has no particles\n";
            return 1;
        }
        if (!event.run_info()) {
            std::cerr << "Converted event is missing run information\n";
            return 1;
        }
        ++event_count;
        event.clear();
    }
    if (event_count == 0) {
        std::cerr << "LHEF-HDF5 fixture contains no events\n";
        return 1;
    }

    return 0;
}