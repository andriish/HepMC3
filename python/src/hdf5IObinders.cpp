#include "hdf5IObinders.h"
#include <HepMC3/GenEvent.h>

namespace binder {

    void WriterHDF5_binder(pybind11::module &M)
    {
        pybind11::class_<HepMC3::WriterHDF5, std::shared_ptr<HepMC3::WriterHDF5>, HepMC3::Writer> cl(M, "WriterHDF5", "");
        pybind11::handle cl_type = cl;

        cl.def(pybind11::init<const std::string &>(), pybind11::arg("filename"));
        cl.def("write_event", (void (HepMC3::WriterHDF5::*)(const HepMC3::GenEvent &)) &HepMC3::WriterHDF5::write_event,
               "Write event to file\n\n  \n Event to be serialized\n\nC++: HepMC3::WriterHDF5::write_event(const class HepMC3::GenEvent &) --> void",
               pybind11::arg("evt"));
        cl.def("failed", (bool (HepMC3::WriterHDF5::*)()) &HepMC3::WriterHDF5::failed,
               "Get stream error state flag \n\nC++: HepMC3::WriterHDF5::failed() --> bool");
        cl.def("close", (void (HepMC3::WriterHDF5::*)()) &HepMC3::WriterHDF5::close,
               "Close file stream \n\nC++: HepMC3::WriterHDF5::close() --> void");
    }

    void ReaderHDF5_binder(pybind11::module &M)
    {
        pybind11::class_<HepMC3::ReaderHDF5, std::shared_ptr<HepMC3::ReaderHDF5>, HepMC3::Reader> cl(M, "ReaderHDF5", "");
        pybind11::handle cl_type = cl;

        cl.def(pybind11::init<const std::string &>(), pybind11::arg("filename"));
        cl.def("read_event", (bool (HepMC3::ReaderHDF5::*)(HepMC3::GenEvent &)) &HepMC3::ReaderHDF5::read_event,
               "Read event from file\n\n  \n Contains parsed event\n\nC++: HepMC3::ReaderHDF5::read_event(class HepMC3::GenEvent &) --> bool",
               pybind11::arg("evt"));
        cl.def("close", (void (HepMC3::ReaderHDF5::*)()) &HepMC3::ReaderHDF5::close,
               "Close file stream \n\nC++: HepMC3::ReaderHDF5::close() --> void");
        cl.def("failed", (bool (HepMC3::ReaderHDF5::*)()) &HepMC3::ReaderHDF5::failed,
               "Get stream error state \n\nC++: HepMC3::ReaderHDF5::failed() --> bool");
    }

} // namespace binder
