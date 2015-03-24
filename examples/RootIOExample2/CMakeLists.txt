
include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/examples/RootIOExample2/include ${PROJECT_SOURCE_DIR}/rootIO/include ${ROOT_INCLUDE_DIR})

#----------------------------------------------------------------------------
# Generate dictionaries
#
ROOT_GENERATE_DICTIONARY(myclass_Classes myclass_Classes.h LINKDEF LinkDef.h OPTIONS -inlineInputHeader)


add_executable(class_example_read.exe ${PROJECT_SOURCE_DIR}/examples/RootIOExample2/class_example_read.cc ${PROJECT_SOURCE_DIR}/examples/RootIOExample2/src/MyClass.cc myclass_Classes.cxx)
target_link_libraries(class_example_read.exe ${ROOT_LIBRARIES} RIO HepMC rootIO)
set_target_properties(class_example_read.exe PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/outputs/bin)

add_executable(class_example_write.exe ${PROJECT_SOURCE_DIR}/examples/RootIOExample2/class_example_write.cc ${PROJECT_SOURCE_DIR}/examples/RootIOExample2/src/MyClass.cc myclass_Classes.cxx)
target_link_libraries(class_example_write.exe ${ROOT_LIBRARIES} RIO HepMC rootIO)
set_target_properties(class_example_write.exe PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/outputs/bin)

# create environment scripts

set(bindir "${CMAKE_INSTALL_PREFIX}/bin")
set(libdir "${CMAKE_INSTALL_PREFIX}/lib:${ROOT_LIBRARY_DIR}")
 
configure_file(
${CMAKE_SOURCE_DIR}/examples/RootIOExample2/class_example_env.sh.in
	    ${PROJECT_BINARY_DIR}/outputs/bin/class_example_env.sh
     	     @ONLY
      	     )

# installs 
install(TARGETS class_example_write.exe class_example_read.exe DESTINATION bin)
install(DIRECTORY ${PROJECT_BINARY_DIR}/examples/RootIOExample2/ DESTINATION lib FILES_MATCHING PATTERN "*.pcm")
install(FILES example.hepmc3 DESTINATION bin)
install(DIRECTORY ${PROJECT_BINARY_DIR}/outputs/bin/ DESTINATION bin
        FILES_MATCHING PATTERN "*.sh")