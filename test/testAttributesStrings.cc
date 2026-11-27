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
    std::string foo;
    VectorStringAttribute vsa;
    vsa.from_string(foo);
    
    return 0;
}
