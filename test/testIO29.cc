// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2022 The HepMC collaboration (see AUTHORS for details)
//
// -- Purpose: Test that an empty event can be written and read by the 
//             protobuf reader/writer
//

#include "HepMC3/Readerprotobuf.h"
#include "HepMC3/Writerprotobuf.h"

#include "HepMC3/GenEvent.h"
#include "HepMC3/GenParticle.h"
#include "HepMC3/GenRunInfo.h"
#include "HepMC3/GenVertex.h"
#include "HepMC3/Print.h"

#include <cassert>

int main() {

  HepMC3::GenEvent evt;

  std::stringstream binstream;

  auto writer = std::make_shared<HepMC3::Writerprotobuf>(binstream);
  writer->write_event(evt);
  writer->write_event(evt);
  writer->write_event(evt);
  writer->close();

  auto reader = std::make_shared<HepMC3::Readerprotobuf>(binstream);
  HepMC3::GenEvent evt_in;
  assert(reader->read_event(evt_in));
  assert(reader->read_event(evt_in));
  assert(reader->read_event(evt_in));
  reader->close();

  std::stringstream ss1("");
  std::stringstream ss2("");

  HepMC3::Print::listing(evt);
  HepMC3::Print::listing(evt_in);
  std::cout << ss1.str() << "\n" << ss2.str() << std::endl;
  assert(ss1.str() == ss2.str());

  ss1.str("");
  ss2.str("");
  HepMC3::Print::content(ss1, evt_in);
  HepMC3::Print::content(ss2, evt);
  std::cout << ss1.str() << "\n" << ss2.str() << std::endl;
  assert(ss1.str() == ss2.str());

  exit(0);
}
