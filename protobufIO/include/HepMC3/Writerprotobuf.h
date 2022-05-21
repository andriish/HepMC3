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
 *  @brief GenEvent I/O serialization for root files
 *
 *  If HepMC was compiled with path to ROOT available, this class can be used
 *  for root writing in the same manner as with HepMC::WriterAscii class.
 *
 *  @ingroup IO
 *
 */

#include "HepMC3/GenEvent.h"
#include "HepMC3/Writer.h"

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

  std::unique_ptr<std::ofstream> out_file;

  size_t number_of_events_written;
};

} // namespace HepMC3

#endif