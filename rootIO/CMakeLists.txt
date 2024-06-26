
include_directories(${PROJECT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR})

if (MSVC)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/outputs/${CMAKE_INSTALL_LIBDIR})
else()
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/outputs/${CMAKE_INSTALL_LIBDIR})
endif()
ROOT_GENERATE_DICTIONARY(G__HepMC3rootIO include/rootIO_Classes.hh LINKDEF include/LinkDef.hh NOINSTALL OPTIONS -inlineInputHeader)
set_source_files_properties(G__HepMC3rootIO.cxx PROPERTIES SKIP_LINTING ON)
add_library(HepMC3rootIO SHARED ${PROJECT_SOURCE_DIR}/rootIO/src/WriterRoot.cc ${PROJECT_SOURCE_DIR}/rootIO/src/ReaderRoot.cc ${PROJECT_SOURCE_DIR}/rootIO/src/WriterRootTree.cc ${PROJECT_SOURCE_DIR}/rootIO/src/ReaderRootTree.cc ${PROJECT_SOURCE_DIR}/rootIO/src/Streamers.cc G__HepMC3rootIO.cxx)
set_property(TARGET HepMC3rootIO PROPERTY POSITION_INDEPENDENT_CODE 1)

target_link_libraries(HepMC3rootIO ROOT::Tree ROOT::RIO ROOT::Core HepMC3::HepMC3)

target_include_directories(HepMC3rootIO PUBLIC
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  ${ROOT_INCLUDE_DIRS})

set_target_properties(HepMC3rootIO PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/outputs/${CMAKE_INSTALL_LIBDIR}/$<0:>
  EXPORT_NAME HepMC3::rootIO)
if (MSVC)
  set_target_properties(HepMC3rootIO PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/outputs/${CMAKE_INSTALL_LIBDIR}/$<0:>)
endif()
set_target_properties(HepMC3rootIO PROPERTIES SOVERSION 3)
# installs
install(TARGETS HepMC3rootIO
  EXPORT HepMC3rootIOTargets
  DESTINATION ${HEPMC3_ROOTIO_INSTALL_LIBDIR}
  COMPONENT rootIOlibs)
install(DIRECTORY ${PROJECT_BINARY_DIR}/outputs/${CMAKE_INSTALL_LIBDIR}/ DESTINATION  ${HEPMC3_ROOTIO_INSTALL_LIBDIR}  COMPONENT rootIOlibs  FILES_MATCHING  PATTERN "*.pcm"  PATTERN "*.rootmap" PATTERN "CMakeFiles" EXCLUDE   PATTERN "src" EXCLUDE  PATTERN "include" EXCLUDE)
install(DIRECTORY include/HepMC3 DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} COMPONENT rootIOdevel)

# Alias for packages that include this as a sub-project but
# want to use the namespaced target names
add_library(HepMC3::rootIO ALIAS HepMC3rootIO)

set(CONFIG_INSTALL_DIR ${CMAKE_INSTALL_DATADIR}/HepMC3/cmake)
install(EXPORT HepMC3rootIOTargets
  DESTINATION ${CONFIG_INSTALL_DIR}
  COMPONENT rootIOdevel)
