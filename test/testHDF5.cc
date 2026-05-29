// g++ -std=c++17 -I/path/to/highfive/include -lhdf5 main.cpp -o main

#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "HepMC3/GenEvent.h"
#include "HepMC3/GenParticle.h"
#include "HepMC3/GenVertex.h"
#include "HepMC3/GenRunInfo.h"
#include "HepMC3/ReaderHDF5.h"
#include "HepMC3/WriterHDF5.h"

using namespace HepMC3;

static GenEvent createSampleEvent(int event_number) {
    GenEvent evt(Units::MomentumUnit::GEV, Units::LengthUnit::MM);
    evt.set_event_number(event_number);
    evt.shift_position_to(FourVector{0.1, 0.2, 0.3, 1.0});

    auto p1 = std::make_shared<GenParticle>(FourVector{1.0, 0.0, 0.0, 1.0}, 11, 1);
    p1->set_generated_mass(0.000511);
    auto p2 = std::make_shared<GenParticle>(FourVector{-1.0, 0.0, 0.0, 1.0}, -11, 1);
    p2->set_generated_mass(0.000511);

    auto v1 = std::make_shared<GenVertex>(FourVector{0.0, 0.0, 0.0, 0.0});
    v1->set_status(0);
    v1->add_particle_out(p1);
    v1->add_particle_out(p2);
    evt.add_vertex(v1);

    evt.weights() = {1.0, 0.5};

    auto run = std::make_shared<GenRunInfo>();
    run->set_weight_names({"w0", "w1"});
    evt.set_run_info(run);

    return evt;
}

int main() {
    WriterHDF5 output("event.h5");
    for (int i = 0; i < 10; ++i) {
        GenEvent evt = createSampleEvent(i + 1);
        output.write_event(evt);
        if (output.failed()) {
            std::cerr << "Failed to write HDF5 event " << i << "\n";
            return 1;
        }
    }

    ReaderHDF5 input("event.h5");
    for (int i = 0; i < 10; ++i) {
        GenEvent evt2(Units::MomentumUnit::GEV, Units::LengthUnit::MM);
        if (!input.read_event(evt2) || input.failed()) {
            std::cerr << "Failed to read HDF5 event " << i << "\n";
            return 1;
        }

        std::cout << "Read event_number = " << evt2.event_number() << "\n";
        std::cout << "Particles: " << evt2.particles().size() << "\n";
        std::cout << "Vertices: " << evt2.vertices().size() << "\n";
        std::cout << "Weights: " << evt2.weights().size() << "\n";
        std::cout << "Attributes: " << evt2.attribute_names().size() << "\n";
        std::cout << "Run weight names: ";
        if (evt2.run_info()) {
            for (const auto &name : evt2.run_info()->weight_names()) std::cout << name << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
