// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2026 The HepMC collaboration (see AUTHORS for details)
//
// -- Purpose: Verifies attribute handling and serialization.
//
#include "HepMC3/GenEvent.h"
#include "HepMC3/GenVertex.h"
#include "HepMC3/GenParticle.h"
using namespace HepMC3;

int main()
{
VectorDoubleAttribute vlda_orig({-000000000001,0000000000.1,-0000000001,00000000.1,0,1,-1,100000,-100000,100000000000,100000000000});
std::string storage;
vlda_orig.to_string(storage);
VectorDoubleAttribute vlda;
vlda.from_string(storage);
if (! (vlda.value()==vlda_orig.value()) ) return 1;

    return 0;
}
