# -*- CMake -*-
# hdf5IO stub support for HepMC3

set(HepMC3hdf5IO_sources
  src/ReaderHDF5.cc
  src/WriterHDF5.cc
  src/hdf5Utils.cc
)

add_library(HepMC3hdf5IO SHARED ${HepMC3hdf5IO_sources})

target_include_directories(HepMC3hdf5IO PUBLIC
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

target_link_libraries(HepMC3hdf5IO PUBLIC HepMC3::HepMC3)

set_target_properties(HepMC3hdf5IO PROPERTIES
  SOVERSION 1
  ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/outputs/${CMAKE_INSTALL_LIBDIR}/$<0:>
  LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/outputs/${CMAKE_INSTALL_LIBDIR}/$<0:>
  RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/outputs/${CMAKE_INSTALL_LIBDIR}/$<0:>
  EXPORT_NAME HepMC3::hdf5IO)

install(TARGETS HepMC3hdf5IO
  EXPORT HepMC3hdf5IOTargets
  DESTINATION ${CMAKE_INSTALL_LIBDIR}
  COMPONENT hdf5IOlibs)

add_library(HepMC3::hdf5IO ALIAS HepMC3hdf5IO)

install(FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/include/HepMC3/ReaderHDF5.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/HepMC3/WriterHDF5.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/HepMC3/hdf5Utils.h
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/HepMC3
  COMPONENT hdf5IOdevel)

if (HEPMC3_BUILD_STATIC_LIBS)
  add_library(HepMC3hdf5IO_static STATIC ${HepMC3hdf5IO_sources})
  target_compile_definitions(HepMC3hdf5IO_static PRIVATE HEPMC3_NO_EXPORTS)
  target_include_directories(HepMC3hdf5IO_static PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
  target_link_libraries(HepMC3hdf5IO_static PUBLIC HepMC3::HepMC3)
  set_target_properties(HepMC3hdf5IO_static PROPERTIES
    OUTPUT_NAME HepMC3hdf5IO-static
    ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/outputs/${CMAKE_INSTALL_LIBDIR}/$<0:>
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/outputs/${CMAKE_INSTALL_LIBDIR}/$<0:>
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/outputs/${CMAKE_INSTALL_LIBDIR}/$<0:>
    EXPORT_NAME HepMC3::hdf5IO_static)

  install(TARGETS HepMC3hdf5IO_static
    EXPORT HepMC3hdf5IOTargets
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
    COMPONENT hdf5IOlibs)

  add_library(HepMC3::hdf5IO_static ALIAS HepMC3hdf5IO_static)
endif()

set(CONFIG_INSTALL_DIR ${CMAKE_INSTALL_DATADIR}/HepMC3/cmake)
install(EXPORT HepMC3hdf5IOTargets
  DESTINATION ${CONFIG_INSTALL_DIR}
  COMPONENT hdf5IOlibs)
