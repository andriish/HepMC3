#include "hdf5IObinders.h"
#include <HepMC3/GenEvent.h>

namespace binder {

       void LHEFHDF5_binder(pybind11::module &M)
       {
              pybind11::class_<LHEFHDF5::Reader, std::shared_ptr<LHEFHDF5::Reader>> reader(M, "Reader", "Read LHEF-HDF5 event files.");
              reader.def(pybind11::init<const std::string &>(), pybind11::arg("filename"));
              reader.def_readwrite("heprup", &LHEFHDF5::Reader::heprup);
              reader.def_readwrite("hepeup", &LHEFHDF5::Reader::hepeup);
              reader.def("readEvent", (bool (LHEFHDF5::Reader::*)()) &LHEFHDF5::Reader::readEvent, "Read the next LHE event.");
              reader.def("read_event", (bool (LHEFHDF5::Reader::*)(LHEF::HEPEUP &)) &LHEFHDF5::Reader::read_event, pybind11::arg("event"), "Read the next LHE event into event.");
              reader.def("skip", &LHEFHDF5::Reader::skip, pybind11::arg("count"));
              reader.def("failed", &LHEFHDF5::Reader::failed);
              reader.def("close", &LHEFHDF5::Reader::close);

              pybind11::class_<LHEFHDF5::Writer, std::shared_ptr<LHEFHDF5::Writer>> writer(M, "Writer", "Write LHEF-HDF5 event files.");
              writer.def(pybind11::init<const std::string &>(), pybind11::arg("filename"));
              writer.def(pybind11::init<const std::string &, const LHEF::HEPRUP &>(), pybind11::arg("filename"), pybind11::arg("heprup"));
              writer.def_readwrite("heprup", &LHEFHDF5::Writer::heprup);
              writer.def_readwrite("hepeup", &LHEFHDF5::Writer::hepeup);
              writer.def("init", &LHEFHDF5::Writer::init);
              writer.def("writeinit", &LHEFHDF5::Writer::writeinit);
              writer.def("writeEvent", (void (LHEFHDF5::Writer::*)()) &LHEFHDF5::Writer::writeEvent);
              writer.def("write_event", (void (LHEFHDF5::Writer::*)(const LHEF::HEPEUP &)) &LHEFHDF5::Writer::write_event, pybind11::arg("event"));
              writer.def("failed", &LHEFHDF5::Writer::failed);
              writer.def("close", &LHEFHDF5::Writer::close);
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
