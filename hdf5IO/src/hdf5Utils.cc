// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2026 The HepMC collaboration (see AUTHORS for details)
//

#include "HepMC3/hdf5Utils.h"

namespace HepMC3 {
namespace HDF5Utils {

bool available() {
    return false;
}

std::string backend_name() {
    return "stub";
}

} // namespace HDF5Utils
} // namespace HepMC3
