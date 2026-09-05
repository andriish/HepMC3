// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2026 The HepMC collaboration (see AUTHORS for details)
//

#include "HepMC3/LHEF.h"
#include "HepMC3/LHEFHDF5.h"
#include "HepMC3TestUtils.h"

#include <iostream>

int main() {
    const std::string input_name = "inputLHEFHDF5RoundTrip.lhe";
    const std::string hdf5_name = "fromLHEFHDF5RoundTrip.hdf5";
    const std::string output_name = "fromfromLHEFHDF5RoundTrip.lhe";

    LHEF::Reader input(input_name);
    LHEFHDF5::Writer hdf5_writer(hdf5_name, input.heprup);
    hdf5_writer.init();
    while (input.readEvent()) hdf5_writer.writeEvent(input.hepeup);
    if (hdf5_writer.failed()) {
        std::cerr << "Failed to write LHEF-HDF5 file\n";
        return 1;
    }
    hdf5_writer.close();

    LHEFHDF5::Reader hdf5_reader(hdf5_name);
    if (hdf5_reader.failed()) {
        std::cerr << "Failed to read LHEF-HDF5 file\n";
        return 1;
    }
    {
        LHEF::Writer output(output_name);
        output.heprup = hdf5_reader.m_heprup;
        output.headerBlock(input.headerBlock);
        output.init();
        while (hdf5_reader.readEvent()) {
            output.hepeup = hdf5_reader.m_hepeup;
            output.hepeup.heprup = &output.heprup;
            output.writeEvent();
        }
    }

    return COMPARE_ASCII_FILES(output_name, input_name);
}