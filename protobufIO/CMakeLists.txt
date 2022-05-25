include_directories(${PROJECT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/include ${Protobuf_INCLUDE_DIRS})

string(REPLACE "." ";" Protobuf_VERSION_LIST ${Protobuf_VERSION})
list(GET Protobuf_VERSION_LIST 0 Protobuf_VERSION_MAJOR)
configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/HepMC3_v${Protobuf_VERSION_MAJOR}.proto
        ${CMAKE_CURRENT_BINARY_DIR}/include/HepMC3/HepMC3.proto
        IMMEDIATE @ONLY)

add_custom_target(compile_proto
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/HepMC3/
  COMMAND ${Protobuf_PROTOC_EXECUTABLE} HepMC3.proto --cpp_out=${CMAKE_CURRENT_BINARY_DIR}/include/HepMC3/ 
  DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/include/HepMC3/HepMC3.proto 
  BYPRODUCTS ${CMAKE_CURRENT_BINARY_DIR}/include/HepMC3/HepMC3.pb.cc ${CMAKE_CURRENT_BINARY_DIR}/include/HepMC3/HepMC3.pb.h
  COMMENT "Generating HepMC3.pb.cc and ${CMAKE_CURRENT_BINARY_DIR}/include/HepMC3/HepMC3.pb.h from HepMC3.proto")

include_directories(${CMAKE_CURRENT_BINARY_DIR}/include ${CMAKE_CURRENT_BINARY_DIR}/include/HepMC3)

add_library(HepMC3protobufIO SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/Writerprotobuf.cc ${CMAKE_CURRENT_SOURCE_DIR}/src/Readerprotobuf.cc ${CMAKE_CURRENT_BINARY_DIR}/include/HepMC3/HepMC3.pb.cc)
add_dependencies(HepMC3protobufIO compile_proto)
set_property(TARGET HepMC3protobufIO PROPERTY POSITION_INDEPENDENT_CODE 1)
target_compile_definitions(HepMC3protobufIO PUBLIC
  -DHEPMC3_VERSION_MAJOR=${HEPMC3_VERSION_MAJOR}
  -DHEPMC3_VERSION_MINOR=${HEPMC3_VERSION_MINOR}
  -DHEPMC3_VERSION_PATCH=${HEPMC3_VERSION_PATCH})

target_link_libraries(HepMC3protobufIO HepMC3 protobuf::libprotobuf)
set_target_properties(HepMC3protobufIO PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/outputs/${CMAKE_INSTALL_LIBDIR}/$<0:>)
if (MSVC)
  set_target_properties(HepMC3protobufIO PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/outputs/${CMAKE_INSTALL_LIBDIR}/$<0:>)
endif()
set_target_properties(HepMC3protobufIO PROPERTIES SOVERSION 3)
# installs
install(TARGETS HepMC3protobufIO DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT protobufIOlibs)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/HepMC3/Writerprotobuf.h ${CMAKE_CURRENT_SOURCE_DIR}/include/HepMC3/Readerprotobuf.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/include/HepMC3 COMPONENT protobufIOdevel)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/include/HepMC3/HepMC3.pb.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/include/HepMC3 COMPONENT protobufIOdevel)
