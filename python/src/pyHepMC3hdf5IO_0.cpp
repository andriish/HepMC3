#include <HepMC3/ReaderHDF5.h>
#include <HepMC3/WriterHDF5.h>
#include <functional>
#include <iterator>
#include <map>
#include <memory>
#include <sstream> // __str__
#include <string>
#include <utility>
#include <vector>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>
#include <HepMC3/Version.h>
#include <HepMC3/Reader.h>
#include <HepMC3/Writer.h>
#include <HepMC3/Print.h>
#include <HepMC3/GenRunInfo.h>
#include <HepMC3/ReaderHDF5.h>
#include <HepMC3/WriterHDF5.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>, false)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*, false)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_pyHepMC3hdf5IO_0(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// HepMC3::ReaderHDF5 file:HepMC3/ReaderHDF5.h line:
	pybind11::class_<HepMC3::ReaderHDF5, std::shared_ptr<HepMC3::ReaderHDF5>, HepMC3::Reader>(M("HepMC3"), "ReaderHDF5")
		.def(pybind11::init<const std::string &>(), pybind11::arg("filename"))
		.def("read_event", (bool (HepMC3::ReaderHDF5::*)(HepMC3::GenEvent &)) &HepMC3::ReaderHDF5::read_event, pybind11::arg("evt"))
		.def("failed", &HepMC3::ReaderHDF5::failed)
		.def("close", &HepMC3::ReaderHDF5::close);

	// HepMC3::WriterHDF5 file:HepMC3/WriterHDF5.h line:
	pybind11::class_<HepMC3::WriterHDF5, std::shared_ptr<HepMC3::WriterHDF5>, HepMC3::Writer>(M("HepMC3"), "WriterHDF5")
		.def(pybind11::init<const std::string &>(), pybind11::arg("filename"))
		.def("write_event", (void (HepMC3::WriterHDF5::*)(const HepMC3::GenEvent &)) &HepMC3::WriterHDF5::write_event, pybind11::arg("evt"))
		.def("failed", &HepMC3::WriterHDF5::failed)
		.def("close", &HepMC3::WriterHDF5::close);
}
