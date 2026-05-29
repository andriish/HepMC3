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
#include <src/hdf5IObinders.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>, false)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*, false)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_pyHepMC3hdf5IO_0(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// HepMC3::ReaderHDF5 file:HepMC3/ReaderHDF5.h line:
	binder::ReaderHDF5_binder(M("HepMC3"));

	// HepMC3::WriterHDF5 file:HepMC3/WriterHDF5.h line:
	binder::WriterHDF5_binder(M("HepMC3"));

}
