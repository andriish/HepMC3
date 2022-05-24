#include "HepMC3/ReaderFactory.h"

#include "HepMC3/Print.h"

int main(int argc, char *const argv[]) {
  std::shared_ptr<HepMC3::Reader> rdr = HepMC3::deduce_reader(argv[1]);

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
}