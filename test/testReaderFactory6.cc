// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2026 The HepMC collaboration (see AUTHORS for details)
//
// -- Purpose: Verifies deducing reader for nonexisting remote file
//
#include "HepMC3/GenEvent.h"
#include "HepMC3/ReaderFactory.h"
using namespace HepMC3;
int main()
{
    auto input = deduce_reader("root://nonexistingurl.root");
    if (!input) return 0;
    return 1;
}
