// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2026 The HepMC collaboration (see AUTHORS for details)
//
// -- Purpose: Verifies that  new search functions do not fail on null pointer.
//

#include "HepMC3/GenEvent.h"
#include "HepMC3/GenParticle.h"
#include "HepMC3/GenVertex.h"
#include "HepMC3/Relatives.h"
using namespace HepMC3;
int main() {
    HepMC3::GenParticlePtr p = nullptr;
    HepMC3::ConstGenParticlePtr cp = nullptr;
    HepMC3::GenVertexPtr v = nullptr;
    HepMC3::ConstGenVertexPtr cv = nullptr;
    {
        auto  GP = children_particles(v);      ///< Return children particles
    }
    {
        auto  CGP = children_particles(cv);    ///< Return children particles
    }
    {
        auto  VP = children_vertices(p);    ///< Return children vertices
    }
    {
        auto  CVP = children_vertices(cp);    ///< Return children vertices
    }
    {
        auto  GP = grandchildren_particles(p);     ///< Return grandchildren particles
    }
    {
        auto  CGP = grandchildren_particles(cp);     ///< Return grandchildren particles
    }
    {
        auto  VP = grandchildren_vertices(v);      ///< Return grandchildren vertices
    }
    {
        auto  CVP = grandchildren_vertices(cv);    ///< Return grandchildren vertices
    }
    {
        auto  GP = parent_particles(v);     ///< Return parent particles
    }
    {
        auto  CGP = parent_particles(cv);      ///< Return parent particles
    }
    {
        auto  VP = parent_vertices(p);      ///< Return parent vertices
    }
    {
        auto  CVP = parent_vertices(cp);       ///< Return parent vertices
    }
    {
        auto  GP = grandparent_particles(p);       ///< Return grandparent particles
    }
    {
        auto  CGP = grandparent_particles(cp);        ///< Return grandparent particles
    }
    {
        auto  VP = grandparent_vertices(v);         ///< Return grandparent vertices
    }
    {
        auto  CVP = grandparent_vertices(cv);          ///< Return grandparent vertices
    }
    {
        auto  CGP = descendant_particles(cv);          ///< Return descendant particles
    }
    {
        auto  GP = descendant_particles(v);          ///< Return descendant particles
    }
    {
        auto  CGP = descendant_particles(cp);          ///< Return descendant particles
    }
    {
        auto  GP = descendant_particles(p);          ///< Return descendant particles
    }
    {
        auto  CVP = descendant_vertices(cp);          ///< Return descendant vertices
    }
    {
        auto  VP = descendant_vertices(p);          ///< Return descendant vertices
    }
    {
        auto  CVP = descendant_vertices(cv);          ///< Return descendant vertices
    }
    {
        auto  VP = descendant_vertices(v);          ///< Return descendant vertices
    }
    {
        auto  CGP = ancestor_particles(cv);          ///< Return ancestor particles
    }
    {
        auto  GP = ancestor_particles(v);         ///< Return ancestor particles
    }
    {
        auto  CGP = ancestor_particles(cp);         ///< Return ancestor particles
    }
    {
        auto  GP = ancestor_particles(p);         ///< Return ancestor particles
    }
    {
        auto  CVP = ancestor_vertices(cp);         ///< Return ancestor vertices
    }
    {
        auto  VP = ancestor_vertices(p);         ///< Return ancestor vertices
    }
    {
        auto  CVP = ancestor_vertices(cv);         ///< Return ancestor vertices
    }
    {
        auto  VP = ancestor_vertices(v);         ///< Return ancestor vertices
    }
    return 0;
}
