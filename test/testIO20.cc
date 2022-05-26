// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2022 The HepMC collaboration (see AUTHORS for details)
//
// -- Purpose: Test that we can correctly deduce the reader type when passed a
// binary protobuf file
//

// These are the only headers in ReaderPlugin, so including these firstmakes
// sure the hack below doesn't leak out of the ReaderPlugin header
#include "HepMC3/GenEvent.h"
#include "HepMC3/Reader.h"

#define private public
#include "HepMC3/ReaderPlugin.h"
#undef private

#include "HepMC3/ReaderFactory.h"

#include "HepMC3/Print.h"

#include "HepMC3/Readerprotobuf.h"

#include <cassert>

int main() {
  std::shared_ptr<HepMC3::Reader> rdr =
      HepMC3::deduce_reader("inputIO20.proto");

  // make sure that we made a reader
  assert(rdr);
  // make sure that it is a plugin reader
  assert(dynamic_cast<HepMC3::ReaderPlugin *>(rdr.get()));
  // make sure that it was deduced correctly
  assert(dynamic_cast<HepMC3::Readerprotobuf *>(
      dynamic_cast<HepMC3::ReaderPlugin *>(rdr.get())->m_reader));

  rdr->close();

  exit(0);
}
