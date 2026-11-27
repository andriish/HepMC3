// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2023 The HepMC collaboration (see AUTHORS for details)
//
#include "HepMC3/GenVertex.h"
#include "HepMC3/GenParticle.h"
#include "HepMC3/GenEvent.h"
#include "HepMC3/ReaderAscii.h"
#include "HepMC3/WriterAsciiHepMC2.h"
#include <cassert>
//
// -- Purpose: Verifies that random states are serialized correctly
//
using namespace HepMC3;
std::shared_ptr<HepMC3::GenEvent> generate_event(const size_t  n,const  size_t  iterations)
{
    auto e = std::make_shared<HepMC3::GenEvent>();
    HepMC3::GenVertexPtr v0=std::make_shared<HepMC3::GenVertex>();
    e->add_vertex(v0);
    size_t it=0;
    for (;;)
    {
        if (it>iterations)
        {
            for (auto v: e->vertices())
            {
                if (!v->particles_out().empty()) continue;
                for (size_t i=0; i<n; i++) v->add_particle_out(std::make_shared<HepMC3::GenParticle>());
            }
            break;
        }
        auto vertices=e->vertices();
        for (auto v: vertices)
        {
            if (!v->particles_out().empty()) continue;
            for (size_t i=0; i<n; i++) v->add_particle_out(std::make_shared<HepMC3::GenParticle>());
            for (auto p: v->particles_out())
            {
                HepMC3::GenVertexPtr vx=std::make_shared<HepMC3::GenVertex>();
                vx->add_particle_in(p);
                e->add_vertex(vx);
            }
        }
        it++;
    }
    return e;
}
int main()
{
    auto event =  generate_event(2,2);
    std::vector<long> random_states_v {1000,999,500};
    std::shared_ptr<VectorLongIntAttribute> random_states_a = std::make_shared<VectorLongIntAttribute>(random_states_v);
    event->add_attribute("random_states", random_states_a);
    WriterAsciiHepMC2 outputA("testRandomStates.hepmc");
    if (outputA.failed()) return 2;
    auto event_get = event.get();
    outputA.write_event(*event_get);
    outputA.close();
    ReaderAscii inputA("testRandomStates.hepmc");
    if(inputA.failed()) return 3;
    GenEvent evt(Units::GEV,Units::MM);
    inputA.read_event(evt);
    inputA.close();
    auto from_file_a = evt.attribute<VectorLongIntAttribute>("random_states");
    auto from_file_v = from_file_a->value();
    if (random_states_v.size()!=from_file_v.size()) return 1;
    for (size_t i=0; i<random_states_v.size(); ++i) if (from_file_v.at(i) != random_states_v.at(i)) return 1;
    return 0;
}
