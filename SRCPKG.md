# HepMC3 source-package structure

The package sources are organized as follows:

0. The topmost directory contains documentation for users and developers,
the contributing-author list, the main CMake build file `CMakeLists.txt`,
the licence details, the change log, and a config-script template:
```
./README.md
./SRCBUILD.md
./SRCPKG.md
./DEVELOPMENT.md
./AUTHORS.md
./LICENCE.md
./COPYING
./HepMC3-config.in
./ChangeLog
./CMakeLists.txt
```

1. The subdirectory `src/` contains the core set of library sources
while the corresponding headers are located in include/HepMC3
directory.  The subdirectory `include/HepMC3/Data` includes headers
with definitions of POD structures used in the library.

2. The subdirectory `search/src` contains a set of source files of the
search sublibrary while the corresponding headers are located in the
`search/include/HepMC3` directory. The `search/CMakeLists.txt` file is
used by CMake to build the search sublibrary.

3. The subdirectory `rootIO/src` contains a set of source files of the
rootIO sublibrary while the corresponding headers are located in the
`rootIO/include/HepMC3` and `rootIO/include/` directories. The
`rootIO/CMakeLists.txt` file is used by cmake to build the search
sublibrary.

4. The subdirectory `python` contains a set of source files required
for compilation of the Python bindings to the library. These include
the `python/include/pybind11` directory with the pybind11 headers.
The `python/src/` directory contains custom

```
python/src/root_binders.hpp
python/src/binders.hpp
python/src/stl_binders.hpp
```

and automatically generated binding sources:
```
python/src/pyHepMC3*.cpp
python/src/pyHepMC3rootIO*.cpp
python/src/pyHepMC3protobufIO*.cpp
python/src/pyHepMC3search*.cpp
```

The automatically generated sources were made using these `binder`
configurations:
```
python/src/pyHepMC3.binder
python/src/pyHepMC3rootIO.binder
python/src/pyHepMC3protobufIO.binder
python/src/pyHepMC3search.binder
```

and the header files generated from these templates:
```
python/all_includes.hpp.in
python/root_includes.hpp.in
python/search_includes.hpp.in
```

The directory contains the files that are used to build a Python
package and installation:
```
python/src/__init__.py
python/src/search/__init__.py
python/src/rootIO/__init__.py
python/src/protobufIO/__init__.py
pyHepMC3.egg-info.in
pyHepMC3.rootIO.egg-info.in
pyHepMC3.protobufIO.egg-info.in
pyHepMC3.search.egg-info.in
```

The `python/CMakeLists.txt` file is used by CMake to build the
binding.


5. The subdirectory `interfaces/` contains subdirectories with
interfaces (C++/Fortran source files, C++ headers) to Monte Carlo
event generators and event processing tools, e.g.  HepMC2 and Pythia6.


6. The subdirectories `test/` and `python/test` contain sets of files
(source files, scripts, inputs) that are used in the unit tests of the
library and the Python bindings respectively.  The files in `test/`
can be split in two groups:

- The tests of HepMC3 on itself with its inputs, e.g.
  ```
  ./test/testIO4.cc
  ./test/inputIO4.root
  ```
- Tests in both directories which serve as examples for usage of HepMC3.


7. The subdirectory `cmake/Modules` contains files needed for the
CMake configuration The subdirectory `cmake/Templates` contains
templates needed for generation of the library CMake configuration
files.


8. The subdirectory `examples` contains several examples of using the
HepMC3 library in standalone applications.

Each example is located in its own directory and can be built using
the `CMakeLists.txt` file in the same directory.

- The `examples/ConvertExample/` subdirectory contains source code of
  utility that converts different types of event records into each other:

  - The files
    ```
    ./examples/ConvertExample/src/WriterDOT.cc
    ./examples/ConvertExample/include/WriterDOT.h
    ```
    are the source files for an event format that can be visualized with
    graphviz.

  - The files
    ```
    ./examples/ConvertExample/src/WriterHEPEVTZEUS.cc
    ./examples/ConvertExample/include/WriterHEPEVTZEUS.h
    ```
    contain an implementation of output format that can be used in the
    ZEUS experiment.

  - The files
    ```
    ./examples/ConvertExample/src/WriterRootTreeOPAL.cc
    ./examples/ConvertExample/include/WriterRootTreeOPAL.h
    ```
    contain an implementation of output format that can be used together
    with data from the OPAL experiment.

  - The files
    ```
    ./examples/ConvertExample/src/AnalysisExample.cc
    ./examples/ConvertExample/include/AnalysisExample.h
    ```
    illustrate an implementation of simple physics analysis using the
    HepMC3 library.

  - The files
    ```
    ./examples/ConvertExample/include/ReaderuprootTree.h
    ./examples/ConvertExample/src/ReaderuprootTree.cc
    ```
    implement an a reader for ROOT files based on uproot.

  - The `./examples/RootIOExample/` subdirectory contains source code of
    an utility that illustrates manipulations with LHEF event record.

  - The `./examples/RootIOExample/` subdirectory contains source code of
    an utility that reads HepMC3 events in ROOT format.

  - The `./examples/RootIOExample2/` subdirectory contains source code of
    an utility that reads HepMC3 events in ROOT TTree format.

  - The `./examples/RootIOExample2/` subdirectory contains source code
    of an utility that reads HepMC3 events and saves them using a
    custom ROOT-based class.

  - The `./examples/RootIOExample3/` subdirectory contains source code
    of an utility that reads HepMC3 events and saves them nto ROOT
    TTree. This is a simplified version of ConvertExample.

  - The `./examples/BasicExamples/` subdirectory contains source code
    of basic examples of HepMC3 usage, e.g. building of event from
    scratch, reading and writing files, usage of fortran, etc.

  - The `./examples/Pythia6Example/` subdirectory contains source code
    of an utility that generates HepMC events with the Pythia6 Monte
    Carlo event generator.

  - The `./examples/Pythia8Example/` subdirectory contains source code
    of an utility that generates HepMC events with the Pythia8 Monte
    Carlo event generator.

  - The `./examples/LHEFExample/` subdirectory contains source code of
    an utility that illustrates manipulations with LHEF event record.

  - The `./examples/ViewerExample/` subdirectory contains source code
    of ROOT based GUI program that allows to visualize the HepMC3
    events.

  - The `./examples/SearchExample/` subdirectory contains source code
    example that deals with search of relations between particles in
    the event.


9. The `doc/` directory contains files used for generation of library
source code documentation with the Doxygen system. The
`doc/CMakeLists.txt` file is used by CMake to build the documentation.
