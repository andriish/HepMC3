#include "HepMC3/Writerprotobuf.h"

#include "HepMC3/GenEvent.h"
#include "HepMC3/GenParticle.h"
#include "HepMC3/GenRunInfo.h"
#include "HepMC3/GenVertex.h"
#include "HepMC3/Print.h"

int main(int argc, char *const argv[]) {

  // Create some four vectors for the electrons
  double ele_mass_sqr = 0.000511 * 0.000511;
  HepMC3::FourVector momentum_e1;
  HepMC3::FourVector momentum_e2;

  momentum_e1.setPz(-2);
  momentum_e2.setPz(3.5);

  momentum_e1.setE(
      std::sqrt(momentum_e1.pz() * momentum_e1.pz() + ele_mass_sqr));
  momentum_e2.setE(
      std::sqrt(momentum_e2.pz() * momentum_e2.pz() + ele_mass_sqr));

  HepMC3::FourVector momentum_tau1(+1.38605041e+00, +1.38605041e+00,
                                   +7.50000000e-01, +2.75000005e+00);
  HepMC3::FourVector momentum_tau2(-1.38605041e+00, -1.38605041e+00,
                                   +7.50000000e-01, +2.75000005e+00);
  // Although the code for HepMC2 would work (thanks to backward compatibility)
  // we don't want to use deprecated functions
  HepMC3::GenParticlePtr e1 =
      std::make_shared<HepMC3::GenParticle>(momentum_e1, -11, 2);
  HepMC3::GenParticlePtr e2 =
      std::make_shared<HepMC3::GenParticle>(momentum_e2, 11, 2);
  HepMC3::GenParticlePtr tau1 =
      std::make_shared<HepMC3::GenParticle>(momentum_tau1, -15, 1);
  HepMC3::GenParticlePtr tau2 =
      std::make_shared<HepMC3::GenParticle>(momentum_tau2, 15, 1);
  HepMC3::GenVertexPtr vertex = std::make_shared<HepMC3::GenVertex>();
  // Set masses
  e1->set_generated_mass(0.000511);
  e2->set_generated_mass(0.000511);
  tau1->set_generated_mass(1.777);
  tau2->set_generated_mass(1.777);

  // Make vertex
  vertex->add_particle_in(e1);
  vertex->add_particle_in(e2);
  vertex->add_particle_out(tau1);
  vertex->add_particle_out(tau2);

  HepMC3::GenEvent hepmc;

  hepmc.add_vertex(vertex);
  hepmc.weights() = std::vector<double>{1., 0., 2.};

  std::shared_ptr<HepMC3::GenRunInfo> gri(new HepMC3::GenRunInfo());
  HepMC3::GenRunInfo::ToolInfo ti;
  ti.name = "protobufdummy";
  ti.version = "0.0.1";
  ti.description = "dummy tool for testing protobufIO";
  gri->tools().push_back(ti);
  HepMC3::GenRunInfo::ToolInfo ti2;
  ti2.name = "protobufdummy2";
  ti2.version = "0.0.2";
  ti2.description = "other dummy tool for testing protobufIO";
  gri->tools().push_back(ti2);
  gri->set_weight_names({"weight1", "weight2", "weight3"});

  std::unique_ptr<HepMC3::Writerprotobuf> writer =
      std::make_unique<HepMC3::Writerprotobuf>(argv[1], gri);

  writer->write_event(hepmc);

  HepMC3::Print::listing(hepmc);
}