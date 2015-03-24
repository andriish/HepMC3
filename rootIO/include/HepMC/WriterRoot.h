// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014 The HepMC collaboration (see AUTHORS for details)
//
#ifndef  HEPMC_WRITERROOT_H
#define  HEPMC_WRITERROOT_H
/**
 *  @file  WriterRoot.h
 *  @brief Definition of \b class WriterRoot
 *
 *  @class HepMC::WriterRoot
 *  @brief GenEvent I/O serialization for root files
 *
 *  If HepMC was compiled with path to ROOT available, this class can be used
 *  for root writing in the same manner as with HepMC::WriterAscii class.
 *
 *  @ingroup IO
 *
 */
#include "HepMC/GenEvent.h"
#include "HepMC/Data/GenEventData.h"

// ROOT header files
#include "TFile.h"

namespace HepMC {

class WriterRoot {
//
// Constructors
//
public:
    /** @brief Default constructor
     *  @warning If file exists, it will be overwritten
     */
    WriterRoot(const std::string &filename);

//
// Functions
//
public:

    /** @brief Write event to file
     *
     *  @param[in] evt Event to be serialized
     */
    void write_event(const GenEvent &evt);

    /** @brief Close file stream */
    void close();

    /** @brief Get stream error state flags
     *
     *  @todo Rename!
     */
    int rdstate();
//
// Fields
//
private:
    TFile m_file; //!< File handler
};

} // namespace HepMC

#endif