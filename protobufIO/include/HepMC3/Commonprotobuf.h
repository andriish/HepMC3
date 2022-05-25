// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2022 The HepMC collaboration (see AUTHORS for details)
//
#ifndef HEPMC3_COMMONPROTOBUF_H
#define HEPMC3_COMMONPROTOBUF_H
/**
 *  @file  Commonprotobuf.h
 *  @brief Definition of common constants required by protobuf reader & writer
 *
 *  @ingroup IO
 *
 */

#include <string>

namespace HepMC3 {
  extern std::string const ProtobufMagicHeader;
  extern size_t const ProtobufMagicHeaderBytes;
}

#endif