// -- Purpose: Verifies search/Relatives functionality for locating related particles and vertices.
//
#include "HepMC3/GenEvent.h"
#include "HepMC3/GenParticle.h"
#include "HepMC3/GenVertex.h"
#include "HepMC3/WriterAscii.h"
#include "HepMC3/ReaderAscii.h"

std::shared_ptr<HepMC3::GenEvent> generate_event(const size_t n, const size_t iterations)
{
    auto e = std::make_shared<HepMC3::GenEvent>();
    HepMC3::GenVertexPtr v0 = std::make_shared<HepMC3::GenVertex>();
    e->add_vertex(v0);
    auto p1 = std::make_shared<HepMC3::GenParticle>();
    auto p2 = std::make_shared<HepMC3::GenParticle>();
    v0->add_particle_in(p1);
    v0->add_particle_in(p2);
    e->add_beam_particle(p1);    
    e->add_beam_particle(p2);    
    size_t it = 0;
    for (;;)
    {
        if (it>iterations)
        {
            for (const auto& v: e->vertices())
            {
                if (!v->particles_out().empty()) continue;
                for (size_t i = 0; i < n; i++) v->add_particle_out(std::make_shared<HepMC3::GenParticle>());
            }
            break;
        }
        auto vertices = e->vertices();
        for (const auto& v: vertices)
        {
            if (!v->particles_out().empty()) continue;
            for (size_t i = 0; i < n; i++) v->add_particle_out(std::make_shared<HepMC3::GenParticle>());
            for (const auto& p: v->particles_out())
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

int main() {
    auto evt = generate_event(2,1);
    auto vx1 = std::make_shared<HepMC3::GenVertex>();
    evt->add_vertex(vx1);
    vx1->add_particle_in(evt->particles().back());
    auto vx2 = std::make_shared<HepMC3::GenVertex>();
    evt->add_vertex(vx2);
    auto p = std::make_shared<HepMC3::GenParticle>();
    vx2->add_particle_out(p);
    
    for (size_t i = 0; i < 100000; ++i) 
    {
		auto part = std::make_shared<HepMC3::GenParticle>();
		vx1->add_particle_out(part);
		vx2->add_particle_in(part);
	}
    HepMC3::WriterAscii  outputA("testLargeVertex.hepmc");
    if(outputA.failed()) return 4;
    outputA.write_event(*evt);
    outputA.close();	
    HepMC3::ReaderAscii  inputA("testLargeVertex.hepmc");
    if(inputA.failed()) return 5;
    HepMC3::GenEvent event;
    inputA.read_event(event);
    inputA.close();
    return 0;
}
