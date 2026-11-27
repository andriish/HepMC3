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
    VectorLongDoubleAttribute vlda_orig({-0.00000000001,0.0000000001,-0.000000001,0.00000001,0,1,-1,100000,-100000,100000000000,100000000000});
    std::string storage_vlda;
    vlda_orig.to_string(storage_vlda);
    VectorLongDoubleAttribute vlda;
    vlda.from_string(storage_vlda);
    if (! (vlda.value()==vlda_orig.value()) ) return 1;


    VectorDoubleAttribute vda_orig({-0.00000000001,0.0000000001,-0.000000001,0.00000001,0,1,-1,100000,-100000,100000000000,100000000000});
    std::string storage_vda;
    vda_orig.to_string(storage_vda);
    VectorDoubleAttribute vda;
    vda.from_string(storage_vda);
    if (! (vda.value()==vda_orig.value()) ) return 2;


    VectorFloatAttribute vfa_orig({-0.00000000001,0.0000000001,-0.000000001,0.00000001,0,1,-1,100000,-100000});
    std::string storage_vfa;
    vfa_orig.to_string(storage_vfa);
    VectorFloatAttribute vfa;
    vfa.from_string(storage_vfa);
    if (! (vfa.value()==vfa_orig.value()) ) return 3;

    return 0;
}
