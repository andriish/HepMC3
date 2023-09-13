#include <HepMC3/Attribute.h>
#include <HepMC3/Data/GenRunInfoData.h>
#include <HepMC3/GenCrossSection.h>
#include <HepMC3/GenHeavyIon.h>
#include <HepMC3/GenRunInfo.h>
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
#include <src/stl_binders.hpp>
#include <src/binders.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

// HepMC3::VectorULongAttribute file:HepMC3/Attribute.h line:944
struct PyCallBack_HepMC3_VectorULongAttribute : public HepMC3::VectorULongAttribute {
	using HepMC3::VectorULongAttribute::VectorULongAttribute;

	bool from_string(const std::string & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorULongAttribute *>(this), "from_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return VectorULongAttribute::from_string(a0);
	}
	bool to_string(std::string & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorULongAttribute *>(this), "to_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return VectorULongAttribute::to_string(a0);
	}
	bool init() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorULongAttribute *>(this), "init");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return Attribute::init();
	}
	bool init(const class HepMC3::GenRunInfo & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorULongAttribute *>(this), "init");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return Attribute::init(a0);
	}
};

// HepMC3::VectorULongLongAttribute file:HepMC3/Attribute.h line:992
struct PyCallBack_HepMC3_VectorULongLongAttribute : public HepMC3::VectorULongLongAttribute {
	using HepMC3::VectorULongLongAttribute::VectorULongLongAttribute;

	bool from_string(const std::string & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorULongLongAttribute *>(this), "from_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return VectorULongLongAttribute::from_string(a0);
	}
	bool to_string(std::string & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorULongLongAttribute *>(this), "to_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return VectorULongLongAttribute::to_string(a0);
	}
	bool init() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorULongLongAttribute *>(this), "init");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return Attribute::init();
	}
	bool init(const class HepMC3::GenRunInfo & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorULongLongAttribute *>(this), "init");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return Attribute::init(a0);
	}
};

// HepMC3::VectorIntAttribute file:HepMC3/Attribute.h line:1039
struct PyCallBack_HepMC3_VectorIntAttribute : public HepMC3::VectorIntAttribute {
	using HepMC3::VectorIntAttribute::VectorIntAttribute;

	bool from_string(const std::string & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorIntAttribute *>(this), "from_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return VectorIntAttribute::from_string(a0);
	}
	bool to_string(std::string & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorIntAttribute *>(this), "to_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return VectorIntAttribute::to_string(a0);
	}
	bool init() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorIntAttribute *>(this), "init");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return Attribute::init();
	}
	bool init(const class HepMC3::GenRunInfo & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorIntAttribute *>(this), "init");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return Attribute::init(a0);
	}
};

