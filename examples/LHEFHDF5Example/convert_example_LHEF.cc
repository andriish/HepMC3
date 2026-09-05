// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2026 The HepMC collaboration (see AUTHORS for details)
//
/// @example convert_example_LHEF.cc
/// @brief Convert an LHE file to LHEF-HDF5 and back to LHE.

#include "HepMC3/LHEF.h"
#include "HepMC3/LHEFHDF5.h"
#if HEPMC3_USE_COMPRESSION
#include "HepMC3/LHEFGZ.h"
#endif

#include <iostream>
#include <map>
#include <string>

enum Format { LHEF, LHEFGZ, LHEFLZMA, LHEFBZ2, LHEFZSTD, LHEFHDF5 };

static void print_usage(const char *program) {
    std::cerr << "Usage: " << program << " -i lhef|lhefgz|lheflzma|lhefbz2|lhefzstd|lhefhdf5 -o lhef|lhefgz|lheflzma|lhefbz2|lhefzstd|lhefhdf5 input output\n";
}

template <class Reader> static int write_hdf5(Reader &input, const std::string &output_name) {
    LHEFHDF5::Writer output(output_name, input.heprup);
    output.init();
    while (input.readEvent()) output.writeEvent(input.hepeup);
    const bool failed = output.failed();
    output.close();
    return failed ? 1 : 0;
}

template <class Reader, class Writer> static int write_lhef(Reader &input, const std::string &output_name) {
    Writer output(output_name);
    output.heprup = input.heprup;
    output.init();
    while (input.readEvent()) {
        output.hepeup = input.hepeup;
        output.hepeup.heprup = &output.heprup;
        output.writeEvent();
    }
    output.close();
    return 0;
}

#if HEPMC3_USE_COMPRESSION
template <HepMC3::Compression C> static int write_compressed_lhef(LHEFHDF5::Reader &input, const std::string &output_name) {
    return write_lhef<LHEFHDF5::Reader, LHEFGZ::Writer<C> >(input, output_name);
}

static int read_compressed_lhef(const std::string &input_name, const std::string &output_name) {
    LHEFGZ::Reader<> input(input_name);
    if (input.failed()) {
        std::cerr << "Failed to read " << input_name << "\n";
        return 1;
    }
    const int result = write_hdf5(input, output_name);
    input.close();
    return result;
}
#endif

int main(int argc, char **argv) {
    if (argc != 7 || std::string(argv[1]) != "-i" || std::string(argv[3]) != "-o") {
        print_usage(argv[0]);
        return 1;
    }

    const std::map<std::string, Format> formats = {
        {"lhef", LHEF},
        {"lhefgz", LHEFGZ},
        {"lheflzma", LHEFLZMA},
        {"lhefbz2", LHEFBZ2},
        {"lhefzstd", LHEFZSTD},
        {"lhefhdf5", LHEFHDF5}
    };
    const std::map<std::string, Format>::const_iterator input_format = formats.find(argv[2]);
    const std::map<std::string, Format>::const_iterator output_format = formats.find(argv[4]);
    if (input_format == formats.end() || output_format == formats.end()) {
        print_usage(argv[0]);
        return 1;
    }
    if (input_format->second == output_format->second) {
        std::cerr << "Input and output formats must differ\n";
        return 1;
    }

    const std::string input_name = argv[5];
    const std::string output_name = argv[6];
    if (input_format->second == LHEF && output_format->second == LHEFHDF5) {
        LHEF::Reader input(input_name);
        return write_hdf5(input, output_name);
    }

    if (input_format->second == LHEFHDF5 && output_format->second == LHEF) {
        LHEFHDF5::Reader input(input_name);
        if (input.failed()) {
            std::cerr << "Failed to read " << input_name << "\n";
            return 1;
        }
        const int result = write_lhef<LHEFHDF5::Reader, LHEF::Writer>(input, output_name);
        input.close();
        return result;
    }

#if HEPMC3_USE_COMPRESSION
    if ((input_format->second == LHEFGZ || input_format->second == LHEFLZMA ||
         input_format->second == LHEFBZ2 || input_format->second == LHEFZSTD) &&
        output_format->second == LHEFHDF5) {
        return read_compressed_lhef(input_name, output_name);
    }

#if HEPMC3_Z_SUPPORT
    if (input_format->second == LHEFHDF5 && output_format->second == LHEFGZ) {
        LHEFHDF5::Reader input(input_name);
        if (input.failed()) {
            std::cerr << "Failed to read " << input_name << "\n";
            return 1;
        }
        const int result = write_compressed_lhef<HepMC3::Compression::z>(input, output_name);
        input.close();
        return result;
    }
#endif
#if HEPMC3_LZMA_SUPPORT
    if (input_format->second == LHEFHDF5 && output_format->second == LHEFLZMA) {
        LHEFHDF5::Reader input(input_name);
        if (input.failed()) return 1;
        const int result = write_compressed_lhef<HepMC3::Compression::lzma>(input, output_name);
        input.close();
        return result;
    }
#endif
#if HEPMC3_BZ2_SUPPORT
    if (input_format->second == LHEFHDF5 && output_format->second == LHEFBZ2) {
        LHEFHDF5::Reader input(input_name);
        if (input.failed()) return 1;
        const int result = write_compressed_lhef<HepMC3::Compression::bz2>(input, output_name);
        input.close();
        return result;
    }
#endif
#if HEPMC3_ZSTD_SUPPORT
    if (input_format->second == LHEFHDF5 && output_format->second == LHEFZSTD) {
        LHEFHDF5::Reader input(input_name);
        if (input.failed()) return 1;
        const int result = write_compressed_lhef<HepMC3::Compression::zstd>(input, output_name);
        input.close();
        return result;
    }
#endif
#else
    if (input_format->second == LHEFGZ || input_format->second == LHEFLZMA || input_format->second == LHEFBZ2 || input_format->second == LHEFZSTD || output_format->second == LHEFGZ || output_format->second == LHEFLZMA || output_format->second == LHEFBZ2 || output_format->second == LHEFZSTD) {
        std::cerr << "Compressed LHEF support requires a configured compression library\n";
        return 1;
    }
#endif

    std::cerr << "The selected format conversion is not supported\n";
    return 1;
}