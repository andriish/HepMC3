// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2022 The HepMC collaboration (see AUTHORS for details)
//
/**
 *  @file Readerprotobuf.cc
 *  @brief Implementation of \b class Readerprotobuf
 *
 */
#include "HepMC3/Readerprotobuf.h"

#include "HepMC3/Print.h"
#include "HepMC3/Version.h"

#include "HepMC3/Data/GenRunInfoData.h"

#include "HepMC3/Commonprotobuf.h"

// protobuf header files
#include "HepMC3.pb.h"

namespace HepMC3 {
HEPMC3_DECLARE_READER_FILE(Readerprotobuf);
HEPMC3_DECLARE_READER_STREAM(Readerprotobuf);

static size_t const MDBytesLength = 10;

Readerprotobuf::Readerprotobuf(const std::string &filename)
    : in_file(nullptr), bytes_read(0),
      msg_type(HepMC3_pb::MessageDigest::unknown) {

  md_buffer.resize(MDBytesLength);

  GOOGLE_PROTOBUF_VERIFY_VERSION;

  in_file = std::unique_ptr<std::ifstream>(
      new std::ifstream(filename, ios::in | ios::binary));

  if (!in_file->is_open()) {
    HEPMC3_ERROR("Readerprotobuf: Problem opening file: " << filename)
    return;
  }

  in_stream = in_file.get();

  read_file_start();
}

Readerprotobuf::Readerprotobuf(std::istream &stream)
    : in_file(nullptr), bytes_read(0),
      msg_type(HepMC3_pb::MessageDigest::unknown) {

  if (!stream.good()) {
    HEPMC3_ERROR(
        "Cannot initialize Readerprotobuf on istream which is not good().");
    return;
  }

  md_buffer.resize(MDBytesLength);

  GOOGLE_PROTOBUF_VERIFY_VERSION;

  in_stream = &stream;
  read_file_start();
}

bool Readerprotobuf::read_file_start() {

  // Read the first 16 bytes, it should read "HepMC3::Protobuf"
  std::string MagicIntro;
  MagicIntro.resize(ProtobufMagicHeaderBytes);
  in_stream->read(&MagicIntro[0], ProtobufMagicHeaderBytes);

  if (MagicIntro != ProtobufMagicHeader) {
    HEPMC3_ERROR("Failed to find expected Magic first "
                 << ProtobufMagicHeaderBytes
                 << " bytes, is this really "
                    "a HepMC3::Protobuf file?");
    return false;
  }

  if (!read_Header()) {
    HEPMC3_ERROR("Readerprotobuf: Problem parsing start of file, expected to "
                 "find Header, but instead found message type: "
                 << msg_type);
    return false;
  }

  if (!read_GenRunInfo()) {
    HEPMC3_ERROR("Readerprotobuf: Problem parsing start of file, expected to "
                 "find RunInfo, but instead found message type: "
                 << msg_type);
    return false;
  }

  buffer_message(); // check that we can find an event message
  if (msg_type != HepMC3_pb::MessageDigest::Event) {
    HEPMC3_ERROR("Readerprotobuf: Problem parsing start of file, expected to "
                 "find Event, but instead found message type: "
                 << msg_type);
    return false;
  }

  return true;
}

bool Readerprotobuf::buffer_message() {
  if (msg_buffer.size()) {
    return false;
  }

  msg_type = HepMC3_pb::MessageDigest::unknown;

  in_stream->read(&md_buffer[0], MDBytesLength);

  if (failed()) {
    return false;
  }

  bytes_read += MDBytesLength;

  HepMC3_pb::MessageDigest md;
  md.ParseFromString(md_buffer);

  msg_type = md.message_type();
  msg_buffer.resize(md.bytes());
  in_stream->read(&msg_buffer[0], md.bytes());

  if (failed()) {
    return false;
  }

  bytes_read += md.bytes();
  return true;
}

bool Readerprotobuf::read_Header() {
  buffer_message();
  if (msg_type != HepMC3_pb::MessageDigest::Header) {
    return false;
  }
  msg_buffer.clear();
  return true;
}

bool Readerprotobuf::read_GenRunInfo() {
  buffer_message();
  if (msg_type != HepMC3_pb::MessageDigest::RunInfo) {
    return false;
  }

  set_run_info(std::shared_ptr<HepMC3::GenRunInfo>(new HepMC3::GenRunInfo()));

  HepMC3_pb::GenRunInfoData GenRunInfo_pb;
  GenRunInfo_pb.ParseFromString(msg_buffer);
  msg_buffer.clear();

  HepMC3::GenRunInfoData gridata;

  int vector_size = 0;

  vector_size = GenRunInfo_pb.weight_names_size();
  for (int it = 0; it < vector_size; ++it) {
    gridata.weight_names.push_back(GenRunInfo_pb.weight_names(it));
  }

  vector_size = GenRunInfo_pb.tool_name_size();
  for (int it = 0; it < vector_size; ++it) {
    gridata.tool_name.push_back(GenRunInfo_pb.tool_name(it));
  }

  vector_size = GenRunInfo_pb.tool_version_size();
  for (int it = 0; it < vector_size; ++it) {
    gridata.tool_version.push_back(GenRunInfo_pb.tool_version(it));
  }

  vector_size = GenRunInfo_pb.tool_description_size();
  for (int it = 0; it < vector_size; ++it) {
    gridata.tool_description.push_back(GenRunInfo_pb.tool_description(it));
  }

  vector_size = GenRunInfo_pb.attribute_name_size();
  for (int it = 0; it < vector_size; ++it) {
    gridata.attribute_name.push_back(GenRunInfo_pb.attribute_name(it));
  }

  vector_size = GenRunInfo_pb.attribute_string_size();
  for (int it = 0; it < vector_size; ++it) {
    gridata.attribute_string.push_back(GenRunInfo_pb.attribute_string(it));
  }

  run_info()->read_data(gridata);
  return true;
}

bool Readerprotobuf::read_GenEvent(bool skip) {
  buffer_message();
  if (msg_type != HepMC3_pb::MessageDigest::Event) {
    return false;
  }

  if (skip) { // Don't parse to HepMC3 if skipping
    msg_buffer.clear();
    return true;
  }

  HepMC3_pb::GenEventData ged_pb;
  ged_pb.ParseFromString(msg_buffer);

  evdata.event_number = ged_pb.event_number();

  switch (ged_pb.momentum_unit()) {
  case HepMC3_pb::GenEventData::MEV: {
    evdata.momentum_unit = HepMC3::Units::MEV;
    break;
  }
  case HepMC3_pb::GenEventData::GEV: {
    evdata.momentum_unit = HepMC3::Units::GEV;
    break;
  }
  default: {
    HEPMC3_ERROR("Unknown momentum unit: " << ged_pb.momentum_unit());
    abort();
  }
  }

  switch (ged_pb.length_unit()) {
  case HepMC3_pb::GenEventData::MM: {
    evdata.length_unit = HepMC3::Units::MM;
    break;
  }
  case HepMC3_pb::GenEventData::CM: {
    evdata.length_unit = HepMC3::Units::CM;
    break;
  }
  default: {
    HEPMC3_ERROR("Unknown length unit: " << ged_pb.length_unit());
    abort();
  }
  }

  int vector_size = 0;

  evdata.particles.clear();
  vector_size = ged_pb.particles_size();
  for (int it = 0; it < vector_size; ++it) {
    auto particle_pb = ged_pb.particles(it);

    HepMC3::GenParticleData pdata;

    pdata.pid = particle_pb.pid();
    pdata.status = particle_pb.status();
    pdata.is_mass_set = particle_pb.is_mass_set();
    pdata.mass = particle_pb.mass();

    pdata.momentum = HepMC3::FourVector{
        particle_pb.momentum().m_v1(), particle_pb.momentum().m_v2(),
        particle_pb.momentum().m_v3(), particle_pb.momentum().m_v4()};

    evdata.particles.push_back(pdata);
  }

  evdata.vertices.clear();
  vector_size = ged_pb.vertices_size();
  for (int it = 0; it < vector_size; ++it) {
    auto vertex_pb = ged_pb.vertices(it);

    HepMC3::GenVertexData vdata;

    vdata.status = vertex_pb.status();

    vdata.position = HepMC3::FourVector{
        vertex_pb.position().m_v1(), vertex_pb.position().m_v2(),
        vertex_pb.position().m_v3(), vertex_pb.position().m_v4()};

    evdata.vertices.push_back(vdata);
  }

  evdata.weights.clear();
  vector_size = ged_pb.weights_size();
  for (int it = 0; it < vector_size; ++it) {
    evdata.weights.push_back(ged_pb.weights(it));
  }

  evdata.links1.clear();
  vector_size = ged_pb.links1_size();
  for (int it = 0; it < vector_size; ++it) {
    evdata.links1.push_back(ged_pb.links1(it));
  }

  evdata.links2.clear();
  vector_size = ged_pb.links2_size();
  for (int it = 0; it < vector_size; ++it) {
    evdata.links2.push_back(ged_pb.links2(it));
  }

  evdata.event_pos =
      HepMC3::FourVector{ged_pb.event_pos().m_v1(), ged_pb.event_pos().m_v2(),
                         ged_pb.event_pos().m_v3(), ged_pb.event_pos().m_v4()};

  evdata.attribute_id.clear();
  vector_size = ged_pb.attribute_id_size();
  for (int it = 0; it < vector_size; ++it) {
    evdata.attribute_id.push_back(ged_pb.attribute_id(it));
  }

  evdata.attribute_name.clear();
  vector_size = ged_pb.attribute_name_size();
  for (int it = 0; it < vector_size; ++it) {
    evdata.attribute_name.push_back(ged_pb.attribute_name(it));
  }

  evdata.attribute_string.clear();
  vector_size = ged_pb.attribute_string_size();
  for (int it = 0; it < vector_size; ++it) {
    evdata.attribute_string.push_back(ged_pb.attribute_string(it));
  }

  msg_buffer.clear();
  return true;
}

bool Readerprotobuf::skip(const int n) {

  for (int nn = n; nn > 0; --nn) {
    if (!read_GenEvent(true)) {
      return false;
    }
  }
  return !failed();
}

bool Readerprotobuf::read_event(GenEvent &evt) {

  if (!read_GenEvent(false)) {
    return false;
  }

  evt.read_data(evdata);
  evt.set_run_info(run_info());

  return true;
}

void Readerprotobuf::close() {
  if (in_file) {
    in_file->close();
    in_file.reset();
  }
  in_stream = nullptr;
}

bool Readerprotobuf::failed() {
  if (in_file) {
    return !in_file->is_open() || !in_file->good();
  }
  return !in_stream || !in_stream->good();
}

} // namespace HepMC3
