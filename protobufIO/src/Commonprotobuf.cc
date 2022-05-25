// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2022 The HepMC collaboration (see AUTHORS for details)
//
/**
 *  @file Commonprotobuf.cc
 *  @brief Initialization of common constants required by protobuf reader & writer
 *
 *  @ingroup IO
 */

#include "HepMC3/Commonprotobuf.h"

namespace HepMC3 {
  std::string const ProtobufMagicHeader = "HepMC3::Protobuf";
  size_t const ProtobufMagicHeaderBytes = ProtobufMagicHeader.size();
}