void bind_pyHepMC3_11(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // HepMC3::VectorULongAttribute file:HepMC3/Attribute.h line:944
		pybind11::class_<HepMC3::VectorULongAttribute, std::shared_ptr<HepMC3::VectorULongAttribute>, PyCallBack_HepMC3_VectorULongAttribute, HepMC3::Attribute> cl(M("HepMC3"), "VectorULongAttribute", "Attribute that holds a vector of unsigned integers of type  unsigned long\n\n  \n\n ");
		cl.def( pybind11::init( [](){ return new HepMC3::VectorULongAttribute(); }, [](){ return new PyCallBack_HepMC3_VectorULongAttribute(); } ) );
		cl.def( pybind11::init<class std::vector<unsigned long>>(), pybind11::arg("val") );

		cl.def( pybind11::init( [](PyCallBack_HepMC3_VectorULongAttribute const &o){ return new PyCallBack_HepMC3_VectorULongAttribute(o); } ) );
		cl.def( pybind11::init( [](HepMC3::VectorULongAttribute const &o){ return new HepMC3::VectorULongAttribute(o); } ) );
		cl.def("from_string", (bool (HepMC3::VectorULongAttribute::*)(const std::string &)) &HepMC3::VectorULongAttribute::from_string, "Implementation of Attribute::from_string \n\nC++: HepMC3::VectorULongAttribute::from_string(const std::string &) --> bool", pybind11::arg("att"));
		cl.def("to_string", (bool (HepMC3::VectorULongAttribute::*)(std::string &) const) &HepMC3::VectorULongAttribute::to_string, "Implementation of Attribute::to_string \n\nC++: HepMC3::VectorULongAttribute::to_string(std::string &) const --> bool", pybind11::arg("att"));
		cl.def("value", (class std::vector<unsigned long> (HepMC3::VectorULongAttribute::*)() const) &HepMC3::VectorULongAttribute::value, "get the value associated to this Attribute. \n\nC++: HepMC3::VectorULongAttribute::value() const --> class std::vector<unsigned long>");
		cl.def("set_value", (void (HepMC3::VectorULongAttribute::*)(const class std::vector<unsigned long> &)) &HepMC3::VectorULongAttribute::set_value, "set the value associated to this Attribute. \n\nC++: HepMC3::VectorULongAttribute::set_value(const class std::vector<unsigned long> &) --> void", pybind11::arg("i"));
		cl.def("assign", (class HepMC3::VectorULongAttribute & (HepMC3::VectorULongAttribute::*)(const class HepMC3::VectorULongAttribute &)) &HepMC3::VectorULongAttribute::operator=, "C++: HepMC3::VectorULongAttribute::operator=(const class HepMC3::VectorULongAttribute &) --> class HepMC3::VectorULongAttribute &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // HepMC3::VectorULongLongAttribute file:HepMC3/Attribute.h line:992
		pybind11::class_<HepMC3::VectorULongLongAttribute, std::shared_ptr<HepMC3::VectorULongLongAttribute>, PyCallBack_HepMC3_VectorULongLongAttribute, HepMC3::Attribute> cl(M("HepMC3"), "VectorULongLongAttribute", "Attribute that holds a vector of integers of type  unsigned long long\n\n  \n\n ");
		cl.def( pybind11::init( [](){ return new HepMC3::VectorULongLongAttribute(); }, [](){ return new PyCallBack_HepMC3_VectorULongLongAttribute(); } ) );
		cl.def( pybind11::init<class std::vector<unsigned long long>>(), pybind11::arg("val") );

		cl.def( pybind11::init( [](PyCallBack_HepMC3_VectorULongLongAttribute const &o){ return new PyCallBack_HepMC3_VectorULongLongAttribute(o); } ) );
		cl.def( pybind11::init( [](HepMC3::VectorULongLongAttribute const &o){ return new HepMC3::VectorULongLongAttribute(o); } ) );
		cl.def("from_string", (bool (HepMC3::VectorULongLongAttribute::*)(const std::string &)) &HepMC3::VectorULongLongAttribute::from_string, "Implementation of Attribute::from_string \n\nC++: HepMC3::VectorULongLongAttribute::from_string(const std::string &) --> bool", pybind11::arg("att"));
		cl.def("to_string", (bool (HepMC3::VectorULongLongAttribute::*)(std::string &) const) &HepMC3::VectorULongLongAttribute::to_string, "Implementation of Attribute::to_string \n\nC++: HepMC3::VectorULongLongAttribute::to_string(std::string &) const --> bool", pybind11::arg("att"));
		cl.def("value", (class std::vector<unsigned long long> (HepMC3::VectorULongLongAttribute::*)() const) &HepMC3::VectorULongLongAttribute::value, "get the value associated to this Attribute. \n\nC++: HepMC3::VectorULongLongAttribute::value() const --> class std::vector<unsigned long long>");
		cl.def("set_value", (void (HepMC3::VectorULongLongAttribute::*)(const class std::vector<unsigned long long> &)) &HepMC3::VectorULongLongAttribute::set_value, "set the value associated to this Attribute. \n\nC++: HepMC3::VectorULongLongAttribute::set_value(const class std::vector<unsigned long long> &) --> void", pybind11::arg("i"));
		cl.def("assign", (class HepMC3::VectorULongLongAttribute & (HepMC3::VectorULongLongAttribute::*)(const class HepMC3::VectorULongLongAttribute &)) &HepMC3::VectorULongLongAttribute::operator=, "C++: HepMC3::VectorULongLongAttribute::operator=(const class HepMC3::VectorULongLongAttribute &) --> class HepMC3::VectorULongLongAttribute &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // HepMC3::VectorIntAttribute file:HepMC3/Attribute.h line:1039
		pybind11::class_<HepMC3::VectorIntAttribute, std::shared_ptr<HepMC3::VectorIntAttribute>, PyCallBack_HepMC3_VectorIntAttribute, HepMC3::Attribute> cl(M("HepMC3"), "VectorIntAttribute", "Attribute that holds a vector of integers of type  int\n\n  \n\n ");
		cl.def( pybind11::init( [](){ return new HepMC3::VectorIntAttribute(); }, [](){ return new PyCallBack_HepMC3_VectorIntAttribute(); } ) );
		cl.def( pybind11::init<class std::vector<int>>(), pybind11::arg("val") );

		cl.def( pybind11::init( [](PyCallBack_HepMC3_VectorIntAttribute const &o){ return new PyCallBack_HepMC3_VectorIntAttribute(o); } ) );
		cl.def( pybind11::init( [](HepMC3::VectorIntAttribute const &o){ return new HepMC3::VectorIntAttribute(o); } ) );
		cl.def("from_string", (bool (HepMC3::VectorIntAttribute::*)(const std::string &)) &HepMC3::VectorIntAttribute::from_string, "Implementation of Attribute::from_string \n\nC++: HepMC3::VectorIntAttribute::from_string(const std::string &) --> bool", pybind11::arg("att"));
		cl.def("to_string", (bool (HepMC3::VectorIntAttribute::*)(std::string &) const) &HepMC3::VectorIntAttribute::to_string, "Implementation of Attribute::to_string \n\nC++: HepMC3::VectorIntAttribute::to_string(std::string &) const --> bool", pybind11::arg("att"));
		cl.def("value", (class std::vector<int> (HepMC3::VectorIntAttribute::*)() const) &HepMC3::VectorIntAttribute::value, "get the value associated to this Attribute. \n\nC++: HepMC3::VectorIntAttribute::value() const --> class std::vector<int>");
		cl.def("set_value", (void (HepMC3::VectorIntAttribute::*)(const class std::vector<int> &)) &HepMC3::VectorIntAttribute::set_value, "set the value associated to this Attribute. \n\nC++: HepMC3::VectorIntAttribute::set_value(const class std::vector<int> &) --> void", pybind11::arg("i"));
		cl.def("assign", (class HepMC3::VectorIntAttribute & (HepMC3::VectorIntAttribute::*)(const class HepMC3::VectorIntAttribute &)) &HepMC3::VectorIntAttribute::operator=, "C++: HepMC3::VectorIntAttribute::operator=(const class HepMC3::VectorIntAttribute &) --> class HepMC3::VectorIntAttribute &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
