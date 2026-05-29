#ifndef HDF5IO_BINDERS_H
#define HDF5IO_BINDERS_H
#include <HepMC3/ReaderHDF5.h>
#include <HepMC3/WriterHDF5.h>
#include <pybind11/pybind11.h>
namespace binder {
	void	WriterHDF5_binder(pybind11::module &M);
	void	ReaderHDF5_binder(pybind11::module &M);
} // namespace binder
#endif // HDF5IO_BINDERS_H
