// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2025 The HepMC collaboration (see AUTHORS for details)
//
/**
 *  @file GenHeavyIon.cc
 *  @brief Implementation of \b class GenHeavyIon
 *
 */
#include <cstdio> // sprintf
#include <cstdlib> // atoi
#include <cstring> // memcmp
#include <sstream> // sprintf

#include "HepMC3/GenHeavyIon.h"

namespace HepMC3 {

bool GenHeavyIon::from_string(const std::string &att) {

    std::istringstream is(att);
    std::string version;

    is >> version >> Ncoll_hard >> Npart_proj >> Npart_targ >> Ncoll
       >> N_Nwounded_collisions >> Nwounded_N_collisions
       >> Nwounded_Nwounded_collisions >> impact_parameter
       >> event_plane_angle >> sigma_inel_NN >> centrality
       >> user_cent_estimate >> Nspec_proj_n >> Nspec_targ_n
       >> Nspec_proj_p >> Nspec_targ_p;

    int N=0;
    int ord=0;
    is >> N;
    for ( int i = 0; i < N; ++i ) {
        is >> ord;
        is >> participant_plane_angles[ord];
    }
    is >> N;
    for ( int i = 0; i < N; ++i ) {
        is >> ord;
        is >> eccentricities[ord];
    }

    return !is.fail();
}

bool GenHeavyIon::to_string(std::string &att) const {
    std::ostringstream os;
    std::string version;

    os << "v1 ";
    os << std::setprecision(8)
       << Ncoll_hard << " " << Npart_proj << " "
       << Npart_targ << " " << Ncoll << " ";    
    os << N_Nwounded_collisions << " " << Nwounded_N_collisions << " "
       << Nwounded_Nwounded_collisions << " " << impact_parameter << " "
       << event_plane_angle << " ";
    os << sigma_inel_NN << " " << centrality << " ";
    os << user_cent_estimate << " ";
    os << Nspec_proj_n << " " << Nspec_targ_n << " "
       << Nspec_proj_p << " " << Nspec_targ_p << " ";

    os << participant_plane_angles.size();
    for (const auto& it: participant_plane_angles) {
        os << " " << it.first << " " << it.second;
    }
    os << " " << eccentricities.size();
    for (const auto& it: eccentricities) {
        os << " " << it.first << " " << it.second;
    }
    att = os.str();

    return true;
}

} // namespace HepMC3
