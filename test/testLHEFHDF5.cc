#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "HepMC3/LHEF.h"
#include "HepMC3/LHEFHDF5.h"

static LHEF::HEPRUP createSampleHEPRUP() {
    LHEF::HEPRUP heprup;
    heprup.IDBMUP = {2212, 2212};
    heprup.EBMUP = {6500.0, 6500.0};
    heprup.PDFGUP = {0, 0};
    heprup.PDFSUP = {260000, 260000};
    heprup.IDWTUP = 3;
    heprup.NPRUP = 1;
    heprup.resize();
    heprup.XSECUP[0] = 100.0;
    heprup.XERRUP[0] = 2.5;
    heprup.XMAXUP[0] = 1.0;
    heprup.LPRUP[0] = 100;
    LHEF::WeightInfo w0;
    w0.name = "w0";
    heprup.weightinfo.push_back(w0);
    LHEF::WeightInfo w1;
    w1.name = "w1";
    heprup.weightinfo.push_back(w1);
    return heprup;
}

static LHEF::HEPEUP createSampleLHEEvent(const LHEF::HEPRUP &heprup, int event_number) {
    LHEF::HEPEUP hepeup;
    hepeup.heprup = const_cast<LHEF::HEPRUP*>(&heprup);
    hepeup.NUP = 4;
    hepeup.IDPRUP = 100;
    hepeup.XWGTUP = 1.25 + 0.1 * event_number;
    hepeup.SCALUP = 91.188;
    hepeup.AQEDUP = 0.00729735;
    hepeup.AQCDUP = 0.118;
    hepeup.ntries = 1;

    hepeup.resize();
    hepeup.IDUP = {2212, 2212, 11, -11};
    hepeup.ISTUP = {-1, -1, 1, 1};
    hepeup.MOTHUP = {{0, 0}, {0, 0}, {1, 2}, {1, 2}};
    hepeup.ICOLUP = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
    hepeup.PUP = {
        {0.0, 0.0, 6500.0, 6500.0, 0.938},
        {0.0, 0.0, -6500.0, 6500.0, 0.938},
        {10.0, 20.0, 30.0, 50.0, 0.000511},
        {-10.0, -20.0, -30.0, 50.0, 0.000511}
    };
    hepeup.VTIMUP = {0.0, 0.0, 0.0, 0.0};
    hepeup.SPINUP = {9.0, 9.0, 9.0, 9.0};
    hepeup.weights = {
        {1.25 + 0.1 * event_number, &heprup.weightinfo[0]},
        {0.75, &heprup.weightinfo[1]}
    };
    return hepeup;
}

int main() {
    LHEF::HEPRUP heprup = createSampleHEPRUP();

    LHEFHDF5::Writer writer("lhe_event.h5", heprup);
    writer.init();

    for (int i = 0; i < 5; ++i) {
        writer.hepeup = createSampleLHEEvent(heprup, i + 1);
        writer.writeEvent();
        if (writer.failed()) {
            std::cerr << "Failed to write LHE HDF5 event " << i << "\n";
            return 1;
        }
    }
    writer.close();

    LHEFHDF5::Reader reader("lhe_event.h5");
    if (reader.failed()) {
        std::cerr << "Failed to open LHE HDF5 file for reading\n";
        return 1;
    }

    std::cout << "HEPRUP NPRUP = " << reader.heprup.NPRUP << "\n";
    std::cout << "HEPRUP EBMUP = " << reader.heprup.EBMUP.first << ", " << reader.heprup.EBMUP.second << "\n";

    int count = 0;
    while (reader.readEvent()) {
        std::cout << "Read event IDPRUP = " << reader.hepeup.IDPRUP
                  << ", NUP = " << reader.hepeup.NUP
                  << ", XWGTUP = " << reader.hepeup.XWGTUP << "\n";
        for (int p = 0; p < reader.hepeup.NUP; ++p) {
            std::cout << "  Particle " << p << ": ID=" << reader.hepeup.IDUP[p]
                      << " ST=" << reader.hepeup.ISTUP[p]
                      << " P=(" << reader.hepeup.PUP[p][0] << ", " << reader.hepeup.PUP[p][1]
                      << ", " << reader.hepeup.PUP[p][2] << ", " << reader.hepeup.PUP[p][3] << ")\n";
        }
        count++;
    }
    if (count != 5) {
        std::cerr << "Expected 5 events, read " << count << "\n";
        return 1;
    }

    reader.close();
    return 0;
}
