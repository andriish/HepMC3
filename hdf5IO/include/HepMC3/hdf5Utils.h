// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2026 The HepMC collaboration (see AUTHORS for details)
//
#ifndef HEPMC3_HDF5UTILS_H
#define HEPMC3_HDF5UTILS_H

#include <cstdint>
#include <string>
#include <vector>
#include "HepMC3/highfive/H5File.hpp"

#include "HepMC3/FourVector.h"
#include "HepMC3/Data/GenParticleData.h"
#include "HepMC3/Data/GenVertexData.h"
#include "HepMC3/Data/GenRunInfoData.h"

namespace HepMC3 {

/// @brief HDF5 utility helper functions.
namespace HDF5Utils {

struct H5FourVector {
    double x, y, z, t;
};

struct H5Particle {
    int pid;
    int status;
    uint8_t is_mass_set;
    double mass;
    H5FourVector momentum;
};

struct H5Vertex {
    int status;
    H5FourVector position;
};

inline HighFive::CompoundType createFourVectorType() {
    return HighFive::CompoundType{
        {"x", HighFive::AtomicType<double>{}},
        {"y", HighFive::AtomicType<double>{}},
        {"z", HighFive::AtomicType<double>{}},
        {"t", HighFive::AtomicType<double>{}}
    };
}

inline HighFive::CompoundType createParticleType() {
    return HighFive::CompoundType{
        {"pid",         HighFive::AtomicType<int>{}},
        {"status",      HighFive::AtomicType<int>{}},
        {"is_mass_set", HighFive::AtomicType<uint8_t>{}},
        {"mass",        HighFive::AtomicType<double>{}},
        {"momentum",    createFourVectorType()}
    };
}

inline HighFive::CompoundType createVertexType() {
    return HighFive::CompoundType{
        {"status",   HighFive::AtomicType<int>{}},
        {"position", createFourVectorType()}
    };
}

inline H5FourVector toH5(const FourVector& v) {
    return H5FourVector{v.x(), v.y(), v.z(), v.t()};
}

inline FourVector fromH5(const H5FourVector& v) {
    return FourVector{v.x, v.y, v.z, v.t};
}

inline H5Particle toH5(const GenParticleData& p) {
    return H5Particle{
        p.pid,
        p.status,
        static_cast<uint8_t>(p.is_mass_set ? 1 : 0),
        p.mass,
        toH5(p.momentum)
    };
}

inline GenParticleData fromH5(const H5Particle& p) {
    return GenParticleData{
        p.pid,
        p.status,
        p.is_mass_set != 0,
        p.mass,
        fromH5(p.momentum)
    };
}

inline H5Vertex toH5(const GenVertexData& v) {
    return H5Vertex{
        v.status,
        toH5(v.position)
    };
}

inline GenVertexData fromH5(const H5Vertex& v) {
    return GenVertexData{
        v.status,
        fromH5(v.position)
    };
}

} // namespace HDF5Utils

} // namespace HepMC3

#endif // HEPMC3_HDF5UTILS_H
