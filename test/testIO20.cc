#include "HepMC3/ReaderFactory.h"

#include "HepMC3/Print.h"

int main() {
  std::shared_ptr<HepMC3::Reader> rdr = HepMC3::deduce_reader("inputIO20.proto");

  HepMC3::GenEvent ev;
  // for some readers we have to try and read an event first
  rdr->read_event(ev);

  if (ev.run_info()) {
    HepMC3::Print::listing(*ev.run_info());
  } else {
    std::cout << "No run info." << std::endl;
  }

  HepMC3::Print::listing(ev);
  size_t ctr = 1;

  while(rdr->read_event(ev) && (ctr++ < 25) ){
    HepMC3::Print::listing(ev);
  }
  exit(0);
}
