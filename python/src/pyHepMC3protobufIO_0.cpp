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

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <HepMC3/Version.h>
#include <HepMC3/Reader.h>
#include <HepMC3/Writer.h>
#include <HepMC3/Print.h>
#include <HepMC3/GenRunInfo.h>
#include <HepMC3/Writerprotobuf.h>
#include <HepMC3/Readerprotobuf.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

// HepMC3::Readerprotobuf file:HepMC3/Readerprotobuf.h line:36
struct PyCallBack_HepMC3_Readerprotobuf : public HepMC3::Readerprotobuf {
	using HepMC3::Readerprotobuf::Readerprotobuf;

	bool skip(const int a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::Readerprotobuf *>(this), "skip");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return Readerprotobuf::skip(a0);
	}
	void close() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::Readerprotobuf *>(this), "close");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return Readerprotobuf::close();
	}
	bool failed() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::Readerprotobuf *>(this), "failed");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return Readerprotobuf::failed();
	}
};

// HepMC3::Writerprotobuf file:HepMC3/Writerprotobuf.h line:32
struct PyCallBack_HepMC3_Writerprotobuf : public HepMC3::Writerprotobuf {
	using HepMC3::Writerprotobuf::Writerprotobuf;

	void close() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::Writerprotobuf *>(this), "close");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return Writerprotobuf::close();
	}
	bool failed() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::Writerprotobuf *>(this), "failed");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return Writerprotobuf::failed();
	}
};

void bind_pyHepMC3protobufIO_0(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // HepMC3::Readerprotobuf file:HepMC3/Readerprotobuf.h line:36
		pybind11::class_<HepMC3::Readerprotobuf, std::shared_ptr<HepMC3::Readerprotobuf>, PyCallBack_HepMC3_Readerprotobuf> cl(M("HepMC3"), "Readerprotobuf", "");
		cl.def( pybind11::init<const std::string &>(), pybind11::arg("filename") );

		cl.def("skip", (bool (HepMC3::Readerprotobuf::*)(const int)) &HepMC3::Readerprotobuf::skip, "skip events\n\nC++: HepMC3::Readerprotobuf::skip(const int) --> bool", pybind11::arg(""));
		cl.def("close", (void (HepMC3::Readerprotobuf::*)()) &HepMC3::Readerprotobuf::close, "Close file stream \n\nC++: HepMC3::Readerprotobuf::close() --> void");
		cl.def("failed", (bool (HepMC3::Readerprotobuf::*)()) &HepMC3::Readerprotobuf::failed, "Get stream error state \n\nC++: HepMC3::Readerprotobuf::failed() --> bool");
	}
	{ // HepMC3::Writerprotobuf file:HepMC3/Writerprotobuf.h line:32
		pybind11::class_<HepMC3::Writerprotobuf, std::shared_ptr<HepMC3::Writerprotobuf>, PyCallBack_HepMC3_Writerprotobuf> cl(M("HepMC3"), "Writerprotobuf", "");
		cl.def("close", (void (HepMC3::Writerprotobuf::*)()) &HepMC3::Writerprotobuf::close, "Close file stream \n\nC++: HepMC3::Writerprotobuf::close() --> void");
		cl.def("failed", (bool (HepMC3::Writerprotobuf::*)()) &HepMC3::Writerprotobuf::failed, "Get stream error state flag \n\nC++: HepMC3::Writerprotobuf::failed() --> bool");
	}
}
