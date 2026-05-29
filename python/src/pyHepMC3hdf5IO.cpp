#include <map>
#include <memory>
#include <string>

#include <pybind11/pybind11.h>

#include <HepMC3/ReaderHDF5.h>
#include <HepMC3/WriterHDF5.h>

namespace py = pybind11;

void bind_pyHepMC3hdf5IO_0(std::function< pybind11::module &(std::string const &namespace_) > &M);

PYBIND11_MODULE(pyHepMC3hdf5IO, root_module) {
    root_module.doc() = "pyHepMC3hdf5IO module";

    std::map<std::string, py::module_> modules;
    auto M = [&](std::string const &namespace_) -> py::module_ & {
        auto it = modules.find(namespace_);
        if (it == modules.end()) {
            throw std::runtime_error("Attempt to access pybind11::module for namespace " + namespace_ + " before it was created!!!");
        }
        return it->second;
    };

    modules[""] = root_module;
    modules["HepMC3"] = root_module.def_submodule("HepMC3", "Bindings for HepMC3 namespace");

    bind_pyHepMC3hdf5IO_0(M);
}
