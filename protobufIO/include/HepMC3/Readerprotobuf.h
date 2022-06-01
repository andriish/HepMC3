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
 *  @brief GenEvent I/O parsing and serialization for protobuf-based binary
 * files
 *
 * If HepMC was compiled with path to protobuf available, this class can be
 * used for protobuf file I/O in the same manner as with HepMC::ReaderAscii
 * class.
 *
 *  @ingroup IO
 *
 */

#include "HepMC3/Reader.h"

#include "HepMC3/GenEvent.h"

#include "HepMC3/Data/GenEventData.h"

#include <array>
#include <fstream>
#include <string>
#include <vector>

namespace HepMC3 {

class Readerprotobuf : public Reader {
  //
  // Types
  //
public:
  struct FileHeader {
    std::string m_version_str;
    unsigned int m_version_maj;
    unsigned int m_version_min;
    unsigned int m_version_patch;

    unsigned int m_protobuf_version_maj;
    unsigned int m_protobuf_version_min;
    unsigned int m_protobuf_version_patch;
  };

  //
  // Constructors
  //
public:
  /** @brief */
  Readerprotobuf(const std::string &filename);
  /** @brief */
  Readerprotobuf(std::istream &stream);
  /** @brief */
  Readerprotobuf(std::shared_ptr<std::istream> stream);
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

  FileHeader const &file_header() { return m_file_header; }

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

  size_t m_bytes_read;

  std::unique_ptr<std::ifstream> m_in_file;
  std::istream *m_in_stream;

  std::string m_msg_buffer;
  std::string m_md_buffer;
  int m_msg_type;

  HepMC3::GenEventData m_evdata;

  FileHeader m_file_header;
};

} // namespace HepMC3

#endif
