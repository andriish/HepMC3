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
#include <memory>
#include <string>

enum class Format { LHEF, LHEFGZ, LHEFLZMA, LHEFBZ2, LHEFZSTD, LHEFHDF5 };

static void print_usage(const char *program) {
    std::cerr << "Usage: " << program << " -i lhef|lhefgz|lheflzma|lhefbz2|lhefzstd|lhefhdf5 -o lhef|lhefgz|lheflzma|lhefbz2|lhefzstd|lhefhdf5 input output\n";
}

static int copy_events(LHEF::ReaderBase &input, LHEF::WriterBase &output) {
    output.heprup = input.heprup;
    output.init();
    while (input.readEvent()) {
        output.hepeup = input.hepeup;
        output.hepeup.heprup = &output.heprup;
        output.writeEvent();
    }
    const bool failed = output.failed();
    output.close();
    input.close();
    return failed ? 1 : 0;
}

static std::unique_ptr<LHEF::ReaderBase> create_reader(Format format, const std::string &filename) {
    if (format == Format::LHEF) {
        return std::unique_ptr<LHEF::ReaderBase>(new LHEF::Reader(filename));
    }
    if (format == Format::LHEFHDF5) {
        return std::unique_ptr<LHEF::ReaderBase>(new LHEF::ReaderHDF5(filename));
    }
#if HEPMC3_USE_COMPRESSION
    if (format == Format::LHEFGZ || format == Format::LHEFLZMA ||
        format == Format::LHEFBZ2 || format == Format::LHEFZSTD) {
        return std::unique_ptr<LHEF::ReaderBase>(new LHEF::ReaderGZ<>(filename));
    }
#endif
    return nullptr;
}

static std::unique_ptr<LHEF::WriterBase> create_writer(Format format, const std::string &filename) {
    if (format == Format::LHEF) {
        return std::unique_ptr<LHEF::WriterBase>(new LHEF::Writer(filename));
    }
    if (format == Format::LHEFHDF5) {
        return std::unique_ptr<LHEF::WriterBase>(new LHEF::WriterHDF5(filename));
    }
#if HEPMC3_USE_COMPRESSION
#if HEPMC3_Z_SUPPORT
    if (format == Format::LHEFGZ) {
        return std::unique_ptr<LHEF::WriterBase>(new LHEF::WriterGZ<LHEF::Writer, LHEF::Compression::z>(filename));
    }
#endif
#if HEPMC3_LZMA_SUPPORT
    if (format == Format::LHEFLZMA) {
        return std::unique_ptr<LHEF::WriterBase>(new LHEF::WriterGZ<LHEF::Writer, LHEF::Compression::lzma>(filename));
    }
#endif
#if HEPMC3_BZ2_SUPPORT
    if (format == Format::LHEFBZ2) {
        return std::unique_ptr<LHEF::WriterBase>(new LHEF::WriterGZ<LHEF::Writer, LHEF::Compression::bz2>(filename));
    }
#endif
#if HEPMC3_ZSTD_SUPPORT
    if (format == Format::LHEFZSTD) {
        return std::unique_ptr<LHEF::WriterBase>(new LHEF::WriterGZ<LHEF::Writer, LHEF::Compression::zstd>(filename));
    }
#endif
#endif
    return nullptr;
}

int main(int argc, char **argv) {
    if (argc != 7 || std::string(argv[1]) != "-i" || std::string(argv[3]) != "-o") {
        print_usage(argv[0]);
        return 1;
    }

    const std::map<std::string, Format> formats = {
        {"lhef", Format::LHEF},
        {"lhefgz", Format::LHEFGZ},
        {"lheflzma", Format::LHEFLZMA},
        {"lhefbz2", Format::LHEFBZ2},
        {"lhefzstd", Format::LHEFZSTD},
        {"lhefhdf5", Format::LHEFHDF5}
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

    std::unique_ptr<LHEF::ReaderBase> input = create_reader(input_format->second, input_name);
    if (!input || input->failed()) {
        std::cerr << "Failed to read input file " << input_name << "\n";
        return 1;
    }

    std::unique_ptr<LHEF::WriterBase> output = create_writer(output_format->second, output_name);
    if (!output) {
        std::cerr << "The selected output format is not supported or not enabled\n";
        return 1;
    }

    return copy_events(*input, *output);
}