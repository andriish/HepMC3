set(TEST_TAUOLAPP_ROOT_DIR  "" ${TAUOLAPP_ROOT_DIR})
IF(TEST_TAUOLAPP_ROOT_DIR STREQUAL "")
  IF(DEFINED ENV{TAUOLAPP_ROOT_DIR})
    set(TAUOLAPP_ROOT_DIR  $ENV{TAUOLAPP_ROOT_DIR})
  else()
    set(TAUOLAPP_ROOT_DIR  "/usr")
   endif()
endif()
set(TAUOLAPP_VERSION 0.0.0)
find_path(TAUOLAPP_INCLUDE_DIR Tauola/Tauola.h HINTS $ENV{TAUOLAPP_ROOT_DIR}/include ${TAUOLAPP_ROOT_DIR}/include)
if (TAUOLAPP_INCLUDE_DIR)
  if (EXISTS ${TAUOLAPP_INCLUDE_DIR}/Tauola/Version.h)
    file(STRINGS ${TAUOLAPP_INCLUDE_DIR}/Tauola/Version.h TAUOLA_VERSION_STRING_CONTENT REGEX "^#define[ ]+TAUOLA_VERSION[ ]+\"")
    string(REGEX MATCH "[1234567890\.]+[a-zA-Z]*" TAUOLAPP_VERSION ${TAUOLA_VERSION_STRING_CONTENT})
  endif()
endif()

find_library(TAUOLAPP_CxxInterface_LIBRARY NAMES TauolaCxxInterface
             HINTS $ENV{TAUOLAPP_ROOT_DIR}/lib ${TAUOLAPP_ROOT_DIR}/lib
             HINTS $ENV{TAUOLAPP_ROOT_DIR}/lib64 ${TAUOLAPP_ROOT_DIR}/lib64
             )

find_library(TAUOLAPP_Fortran_LIBRARY NAMES TauolaFortran
             HINTS $ENV{TAUOLAPP_ROOT_DIR}/lib ${TAUOLAPP_ROOT_DIR}/lib
             HINTS $ENV{TAUOLAPP_ROOT_DIR}/lib64 ${TAUOLAPP_ROOT_DIR}/lib64
             )


find_library(TAUOLAPP_HepMC_LIBRARY NAMES TauolaHepMC
             HINTS $ENV{TAUOLAPP_ROOT_DIR}/lib ${TAUOLAPP_ROOT_DIR}/lib
             HINTS $ENV{TAUOLAPP_ROOT_DIR}/lib64 ${TAUOLAPP_ROOT_DIR}/lib64
             )

find_library(TAUOLAPP_HepMC3_LIBRARY NAMES TauolaHepMC3
             HINTS $ENV{TAUOLAPP_ROOT_DIR}/lib ${TAUOLAPP_ROOT_DIR}/lib
             HINTS $ENV{TAUOLAPP_ROOT_DIR}/lib64 ${TAUOLAPP_ROOT_DIR}/lib64
             )

find_library(TAUOLAPP_HEPEVT_LIBRARY NAMES TauolaHEPEVT
             HINTS $ENV{TAUOLAPP_ROOT_DIR}/lib ${TAUOLAPP_ROOT_DIR}/lib
             HINTS $ENV{TAUOLAPP_ROOT_DIR}/lib64 ${TAUOLAPP_ROOT_DIR}/lib64
             )

set(TAUOLAPP_INCLUDE_DIRS ${TAUOLAPP_INCLUDE_DIR})
if (TAUOLAPP_CxxInterface_LIBRARY AND  TAUOLAPP_Fortran_LIBRARY)
    set(TAUOLAPP_LIBRARIES ${TAUOLAPP_CxxInterface_LIBRARY} ${TAUOLAPP_Fortran_LIBRARY})
endif()

if (TAUOLAPP_HepMC3_LIBRARY)
    set(TAUOLAPP_HEPMC3_LIBRARIES  ${TAUOLAPP_HepMC3_LIBRARY})
    set(Tauolapp_HEPMC3_FOUND TRUE)
endif()
if (TAUOLAPP_HepMC_LIBRARY)
    set(TAUOLAPP_HEPMC2_LIBRARIES  ${TAUOLAPP_HepMC_LIBRARY})
    set(Tauolapp_HEPMC2_FOUND TRUE)
endif()
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(Tauolapp REQUIRED_VARS TAUOLAPP_INCLUDE_DIR TAUOLAPP_LIBRARIES TAUOLAPP_VERSION HANDLE_COMPONENTS )

mark_as_advanced(Tauolapp_FOUND TAUOLAPP_INCLUDE_DIR TAUOLAPP_INCLUDE_DIRS TAUOLAPP_LIBRARIES)
