#include "HepMC3/GenEvent.h"
#include "HepMC3/ReaderFactory.h"
using namespace HepMC3;
int main(int argc, char* argv[])
{
    std::shared_ptr<Reader> inputA = deduce_reader("inputSherpa140Crash.hepmc");
    if (!inputA) return 1;

    int i = 0;

    while (true) {
        std::cout << "Reading event #" << (i+1) << " ..."  << std::endl;
        GenEvent evt;
        inputA->read_event(evt);
        if (inputA->failed()) {
            std::cout << "End of file reached, stop" << std::endl;
            break;
        }

        i += 1;
    }

    inputA->close();

    std::cout << "Total events read = " << i << std::endl;

    return 0;
}

