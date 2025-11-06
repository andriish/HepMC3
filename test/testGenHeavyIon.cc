// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2025 The HepMC collaboration (see AUTHORS for details)
//
#include "HepMC3/GenHeavyIon.h"
#include "HepMC3TestUtils.h"
using namespace HepMC3;
int main() {
    auto HI1 = std::make_shared<GenHeavyIon>();
    std::string S1;
    HI1->to_string(S1);
    auto HI2 = std::make_shared<GenHeavyIon>();
    std::string S2;
    HI2->from_string(S1);
    HI2->to_string(S2);
    return (S1 != S2);
}
