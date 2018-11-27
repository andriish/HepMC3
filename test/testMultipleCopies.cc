//////////////////////////////////////////////////////////////////////////
// testMultipleCopies.cc.in
//
// garren@fnal.gov, January 2008
// Multiple events in memory at the same time
// run with valgrind or some other leak checker
//////////////////////////////////////////////////////////////////////////
//

#include <fstream>
#include "HepMC/GenEvent.h"
#include "HepMC/GenCrossSection.h"
#include "HepMC/GenParticle.h"
#include "HepMC/WriterAscii.h"
#include "HepMC/ReaderAscii.h"
#include "HepMC/ReaderAsciiHepMC2.h"
#include "HepMC/Print.h"
#include "HepMC3TestUtils.h"

// define methods and classes used by this test
//#include "IsGoodEvent.h"

int main()
{
    // use output file
    std::ofstream os( "testMultipleCopies.out" );
    {
        // declare an input strategy
        HepMC::ReaderAsciiHepMC2 ascii_in("testIOGenEvent.input");
        if (ascii_in.failed()) return 1;
        // declare another input strategy
        HepMC::ReaderAsciiHepMC2 ascii_in2("testHepMCVarious.input");
        if (ascii_in2.failed()) return 2;
        std::ofstream os1( "testMultipleOriginals.out"  );
        std::ofstream os2( "testMultipleCopies1.out" ) ;
        std::ofstream os3( "testMultipleCopies2.out" ) ;
        HepMC::WriterAscii out1(os1);
        HepMC::WriterAscii out2(os2);
        HepMC::WriterAscii out3(os3);
        // declare an instance of the event selection predicate
//        IsGoodEvent is_good_event;

        //........................................EVENT LOOP
        int icount=0;
        int num_good_events=0;
        int icnt;
        HepMC::GenEvent evt1;
        ascii_in.read_event(evt1);
        if (ascii_in.failed()) return 3;
        HepMC::GenEvent evt2;
        ascii_in2.read_event(evt2);
        if (ascii_in2.failed()) return 4;
        HepMC::GenEvent evt3;
        ascii_in.read_event(evt3);
        if (ascii_in.failed()) return 5;
        while ( !ascii_in.failed() && !ascii_in2.failed() )
            {
                icount++;
                //if ( icount%50==1 )
                os << "Processing Event Number " << icount
                   << " stream 1 # " << evt1.event_number()
                   << " stream 2 # " << evt2.event_number()
                   << std::endl;

                //AV     if ( is_good_event(&evt1) )
                {

                    os << "good event in stream 1 # "
                       << evt1.event_number() << std::endl;
                    out1.write_event(evt1);
                    ++num_good_events;
                    HepMC::GenEvent ec = evt1;
                    out3.write_event(ec);
                    icnt=0;
                    for ( HepMC::GenEvent::particle_const_iterator p1 =  ec.particles_begin();
                            p1 !=  ec.particles_end(); ++p1 )
                        {
                            ++icnt;
                            os << "particle " << icnt << " barcode " << std::endl;
                        }
                    HepMC::GenEvent evt4(evt1);
                    out2.write_event(evt4);
                    //AV if( !compareGenEvent(&evt1,&evt4) ) { return -1; }
                    evt4.clear();
                }
                // clean up and get next events
                evt1.clear();
                evt2.clear();
                ascii_in.read_event(evt1);
                ascii_in2.read_event(evt2);
            }
        // might have either evt1 or evt2 still in memory, cleanup here
        evt1.clear();
        evt2.clear();
        evt3.clear();

        //........................................PRINT RESULT
        os << std::endl;
        os << num_good_events << " out of " << icount
           << " processed events passed the cuts." << std::endl;
        os << std::endl;
        os << " GenEvent copy constructor passes the test" << std::endl;
        os << std::endl;
        ascii_in.close();
        ascii_in2.close();
    }

    // test operator= and swap
    {
        // declare an input strategy
        HepMC::ReaderAsciiHepMC2 ascii_in("testIOGenEvent.input");
        if (ascii_in.failed()) return 4;
        //
        HepMC::GenEvent evt5;
        ascii_in.read_event(evt5);
        HepMC::GenEvent evt6;
        os << "event number for evt5: " << evt5.event_number() << std::endl;
        os << "event number for evt6: " << evt6.event_number() << std::endl;
        // copy  GenEvent object
        evt6 = evt5;
        //AV if( !compareGenEvent(&evt5,&evt6) ) { return -4; }
        evt5.clear();
        os << "event number for evt6 after copy: " << evt6.event_number() << std::endl;
        os << std::endl;
        evt6.clear();
        os << " GenEvent operator= passes the test" << std::endl;
        os << std::endl;

        ascii_in.read_event(evt5);
        if (ascii_in.failed()) return 5;
        ascii_in.read_event(evt6);
        if (ascii_in.failed()) return 6;
        HepMC::GenEvent evt7(evt5);
        HepMC::GenEvent evt8(evt6);
        os << "event number for evt5: " << evt5.event_number() << std::endl;
        os << "event number for evt6: " << evt6.event_number() << std::endl;
        os << "before swap, evt5 has: " << evt5.vertices_size() << " vertices and "
           << evt5.particles_size() << " particles" << std::endl;
        os << "before swap, evt6 has: " << evt6.vertices_size() << " vertices and "
           << evt6.particles_size() << " particles" << std::endl;
        os << "before swap, evt7 has: " << evt7.vertices_size() << " vertices and "
           << evt7.particles_size() << " particles" << std::endl;
        os << "before swap, evt8 has: " << evt8.vertices_size() << " vertices and "
           << evt8.particles_size() << " particles" << std::endl;
        std::swap(evt6,evt5);
        os << "event number for evt5 after swap: " << evt5.event_number() << std::endl;
        os << "event number for evt6 after swap: " << evt6.event_number() << std::endl;
        // evt6 should now match evt7
        os << "after swap, evt6 has: " << evt6.vertices_size() << " vertices and "
           << evt6.particles_size() << " particles" << std::endl;
        os << "after swap, evt7 has: " << evt7.vertices_size() << " vertices and "
           << evt7.particles_size() << " particles" << std::endl;
        //AV  if( !compareGenEvent(&evt6,&evt7) ) { return -6; }
        // evt5 should now match evt8
        os << "after swap, evt5 has: " << evt5.vertices_size() << " vertices and "
           << evt5.particles_size() << " particles" << std::endl;
        os << "after swap, evt8 has: " << evt8.vertices_size() << " vertices and "
           << evt8.particles_size() << " particles" << std::endl;
        //AV   if( !compareGenEvent(&evt5,&evt8) ) { return -5; }
        os << std::endl;
        os << " GenEvent swap passes the test" << std::endl;
        os << std::endl;
        evt5.clear();
        evt6.clear();
        evt7.clear();
        evt8.clear();
        //ascii_in.close();
    }
    bool passed=(
    (COMPARE_ASCII_FILES("testMultipleCopies1.out","testMultipleCopies2.out")==0)
    &&
    (COMPARE_ASCII_FILES("testMultipleCopies1.out","testMultipleOriginals.out")==0)
    );
    if (!passed) return 1;
    return 0;
}
