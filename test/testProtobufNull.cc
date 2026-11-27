// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2026 The HepMC collaboration (see AUTHORS for details)
//
// -- Purpose: Test that a protobuf input file w/o a header will fail
//

#include "HepMC3/Readerprotobuf.h"

#include "HepMC3/Print.h"

#include "HepMC3/GenEvent.h"
#include "HepMC3/GenParticle.h"
#include "HepMC3/GenRunInfo.h"
#include "HepMC3/GenVertex.h"

int main() {
    {
        std::array<std::uint8_t, 300> buffer = {{0x0A, 0x0B, 0x0C, 0x0D}};
        // Fill with some arbitrary binary data
        for (size_t i = 10; i < buffer.size(); ++i)
            buffer[i] = static_cast<std::uint8_t>(i + 5);
        std::ofstream file("ProtobufNull.proto", std::ios::binary);
        file.write(reinterpret_cast<const char*>(buffer.data()), buffer.size());
        file.close();
    }
    HepMC3::Readerprotobuf rdr("ProtobufNull.proto");
    if(rdr.failed()) return 0;
    HepMC3::GenEvent evt_in;
    rdr.read_event(evt_in);
    printf("Invalid event, failed=%i\n",rdr.failed());
    return 1;
}
