#include "HepMC3/ReaderFactory.h"

#include "HepMC3/Print.h"

int main(int argc, char * const argv[]) {
  std::shared_ptr<HepMC3::Reader> rdr = HepMC3::deduce_reader(argv[1]);

  HepMC3::GenEvent ev;
  while(rdr->read_event(ev)){
    HepMC3::Print::listing(ev);
  }
}