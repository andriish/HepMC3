include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR})

ROOT_GENERATE_DICTIONARY(myclass_Classes include/myclass_Classes.h LINKDEF include/LinkDef.h OPTIONS -inlineInputHeader -DHEPMC3_ROOTIO)
set_source_files_properties(myclass_Classes.cxx PROPERTIES SKIP_LINTING ON)

add_custom_target (dictionary DEPENDS myclass_Classes.cxx)


add_executable(class_example_read.exe
        ${CMAKE_CURRENT_SOURCE_DIR}/class_example_read.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/src/MyRunClass.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/src/MyClass.cc myclass_Classes.cxx)
target_link_libraries(class_example_read.exe ROOT::Tree ROOT::RIO ROOT::Core HepMC3::HepMC3 HepMC3::rootIO)
set_target_properties(class_example_read.exe PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/outputs/${CMAKE_INSTALL_BINDIR})
add_dependencies( class_example_read.exe dictionary )

add_executable(class_example_write.exe
        ${CMAKE_CURRENT_SOURCE_DIR}/class_example_write.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/src/MyRunClass.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/src/MyClass.cc myclass_Classes.cxx)
target_link_libraries(class_example_write.exe ROOT::Tree ROOT::RIO ROOT::Core HepMC3::HepMC3 HepMC3::rootIO)
set_target_properties(class_example_write.exe PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/outputs/${CMAKE_INSTALL_BINDIR})
add_dependencies( class_example_write.exe dictionary )

# create environment scripts

set(bindir "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_BINDIR}")
set(libdir "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}:${ROOT_LIBRARY_DIR}")

configure_file( ${CMAKE_CURRENT_SOURCE_DIR}/class_example_env.sh.in
                ${PROJECT_BINARY_DIR}/outputs/${CMAKE_INSTALL_BINDIR}/class_example_env.sh
                @ONLY
              )

# installs
if (USE_INSTALLED_HEPMC3)
  install(TARGETS class_example_write.exe class_example_read.exe DESTINATION ${CMAKE_INSTALL_BINDIR})
  install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/example.hepmc3 ${CMAKE_CURRENT_BINARY_DIR}/libmyclass_Classes_rdict.pcm  ${CMAKE_CURRENT_BINARY_DIR}/libmyclass_Classes.rootmap  DESTINATION ${CMAKE_INSTALL_BINDIR})
  install(DIRECTORY ${PROJECT_BINARY_DIR}/outputs/${CMAKE_INSTALL_BINDIR}/ DESTINATION ${CMAKE_INSTALL_BINDIR}
        FILES_MATCHING PATTERN "*env.sh*")
endif()
