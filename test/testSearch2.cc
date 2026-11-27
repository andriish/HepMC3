// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2026 The HepMC collaboration (see AUTHORS for details)
//
// -- Purpose: Verifies that search functions do not fail on null pointer.
//

#include "HepMC3/GenEvent.h"
#include "HepMC3/GenParticle.h"
#include "HepMC3/GenVertex.h"
#include "HepMC3/Relatives.h"
int main() {
    std::shared_ptr<HepMC3::GenParticle> p =  nullptr;
    std::shared_ptr<HepMC3::GenVertex> v =  nullptr;
    auto p_ANCESTORS = HepMC3::Relatives::ANCESTORS(p);
    auto p_DESCENDANTS = HepMC3::Relatives::DESCENDANTS(p);
    auto p_CHILDREN = HepMC3::Relatives::CHILDREN(p);
    auto p_PARENTS = HepMC3::Relatives::PARENTS(p);
    auto v_ANCESTORS = HepMC3::Relatives::ANCESTORS(v);
    auto v_DESCENDANTS = HepMC3::Relatives::DESCENDANTS(v);
    auto v_CHILDREN = HepMC3::Relatives::CHILDREN(v);
    auto v_PARENTS = HepMC3::Relatives::PARENTS(v);
    return 0;
}
