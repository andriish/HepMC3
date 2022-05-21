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
 *  @brief GenEvent I/O parsing and serialization for protobuf files
 *
 *  If HepMC was compiled with path to protobuf available, this class can be
 * used for protobuf file I/O in the same manner as with HepMC::ReaderAscii
 * class.
 *
 *  @ingroup IO
 *
 */

#include "HepMC3/GenEvent.h"
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
  void read_message();

  size_t bytes_read;
  std::unique_ptr<std::ifstream> in_file;
  std::string msg_buffer;
  std::string md_buffer;
};

} // namespace HepMC3

#endif
