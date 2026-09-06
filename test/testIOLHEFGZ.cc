// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2026 The HepMC collaboration (see AUTHORS for details)
//
#include "HepMC3/LHEF.h"
#include "HepMC3/LHEFGZ.h"
#include "HepMC3TestUtils.h"

int main()
{
#if HEPMC3_USE_COMPRESSION
    const std::string input_lhe = "inputIOLHEFGZ.lhe";
    auto supported = LHEF::supported_compression_types;

    // 1. Test uncompressed round-trip using LHEF::Reader and LHEF::Writer
    {
        std::string uncompressed_out = "frominputIOLHEFGZ_plain.lhe";
        LHEF::Reader reader_plain(input_lhe);
        if (reader_plain.failed()) return 1;

        LHEF::Writer writer_plain(uncompressed_out);
        writer_plain.heprup = reader_plain.heprup;
        writer_plain.headerBlock(reader_plain.headerBlock);
        writer_plain.init();

        while (reader_plain.readEvent()) {
            writer_plain.hepeup = reader_plain.hepeup;
            writer_plain.hepeup.heprup = &writer_plain.heprup;
            writer_plain.writeEvent();
        }
        if (writer_plain.failed()) return 2;
        writer_plain.close();
        reader_plain.close();

        if (COMPARE_ASCII_FILES(uncompressed_out, input_lhe) != 0) return 3;
    }

    // 2. Test writing compressed LHE files with LHEF::WriterGZ
    for (auto c : supported) {
        std::string filename = "frominputIOLHEFGZ.lhe." + LHEF::to_string(c);
        LHEF::Reader reader_in(input_lhe);
        if (reader_in.failed()) return 4;

        std::unique_ptr<LHEF::WriterBase> writer;
        switch (c) {
#if HEPMC3_Z_SUPPORT
        case LHEF::Compression::z:
            writer.reset(new LHEF::WriterGZ<LHEF::Writer, LHEF::Compression::z>(filename));
            break;
#endif
#if HEPMC3_LZMA_SUPPORT
        case LHEF::Compression::lzma:
            writer.reset(new LHEF::WriterGZ<LHEF::Writer, LHEF::Compression::lzma>(filename));
            break;
#endif
#if HEPMC3_BZ2_SUPPORT
        case LHEF::Compression::bz2:
            writer.reset(new LHEF::WriterGZ<LHEF::Writer, LHEF::Compression::bz2>(filename));
            break;
#endif
#if HEPMC3_ZSTD_SUPPORT
        case LHEF::Compression::zstd:
            writer.reset(new LHEF::WriterGZ<LHEF::Writer, LHEF::Compression::zstd>(filename));
            break;
#endif
        default:
            return 5;
        }

        writer->heprup = reader_in.heprup;
        writer->headerBlock(reader_in.headerBlock);
        writer->init();

        while (reader_in.readEvent()) {
            writer->hepeup = reader_in.hepeup;
            writer->hepeup.heprup = &writer->heprup;
            writer->writeEvent();
        }
        if (writer->failed()) return 6;
        writer->close();
        reader_in.close();
    }

    // 3. Test reading back compressed LHE files using LHEF::ReaderGZ and writing uncompressed LHE with LHEF::Writer
    for (auto c : supported) {
        std::string filename = "frominputIOLHEFGZ.lhe." + LHEF::to_string(c);
        std::string output_lhe = "fromfrominputIOLHEFGZ_" + LHEF::to_string(c) + ".lhe";

        LHEF::ReaderGZ<> reader_gz(filename);
        if (reader_gz.failed()) return 7;

        LHEF::Writer writer_out(output_lhe);
        writer_out.heprup = reader_gz.heprup;
        writer_out.headerBlock(reader_gz.headerBlock);
        writer_out.init();

        while (reader_gz.readEvent()) {
            writer_out.hepeup = reader_gz.hepeup;
            writer_out.hepeup.heprup = &writer_out.heprup;
            writer_out.writeEvent();
        }
        if (writer_out.failed()) return 8;
        writer_out.close();
        reader_gz.close();

        if (COMPARE_ASCII_FILES(output_lhe, input_lhe) != 0) return 9;
    }

    // 4. Test reading compressed LHE files with LHEF::ReaderGZ and writing compressed LHE with LHEF::WriterGZ (compressed-to-compressed)
    for (auto c : supported) {
        std::string filename_in = "frominputIOLHEFGZ.lhe." + LHEF::to_string(c);
        std::string filename_out = "fromcompressed_IOLHEFGZ.lhe." + LHEF::to_string(c);
        std::string output_lhe_decompressed = "fromfromcompressed_IOLHEFGZ_" + LHEF::to_string(c) + ".lhe";

        LHEF::ReaderGZ<> reader_gz(filename_in);
        if (reader_gz.failed()) return 10;

        std::unique_ptr<LHEF::WriterBase> writer_gz;
        switch (c) {
#if HEPMC3_Z_SUPPORT
        case LHEF::Compression::z:
            writer_gz.reset(new LHEF::WriterGZ<LHEF::Writer, LHEF::Compression::z>(filename_out));
            break;
#endif
#if HEPMC3_LZMA_SUPPORT
        case LHEF::Compression::lzma:
            writer_gz.reset(new LHEF::WriterGZ<LHEF::Writer, LHEF::Compression::lzma>(filename_out));
            break;
#endif
#if HEPMC3_BZ2_SUPPORT
        case LHEF::Compression::bz2:
            writer_gz.reset(new LHEF::WriterGZ<LHEF::Writer, LHEF::Compression::bz2>(filename_out));
            break;
#endif
#if HEPMC3_ZSTD_SUPPORT
        case LHEF::Compression::zstd:
            writer_gz.reset(new LHEF::WriterGZ<LHEF::Writer, LHEF::Compression::zstd>(filename_out));
            break;
#endif
        default:
            return 11;
        }

        writer_gz->heprup = reader_gz.heprup;
        writer_gz->headerBlock(reader_gz.headerBlock);
        writer_gz->init();

        while (reader_gz.readEvent()) {
            writer_gz->hepeup = reader_gz.hepeup;
            writer_gz->hepeup.heprup = &writer_gz->heprup;
            writer_gz->writeEvent();
        }
        if (writer_gz->failed()) return 12;
        writer_gz->close();
        reader_gz.close();

        // Verify by reading back and comparing to original
        LHEF::ReaderGZ<> reader_check(filename_out);
        if (reader_check.failed()) return 13;

        LHEF::Writer writer_check(output_lhe_decompressed);
        writer_check.heprup = reader_check.heprup;
        writer_check.headerBlock(reader_check.headerBlock);
        writer_check.init();

        while (reader_check.readEvent()) {
            writer_check.hepeup = reader_check.hepeup;
            writer_check.hepeup.heprup = &writer_check.heprup;
            writer_check.writeEvent();
        }
        writer_check.close();
        reader_check.close();

        if (COMPARE_ASCII_FILES(output_lhe_decompressed, input_lhe) != 0) return 14;
    }
#endif
    return 0;
}
