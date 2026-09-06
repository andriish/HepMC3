#include "hdf5IObinders.h"
#include <HepMC3/GenEvent.h>

namespace binder {

       void LHEFHDF5_binder(pybind11::module &M)
       {
              pybind11::class_<LHEF::ReaderHDF5, std::shared_ptr<LHEF::ReaderHDF5>> reader(M, "ReaderHDF5", "Read LHEF-HDF5 event files.");
              reader.def(pybind11::init<const std::string &>(), pybind11::arg("filename"));
              reader.def_readwrite("heprup", &LHEF::ReaderHDF5::heprup);
              reader.def_readwrite("hepeup", &LHEF::ReaderHDF5::hepeup);
              reader.def("readEvent", (bool (LHEF::ReaderHDF5::*)()) &LHEF::ReaderHDF5::readEvent, "Read the next LHE event.");
              reader.def("read_event", (bool (LHEF::ReaderHDF5::*)(LHEF::HEPEUP &)) &LHEF::ReaderHDF5::read_event, pybind11::arg("event"), "Read the next LHE event into event.");
              reader.def("skip", &LHEF::ReaderHDF5::skip, pybind11::arg("count"));
              reader.def("failed", &LHEF::ReaderHDF5::failed);
              reader.def("close", &LHEF::ReaderHDF5::close);

              pybind11::class_<LHEF::WriterHDF5, std::shared_ptr<LHEF::WriterHDF5>> writer(M, "WriterHDF5", "Write LHEF-HDF5 event files.");
              writer.def(pybind11::init<const std::string &>(), pybind11::arg("filename"));
              writer.def(pybind11::init<const std::string &, const LHEF::HEPRUP &>(), pybind11::arg("filename"), pybind11::arg("heprup"));
              writer.def_readwrite("heprup", &LHEF::WriterHDF5::heprup);
              writer.def_readwrite("hepeup", &LHEF::WriterHDF5::hepeup);
              writer.def("init", &LHEF::WriterHDF5::init);
              writer.def("writeinit", &LHEF::WriterHDF5::writeinit);
              writer.def("writeEvent", (void (LHEF::WriterHDF5::*)()) &LHEF::WriterHDF5::writeEvent);
              writer.def("write_event", (void (LHEF::WriterHDF5::*)(const LHEF::HEPEUP &)) &LHEF::WriterHDF5::write_event, pybind11::arg("event"));
              writer.def("failed", &LHEF::WriterHDF5::failed);
              writer.def("close", &LHEF::WriterHDF5::close);
       }

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
