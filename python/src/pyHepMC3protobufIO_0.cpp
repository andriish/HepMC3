#include <HepMC3/Readerprotobuf.h>
#include <HepMC3/Writerprotobuf.h>
#include <functional>
#include <ios>
#include <istream>
#include <iterator>
#include <map>
#include <memory>
#include <ostream>
#include <sstream> // __str__
#include <streambuf>
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
#include <HepMC3/Writerprotobuf.h>
#include <HepMC3/Readerprotobuf.h>
#include <src/protobufIObinders.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>, false)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*, false)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_pyHepMC3protobufIO_0(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// HepMC3::Readerprotobuf file:HepMC3/Readerprotobuf.h line:
	binder::Readerprotobuf_binder(M("HepMC3"));

	// HepMC3::Writerprotobuf file:HepMC3/Writerprotobuf.h line:
	binder::Writerprotobuf_binder(M("HepMC3"));

}
