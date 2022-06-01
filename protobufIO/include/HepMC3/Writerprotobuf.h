// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2022 The HepMC collaboration (see AUTHORS for details)
//
#ifndef HEPMC3_WRITERPROTOBUF_H
#define HEPMC3_WRITERPROTOBUF_H
/**
 *  @file  Writerprotobuf.h
 *  @brief Definition of \b class Writerprotobuf
 *
 *  @class HepMC3::Writerprotobuf
 *  @brief GenEvent I/O serialization for protobuf-based binary files
 *
 *  If HepMC was compiled with protobuf available, this class can be used
 *  for writing in the same manner as with HepMC::WriterAscii class.
 *
 *  @ingroup IO
 *
 */

#include "HepMC3/Writer.h"

#include "HepMC3/GenEvent.h"

#include <fstream>
#include <memory>
#include <string>

namespace HepMC3 {

class Writerprotobuf : public Writer {
  //
  // Constructors
  //
public:
  /** @brief Default constructor
   *  @warning If file exists, it will be overwritten
   */
  Writerprotobuf(
      const std::string &filename,
      std::shared_ptr<GenRunInfo> run = std::shared_ptr<GenRunInfo>());

  Writerprotobuf(std::ostream &out_stream, std::shared_ptr<GenRunInfo> run =
                                               std::shared_ptr<GenRunInfo>());

  Writerprotobuf(
      std::shared_ptr<std::ostream> out_stream,
      std::shared_ptr<GenRunInfo> run = std::shared_ptr<GenRunInfo>());
  //
  // Functions
  //
public:
  /** @brief Write event to file
   *
   *  @param[in] evt Event to be serialized
   */
  void write_event(const GenEvent &evt) override;

  /** @brief Close file stream */
  void close() override;

  /** @brief Get stream error state flag */
  bool failed() override;

  virtual ~Writerprotobuf() { close(); }
  //
  // Fields
  //
private:
  /** @brief Write the GenRunInfo object to file. */
  void write_run_info();
  void start_file();

  std::unique_ptr<std::ofstream> m_out_file;
  std::ostream *m_out_stream;

  size_t m_events_written;
  size_t m_event_bytes_written;
};

} // namespace HepMC3

#endif