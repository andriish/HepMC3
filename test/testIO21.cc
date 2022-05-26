// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2022 The HepMC collaboration (see AUTHORS for details)
//
// -- Purpose: Test that we can read a file produced with libprotobuf v2.X and
// v3.X with the same reader
//

#include "HepMC3/Readerprotobuf.h"

#include <cassert>

int main() {
  HepMC3::Readerprotobuf rdr2("inputIO21_libprotobuf2.proto");
  std::cout << "File inputIO21_libprotobuf2.proto was written by libprotobuf v"
            << rdr2.file_header().protobuf_version_maj << "."
            << rdr2.file_header().protobuf_version_min << "."
            << rdr2.file_header().protobuf_version_patch << std::endl;
  assert(rdr2.file_header().protobuf_version_maj == 2);
  rdr2.close();

  HepMC3::Readerprotobuf rdr3("inputIO21_libprotobuf3.proto");
  std::cout << "File inputIO21_libprotobuf3.proto was written by libprotobuf v"
            << rdr3.file_header().protobuf_version_maj << "."
            << rdr3.file_header().protobuf_version_min << "."
            << rdr3.file_header().protobuf_version_patch << std::endl;
  assert(rdr3.file_header().protobuf_version_maj == 3);
  rdr3.close();

  exit(0);
}
