// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2023 The HepMC collaboration (see AUTHORS for details)
//
/**
 *  @file WriterRoot.cc
 *  @brief Implementation of \b class WriterRoot
 *
 */
#include <array>
#include <cstdio>  // sprintf
#include "HepMC3/WriterRoot.h"
#include "HepMC3/Version.h"
// ROOT header files
#include "TFile.h"
#include "TTree.h"

namespace HepMC3 {
HEPMC3_DECLARE_WRITER_FILE(WriterRoot)

WriterRoot::WriterRoot(const std::string &filename, std::shared_ptr<GenRunInfo> run):
    m_events_count(0) {
    set_run_info(run);

    m_file = TFile::Open(filename.c_str(), "RECREATE");
    if ( !m_file->IsOpen() ) {
        HEPMC3_ERROR_LEVEL(100,"WriterRoot: problem opening file: " << filename)
        return;
    }

    if ( run_info() ) write_run_info();
}

void WriterRoot::write_event(const GenEvent &evt) {
    if ( !m_file->IsOpen() ) return;

    if ( !run_info() ) {
        set_run_info(evt.run_info());
        write_run_info();
    } else {
        if ( evt.run_info() && run_info() != evt.run_info() ) {
            HEPMC3_WARNING_LEVEL(100,"WriterRoot::write_event: GenEvents contain different GenRunInfo objects from - only the first such object will be serialized.")
        }
    }

    GenEventData data;
    evt.write_data(data);

    std::array<char,16> buf{};
    snprintf(buf.data(), buf.size(), "%15i", ++m_events_count);

    int nbytes = m_file->WriteObject(&data, buf.data());

    if ( nbytes == 0 ) {
        HEPMC3_ERROR_LEVEL(100,"WriterRoot: error writing event")
        m_file->Close();
    }
}

void WriterRoot::write_run_info() {
    if ( !m_file->IsOpen() || !run_info() ) return;

    GenRunInfoData data;
    run_info()->write_data(data);

    int nbytes = m_file->WriteObject(&data, "GenRunInfoData");

    if ( nbytes == 0 ) {
        HEPMC3_ERROR_LEVEL(100,"WriterRoot: error writing GenRunInfo")
        m_file->Close();
    }
}

void WriterRoot::close() {
    m_file->Close();
}

bool WriterRoot::failed() {
    return !m_file->IsOpen();
}

} // namespace HepMC3
