// -*- C++ -*-
#include "HepMC/GenEvent.h"
#include "HepMC/ReaderAscii.h"
#include "HepMC/WriterAscii.h"
#include "HepMC/ReaderAsciiHepMC2.h"
#include "HepMC/WriterAsciiHepMC2.h"
#include "HepMC3TestUtils.h"
#include <fstream>
#include <iostream>     // std::ios, std::istream, std::cout
#include <fstream>      // std::filebuf
int main()
{
	
	std::filebuf isrA; isrA.open("inputI05.hepmc",std::ios::in ); std::istream SisrA(&isrA);
    HepMC::ReaderAsciiHepMC2 inputA(SisrA);
    if(inputA.failed()) return 1;
    std::filebuf osrA; osrA.open("frominputI05.hepmc",std::ios::out);  std::ostream SosrA(&osrA);
    HepMC::WriterAscii       outputA(SosrA);
    if(outputA.failed()) return 2;
    while( !inputA.failed() )
        {
            HepMC::GenEvent evt(HepMC::Units::GEV,HepMC::Units::MM);
            inputA.read_event(evt);
            if( inputA.failed() )  {printf("End of file reached. Exit.\n"); break;}
            outputA.write_event(evt);
            evt.clear();
        }
    inputA.close();
    outputA.close();

    std::filebuf isrB; isrB.open("frominputI05.hepmc",ios_base::in ); std::istream SisrB(&isrB);
    HepMC::ReaderAscii inputB(SisrB);
    if(inputB.failed()) return 3;
     std::filebuf osrB; osrB.open ("fromfrominputI05.hepmc",ios_base::out );std::ostream SosrB(&osrB);
    HepMC::WriterAsciiHepMC2       outputB(SosrB);
    if(outputB.failed()) return 4;
    while( !inputB.failed() )
        {
            HepMC::GenEvent evt(HepMC::Units::GEV,HepMC::Units::MM);
            inputB.read_event(evt);
            if( inputB.failed() )  {printf("End of file reached. Exit.\n"); break;}
            outputB.write_event(evt);
            evt.clear();
        }
    inputB.close();
    outputB.close();
    return COMPARE_ASCII_FILES("fromfrominputI05.hepmc","inputI05.hepmc");
}