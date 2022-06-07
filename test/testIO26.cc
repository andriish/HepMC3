// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2019 The HepMC collaboration (see AUTHORS for details)
//
#include "HepMC3/GenEvent.h"
#include "HepMC3/Print.h"
#include "HepMC3/ReaderAscii.h"
#include "HepMC3/ReaderAsciiHepMC2.h"
#include "HepMC3/Readerprotobuf.h"
#include "HepMC3/WriterAscii.h"
#include "HepMC3/WriterAsciiHepMC2.h"
#include "HepMC3/Writerprotobuf.h"

using namespace HepMC3;
int main() {
  Readerprotobuf inputA("inputIO26.proto");
  if (inputA.failed()) {
    return 1;
  }
  std::stringstream ss("");
  WriterAscii outputA(ss);
  if (outputA.failed()) {
    return 2;
  }

  size_t evs_in_proto = 0;
  GenEvent evt_in_proto(Units::GEV, Units::MM);
  while (!inputA.failed()) {
    evt_in_proto.clear();
    evs_in_proto += inputA.read_event(evt_in_proto);
    std::cout << "Read event from proto \n";
    HepMC3::Print::listing(std::cout, evt_in_proto);
    if (inputA.failed()) {
      printf("End of file reached. Exit.\n");
      break;
    }
    outputA.write_event(evt_in_proto);
  }
  inputA.close();
  outputA.close();

  ReaderAscii inputB(ss);
  if (inputB.failed()) {
    return 3;
  }

  size_t evs_in_ASCII = 0;
  GenEvent evt_in_ASCII(Units::GEV, Units::MM);
  while (!inputB.failed()) {
    evt_in_ASCII.clear();
    evs_in_ASCII += inputB.read_event(evt_in_ASCII);
    std::cout << "Read event from ASCII \n";
    HepMC3::Print::listing(std::cout, evt_in_ASCII);
    if (inputB.failed()) {
      printf("End of file reached. Exit.\n");
      break;
    }
  }

  if (evs_in_proto != evs_in_ASCII) {
    printf("Events read in from inputIO26.proto: %d, events read from ASCII "
           "conversion: %d\n",
           evs_in_proto, evs_in_ASCII);
    return 4;
  }

  std::stringstream ss1("");
  std::stringstream ss2("");
  HepMC3::Print::listing(ss1, *evt_in_proto.run_info());
  HepMC3::Print::listing(ss2, *evt_in_ASCII.run_info());

  std::cout << ss1.str() << "\n" << ss2.str() << std::endl;
  if (ss1.str() != ss2.str()) {
    return 5;
  }

  ss1.str("");
  ss2.str("");
  HepMC3::Print::content(ss1, evt_in_proto);
  HepMC3::Print::content(ss2, evt_in_ASCII);
  std::cout << ss1.str() << "\n" << ss2.str() << std::endl;
  if (ss1.str() != ss2.str()) {
    return 6;
  }

  exit(0);
}
