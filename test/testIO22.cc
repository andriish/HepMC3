// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2022 The HepMC collaboration (see AUTHORS for details)
//
// -- Purpose: Test that a file produced with libprotobuf v2.X and
// v3.X with the same reader give equivalent in-memory events
//

#include "HepMC3/Readerprotobuf.h"

#include "HepMC3/Print.h"

#include <cassert>

int main() {
  HepMC3::Readerprotobuf rdr2("inputIO22_libprotobuf2.proto");
  HepMC3::Readerprotobuf rdr3("inputIO22_libprotobuf3.proto");

  HepMC3::GenEvent evt2;
  HepMC3::GenEvent evt3;

  rdr2.read_event(evt2);
  rdr3.read_event(evt3);

  std::stringstream ss1("");
  std::stringstream ss2("");
  HepMC3::Print::listing(ss1, evt2.run_info());
  HepMC3::Print::listing(ss2, evt3.run_info());
  std::cout << ss1.str() << "\n" << ss2.str() << std::endl;
  assert(ss1.str() == ss2.str());

  ss1.str("");
  ss2.str("");
  HepMC3::Print::content(ss1, evt2);
  HepMC3::Print::content(ss2, evt3);
  std::cout << ss1.str() << "\n" << ss2.str() << std::endl;
  assert(ss1.str() == ss2.str());

  rdr2.close();
  rdr3.close();

  exit(0);
}
