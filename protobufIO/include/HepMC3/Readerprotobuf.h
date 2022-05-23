// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2022 The HepMC collaboration (see AUTHORS for details)
//
#ifndef HEPMC3_READERPROTOBUF_H
#define HEPMC3_READERPROTOBUF_H
/**
 *  @file  Readerprotobuf.h
 *  @brief Definition of \b class Readerprotobuf
 *
 *  @class HepMC3::Readerprotobuf
 *  @brief GenEvent I/O parsing and serialization for protobuf-based binary files
 *
 * If HepMC was compiled with path to protobuf available, this class can be
 * used for protobuf file I/O in the same manner as with HepMC::ReaderAscii
 * class.
 *
 *  @ingroup IO
 *
 */

#include "HepMC3/GenEvent.h"
#include "HepMC3/Data/GenEventData.h"
#include "HepMC3/Reader.h"

#include <array>
#include <string>
#include <vector>
#include <fstream>

namespace HepMC3 {

class Readerprotobuf : public Reader {
  //
  // Constructors
  //
public:
  /** @brief Default constructor */
  Readerprotobuf(const std::string &filename);
  /** @brief Default constructor */
  Readerprotobuf(std::istream &stream);

  //
  // Functions
  //
public:
  /// @brief skip events
  bool skip(const int) override;

  /** @brief Read event from file
   *
   *  @param[out] evt Contains parsed event
   */
  bool read_event(GenEvent &evt) override;

  /** @brief Close file stream */
  void close() override;

  /** @brief Get stream error state */
  bool failed() override;
  //
  // Fields
  //
private:
  bool buffer_message();
  bool read_GenRunInfo();
  bool read_GenEvent(bool skip = false);
  bool read_Header();

  bool read_file_start();

  size_t bytes_read;
  
  std::unique_ptr<std::ifstream> in_file;
  std::istream *in_stream;

  std::string msg_buffer;
  std::string md_buffer;
  int msg_type;

  HepMC3::GenEventData evdata;
};

} // namespace HepMC3

#endif
