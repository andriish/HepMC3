// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2023 The HepMC collaboration (see AUTHORS for details)
//
#include "HepMC3/Attribute.h"
#include "HepMC3/GenEvent.h"
#include "HepMC3/GenParticle.h"
#include "HepMC3/GenVertex.h"
#include "HepMC3/Relatives.h"
#include "HepMC3TestUtils.h"
#include <thread>
#include <random>
#include <iterator>
using namespace HepMC3;
const size_t NinputCopies=4;
std::shared_ptr<GenEvent> generate(const int Z) {
    std::shared_ptr<GenEvent> evt = std::make_shared<GenEvent>();
    std::shared_ptr<GenRunInfo> run = std::make_shared<GenRunInfo>();
    evt->set_run_info(run);
    GenParticlePtr b2 = std::make_shared<GenParticle>( FourVector( 0.0,    0.0,   7000.0,  7000.0  ),2212,  3 );
    GenParticlePtr b1 = std::make_shared<GenParticle>( FourVector( 0.750, -1.569,   32.191,  32.238),   1,  3 );
    GenParticlePtr b3 = std::make_shared<GenParticle>( FourVector( 0.750, -1.569,   32.191,  -32.238),   1,  3 );
    GenVertexPtr v1 = std::make_shared<GenVertex>();
    v1->add_particle_in (b1);
    v1->add_particle_in(b2);
    v1->add_particle_out(b3);
    evt->add_vertex(v1);
    for (int z = 0; z < Z; z++) {
        auto particles = evt->particles();
        for (auto p: particles) {
            if (p->end_vertex()) continue;
            GenParticlePtr p2 = std::make_shared<GenParticle>( FourVector( 0.0,    0.0,   7000.0+0.01*evt->particles().size(),  7000.0  ),2212,  3 );
            GenParticlePtr p1 = std::make_shared<GenParticle>( FourVector( 0.750, -1.569,   32.191+0.01*evt->particles().size(),  32.238),   1,  3 );
            GenVertexPtr v = std::make_shared<GenVertex>();
            v->add_particle_in (p);
            v->add_particle_out(p1);
            v->add_particle_out(p2);
            evt->add_vertex(v);
        }
    }
    return evt;
}

void attribute_function1(const std::vector<std::shared_ptr<GenEvent>>& evts, std::map<int,int>& res)
{
    for (size_t i = 0; i < evts.size(); i++) {
        res[evts.at(i)->event_number()] =
            (Relatives::DESCENDANTS(evts.at(i)->particles().at(2))).size();
    }
}

int main()
{
    std::vector<std::shared_ptr<GenEvent> > evts;
    for (int i=0; i < 20; i++) {
        evts.push_back(generate(5+i/3));
        evts.back()->set_event_number(i);
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::vector<std::vector<std::shared_ptr<GenEvent>>> thr_evts;
    for (size_t i=0; i<NinputCopies; i++) {
        thr_evts.emplace_back(evts);
        std::shuffle(thr_evts[i].begin(), thr_evts[i].end(), g);
    }
    std::vector<std::map<int,int>> res(NinputCopies);
    std::vector<std::thread> threads;


    for (size_t i = 0; i < NinputCopies; i++) {
        threads.emplace_back(std::thread(attribute_function1,std::cref(thr_evts[i]), std::ref(res[i])));
    }
    for (auto& th : threads) {th.join();}
    threads.clear();

    for (size_t k = 1; k < NinputCopies; k++)
    {
        if (!std::equal(res[k].begin(), res[k].end(), res[0].begin())) {
            return 1;
        };
    }
    return 0;
}
