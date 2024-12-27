// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2024 The HepMC collaboration (see AUTHORS for details)
//
// -- Purpose: Test deduce_reader reading from std::cin
//
#if defined(__linux__) || defined(__darwin__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__sun)
#include "HepMC3/GenEvent.h"
#include "HepMC3/ReaderFactory.h"
using namespace HepMC3;
int main() {
	std::shared_ptr<Reader>  input_file = deduce_reader(std::cin);
    while (!input_file->failed()) {
        GenEvent evt(Units::GEV, Units::MM);
        input_file->read_event(evt);
        if (input_file->failed()) {
            printf("End of file reached. Exit.\n");
            break;
        }
        evt.clear();
    }
    input_file->close();	
    return 0;
}
#else
int main() { return 0; }
#endif
