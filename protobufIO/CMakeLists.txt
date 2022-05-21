include_directories(${PROJECT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/include ${Protobuf_INCLUDE_DIRS})

add_custom_target(compile_proto
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMAND protoc -I ${CMAKE_CURRENT_SOURCE_DIR} HepMC3.proto --cpp_out=. 
    && mkdir -p include/HepMC3 
    && mv HepMC3.pb.h include/HepMC3/
  DEPENDS HepMC3.proto 
  BYPRODUCTS HepMC3.pb.cc include/HepMC3/HepMC3.pb.h
  COMMENT "Generating HepMC3.pb.cc and include/HepMC3/HepMC3.pb.h from HepMC3.proto")

include_directories(${CMAKE_CURRENT_BINARY_DIR}/include ${CMAKE_CURRENT_BINARY_DIR}/include/HepMC3)

add_library(HepMC3protobufIO SHARED src/Writerprotobuf.cc src/Readerprotobuf.cc HepMC3.pb.cc)
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
install(TARGETS HepMC3protobufIO DESTINATION ${HEPMC3_PROTOBUFIO_INSTALL_LIBDIR} COMPONENT protobufIOlibs)
install(DIRECTORY ${PROJECT_BINARY_DIR}/outputs/${CMAKE_INSTALL_LIBDIR}/ DESTINATION ${HEPMC3_PROTOBUFIO_INSTALL_LIBDIR} COMPONENT protobufIOlibs  FILES_MATCHING PATTERN "CMakeFiles" EXCLUDE   PATTERN "src" EXCLUDE  PATTERN "include" EXCLUDE)
install(DIRECTORY include/HepMC3 DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} COMPONENT protobufIOdevel)
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/HepMC3 DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} COMPONENT protobufIOdevel)


add_executable(protobufIOWriter_test test/protobufIOWriter.cc)
target_link_libraries(protobufIOWriter_test HepMC3protobufIO)

install(TARGETS protobufIOWriter_test DESTINATION ${CMAKE_INSTALL_BINDIR})

add_executable(protobufIOReader_test test/protobufIOReader.cc)
target_link_libraries(protobufIOReader_test HepMC3protobufIO)

install(TARGETS protobufIOReader_test DESTINATION ${CMAKE_INSTALL_BINDIR})