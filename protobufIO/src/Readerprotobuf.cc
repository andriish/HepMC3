// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2019 The HepMC collaboration (see AUTHORS for details)
//
/**
 *  @file Readerprotobuf.cc
 *  @brief Implementation of \b class Readerprotobuf
 *
 */
#include "HepMC3/Readerprotobuf.h"
#include "HepMC3/Version.h"

// protobuf header files
#include "HepMC3/HepMC3.pb.h"

namespace HepMC3 {
HEPMC3_DECLARE_READER_FILE(Readerprotobuf);

void Readerprotobuf::read_message() {
  in_file->read(md_buffer.data(), 10);

  if (failed()) {
    return;
  }

  bytes_read += 10;

  HepMC3_pb::MessageDigest md;
  md.ParseFromString(md_buffer);

  // std::cout << "[MessageDigest]:\n>>>>>>>>>>>>>>>>>>\n"
  //           << md.DebugString() << "<<<<<<<<<<<<<<<<<<" << std::endl;

  // std::cout << "--read " << bytes_read << " bytes" << std::endl;

  msg_buffer.resize(md.bytes());
  in_file->read(msg_buffer.data(), md.bytes());
  bytes_read += md.bytes();

  switch (md.message_type()) {
  case HepMC3_pb::MessageDigest::Header: {
    HepMC3_pb::Header hdr;
    hdr.ParseFromString(msg_buffer);
    // std::cout << "--MSG type HepMC3_pb::MessageDigest::Header" << std::endl;
    // std::cout << ">>>>>>>>>>>>>>>>>>\n"
    //           << hdr.DebugString() << "<<<<<<<<<<<<<<<<<<" << std::endl;
    break;
  }
  case HepMC3_pb::MessageDigest::RunInfo: {
    HepMC3_pb::GenRunInfoData gri;
    gri.ParseFromString(msg_buffer);
    // std::cout << "--MSG type HepMC3_pb::MessageDigest::RunInfo" << std::endl;
    // std::cout << ">>>>>>>>>>>>>>>>>>\n"
    //           << gri.DebugString() << "<<<<<<<<<<<<<<<<<<" << std::endl;
    break;
  }
  case HepMC3_pb::MessageDigest::Event: {
    HepMC3_pb::GenEventData ev;
    ev.ParseFromString(msg_buffer);
    // std::cout << "--MSG type HepMC3_pb::MessageDigest::Event" << std::endl;
    // std::cout << ">>>>>>>>>>>>>>>>>>\n"
    //           << ev.DebugString() << "<<<<<<<<<<<<<<<<<<" << std::endl;
    break;
  }
  case HepMC3_pb::MessageDigest::Footer: {
    HepMC3_pb::Footer ftr;
    ftr.ParseFromString(msg_buffer);
    // std::cout << "--MSG type HepMC3_pb::MessageDigest::Footer" << std::endl;
    // std::cout << ">>>>>>>>>>>>>>>>>>\n"
    //           << ftr.DebugString() << "<<<<<<<<<<<<<<<<<<" << std::endl;
    break;
  }
  }
}

Readerprotobuf::Readerprotobuf(const std::string &filename) : bytes_read(0) {

  md_buffer.resize(10);

  GOOGLE_PROTOBUF_VERIFY_VERSION;

  in_file = std::make_unique<ifstream>(filename, ios::in | ios::binary);

  if (!in_file->is_open()) {
    HEPMC3_ERROR("Readerprotobuf: problem opening file: " << filename)
    return;
  }

  while (!failed()) {
    read_message();
  }

  // std::shared_ptr<GenRunInfo> ri = std::make_shared<GenRunInfo>();

  // GenRunInfoData run;

  // ri->read_data(*run);
  // set_run_info(ri);
}

bool Readerprotobuf::skip(const int n) {
  // GenEvent evt;
  // for (int nn = n; nn > 0; --nn) {
  //   if (!read_event(evt))
  //     return false;
  //   evt.clear();
  // }
  return !failed();
}

bool Readerprotobuf::read_event(GenEvent &evt) {
  // Skip object of different type than GenEventData
  // GenEventData data;

  // evt.read_data(*data);
  // evt.set_run_info(run_info());

  return true;
}

void Readerprotobuf::close() { in_file->close(); }

bool Readerprotobuf::failed() {
  return !in_file || !in_file->is_open() || !in_file->good();
}

} // namespace HepMC3
