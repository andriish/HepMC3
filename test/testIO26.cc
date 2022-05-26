// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2022 The HepMC collaboration (see AUTHORS for details)
//
// -- Purpose: Test graceful failure from reading non-existant file
//

#include "HepMC3/Readerprotobuf.h"

#include <cassert>

int main() {
  HepMC3::Readerprotobuf rdr("nonexistant.proto");
  assert(rdr.failed());
  exit(0);
}
