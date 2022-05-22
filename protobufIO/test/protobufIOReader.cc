#include "HepMC3/Readerprotobuf.h"

#include "HepMC3/Print.h"

int main(int argc, char * const argv[]) {
  HepMC3::Readerprotobuf rdr(argv[1]);

  HepMC3::GenEvent ev;
  while(rdr.read_event(ev)){
    HepMC3::Print::listing(ev);
  }
}