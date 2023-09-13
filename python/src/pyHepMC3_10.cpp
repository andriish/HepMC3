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

// HepMC3::VectorLongDoubleAttribute file:HepMC3/Attribute.h line:801
struct PyCallBack_HepMC3_VectorLongDoubleAttribute : public HepMC3::VectorLongDoubleAttribute {
	using HepMC3::VectorLongDoubleAttribute::VectorLongDoubleAttribute;

	bool from_string(const std::string & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorLongDoubleAttribute *>(this), "from_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return VectorLongDoubleAttribute::from_string(a0);
	}
	bool to_string(std::string & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorLongDoubleAttribute *>(this), "to_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return VectorLongDoubleAttribute::to_string(a0);
	}
	bool init() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorLongDoubleAttribute *>(this), "init");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorLongDoubleAttribute *>(this), "init");
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

// HepMC3::VectorLongLongAttribute file:HepMC3/Attribute.h line:850
struct PyCallBack_HepMC3_VectorLongLongAttribute : public HepMC3::VectorLongLongAttribute {
	using HepMC3::VectorLongLongAttribute::VectorLongLongAttribute;

	bool from_string(const std::string & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorLongLongAttribute *>(this), "from_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return VectorLongLongAttribute::from_string(a0);
	}
	bool to_string(std::string & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorLongLongAttribute *>(this), "to_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return VectorLongLongAttribute::to_string(a0);
	}
	bool init() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorLongLongAttribute *>(this), "init");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorLongLongAttribute *>(this), "init");
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

// HepMC3::VectorUIntAttribute file:HepMC3/Attribute.h line:897
struct PyCallBack_HepMC3_VectorUIntAttribute : public HepMC3::VectorUIntAttribute {
	using HepMC3::VectorUIntAttribute::VectorUIntAttribute;

	bool from_string(const std::string & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorUIntAttribute *>(this), "from_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return VectorUIntAttribute::from_string(a0);
	}
	bool to_string(std::string & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorUIntAttribute *>(this), "to_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return VectorUIntAttribute::to_string(a0);
	}
	bool init() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorUIntAttribute *>(this), "init");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorUIntAttribute *>(this), "init");
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

void bind_pyHepMC3_10(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // HepMC3::VectorLongDoubleAttribute file:HepMC3/Attribute.h line:801
		pybind11::class_<HepMC3::VectorLongDoubleAttribute, std::shared_ptr<HepMC3::VectorLongDoubleAttribute>, PyCallBack_HepMC3_VectorLongDoubleAttribute, HepMC3::Attribute> cl(M("HepMC3"), "VectorLongDoubleAttribute", "Attribute that holds a vector of real numbers of type long double\n\n  \n\n ");
		cl.def( pybind11::init( [](){ return new HepMC3::VectorLongDoubleAttribute(); }, [](){ return new PyCallBack_HepMC3_VectorLongDoubleAttribute(); } ) );
		cl.def( pybind11::init<class std::vector<long double>>(), pybind11::arg("val") );

		cl.def( pybind11::init( [](PyCallBack_HepMC3_VectorLongDoubleAttribute const &o){ return new PyCallBack_HepMC3_VectorLongDoubleAttribute(o); } ) );
		cl.def( pybind11::init( [](HepMC3::VectorLongDoubleAttribute const &o){ return new HepMC3::VectorLongDoubleAttribute(o); } ) );
		cl.def("from_string", (bool (HepMC3::VectorLongDoubleAttribute::*)(const std::string &)) &HepMC3::VectorLongDoubleAttribute::from_string, "Implementation of Attribute::from_string \n\nC++: HepMC3::VectorLongDoubleAttribute::from_string(const std::string &) --> bool", pybind11::arg("att"));
		cl.def("to_string", (bool (HepMC3::VectorLongDoubleAttribute::*)(std::string &) const) &HepMC3::VectorLongDoubleAttribute::to_string, "Implementation of Attribute::to_string \n\nC++: HepMC3::VectorLongDoubleAttribute::to_string(std::string &) const --> bool", pybind11::arg("att"));
		cl.def("value", (class std::vector<long double> (HepMC3::VectorLongDoubleAttribute::*)() const) &HepMC3::VectorLongDoubleAttribute::value, "get the value associated to this Attribute. \n\nC++: HepMC3::VectorLongDoubleAttribute::value() const --> class std::vector<long double>");
		cl.def("set_value", (void (HepMC3::VectorLongDoubleAttribute::*)(const class std::vector<long double> &)) &HepMC3::VectorLongDoubleAttribute::set_value, "set the value associated to this Attribute. \n\nC++: HepMC3::VectorLongDoubleAttribute::set_value(const class std::vector<long double> &) --> void", pybind11::arg("i"));
		cl.def("assign", (class HepMC3::VectorLongDoubleAttribute & (HepMC3::VectorLongDoubleAttribute::*)(const class HepMC3::VectorLongDoubleAttribute &)) &HepMC3::VectorLongDoubleAttribute::operator=, "C++: HepMC3::VectorLongDoubleAttribute::operator=(const class HepMC3::VectorLongDoubleAttribute &) --> class HepMC3::VectorLongDoubleAttribute &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // HepMC3::VectorLongLongAttribute file:HepMC3/Attribute.h line:850
		pybind11::class_<HepMC3::VectorLongLongAttribute, std::shared_ptr<HepMC3::VectorLongLongAttribute>, PyCallBack_HepMC3_VectorLongLongAttribute, HepMC3::Attribute> cl(M("HepMC3"), "VectorLongLongAttribute", "Attribute that holds a vector of integers of type  long long\n\n  \n\n ");
		cl.def( pybind11::init( [](){ return new HepMC3::VectorLongLongAttribute(); }, [](){ return new PyCallBack_HepMC3_VectorLongLongAttribute(); } ) );
		cl.def( pybind11::init<class std::vector<long long>>(), pybind11::arg("val") );

		cl.def( pybind11::init( [](PyCallBack_HepMC3_VectorLongLongAttribute const &o){ return new PyCallBack_HepMC3_VectorLongLongAttribute(o); } ) );
		cl.def( pybind11::init( [](HepMC3::VectorLongLongAttribute const &o){ return new HepMC3::VectorLongLongAttribute(o); } ) );
		cl.def("from_string", (bool (HepMC3::VectorLongLongAttribute::*)(const std::string &)) &HepMC3::VectorLongLongAttribute::from_string, "Implementation of Attribute::from_string \n\nC++: HepMC3::VectorLongLongAttribute::from_string(const std::string &) --> bool", pybind11::arg("att"));
		cl.def("to_string", (bool (HepMC3::VectorLongLongAttribute::*)(std::string &) const) &HepMC3::VectorLongLongAttribute::to_string, "Implementation of Attribute::to_string \n\nC++: HepMC3::VectorLongLongAttribute::to_string(std::string &) const --> bool", pybind11::arg("att"));
		cl.def("value", (class std::vector<long long> (HepMC3::VectorLongLongAttribute::*)() const) &HepMC3::VectorLongLongAttribute::value, "get the value associated to this Attribute. \n\nC++: HepMC3::VectorLongLongAttribute::value() const --> class std::vector<long long>");
		cl.def("set_value", (void (HepMC3::VectorLongLongAttribute::*)(const class std::vector<long long> &)) &HepMC3::VectorLongLongAttribute::set_value, "set the value associated to this Attribute. \n\nC++: HepMC3::VectorLongLongAttribute::set_value(const class std::vector<long long> &) --> void", pybind11::arg("i"));
		cl.def("assign", (class HepMC3::VectorLongLongAttribute & (HepMC3::VectorLongLongAttribute::*)(const class HepMC3::VectorLongLongAttribute &)) &HepMC3::VectorLongLongAttribute::operator=, "C++: HepMC3::VectorLongLongAttribute::operator=(const class HepMC3::VectorLongLongAttribute &) --> class HepMC3::VectorLongLongAttribute &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // HepMC3::VectorUIntAttribute file:HepMC3/Attribute.h line:897
		pybind11::class_<HepMC3::VectorUIntAttribute, std::shared_ptr<HepMC3::VectorUIntAttribute>, PyCallBack_HepMC3_VectorUIntAttribute, HepMC3::Attribute> cl(M("HepMC3"), "VectorUIntAttribute", "Attribute that holds a vector of unsigned integers of type  unsigned int\n\n  \n\n ");
		cl.def( pybind11::init( [](){ return new HepMC3::VectorUIntAttribute(); }, [](){ return new PyCallBack_HepMC3_VectorUIntAttribute(); } ) );
		cl.def( pybind11::init<class std::vector<unsigned int>>(), pybind11::arg("val") );

		cl.def( pybind11::init( [](PyCallBack_HepMC3_VectorUIntAttribute const &o){ return new PyCallBack_HepMC3_VectorUIntAttribute(o); } ) );
		cl.def( pybind11::init( [](HepMC3::VectorUIntAttribute const &o){ return new HepMC3::VectorUIntAttribute(o); } ) );
		cl.def("from_string", (bool (HepMC3::VectorUIntAttribute::*)(const std::string &)) &HepMC3::VectorUIntAttribute::from_string, "Implementation of Attribute::from_string \n\nC++: HepMC3::VectorUIntAttribute::from_string(const std::string &) --> bool", pybind11::arg("att"));
		cl.def("to_string", (bool (HepMC3::VectorUIntAttribute::*)(std::string &) const) &HepMC3::VectorUIntAttribute::to_string, "Implementation of Attribute::to_string \n\nC++: HepMC3::VectorUIntAttribute::to_string(std::string &) const --> bool", pybind11::arg("att"));
		cl.def("value", (class std::vector<unsigned int> (HepMC3::VectorUIntAttribute::*)() const) &HepMC3::VectorUIntAttribute::value, "get the value associated to this Attribute. \n\nC++: HepMC3::VectorUIntAttribute::value() const --> class std::vector<unsigned int>");
		cl.def("set_value", (void (HepMC3::VectorUIntAttribute::*)(const class std::vector<unsigned int> &)) &HepMC3::VectorUIntAttribute::set_value, "set the value associated to this Attribute. \n\nC++: HepMC3::VectorUIntAttribute::set_value(const class std::vector<unsigned int> &) --> void", pybind11::arg("i"));
		cl.def("assign", (class HepMC3::VectorUIntAttribute & (HepMC3::VectorUIntAttribute::*)(const class HepMC3::VectorUIntAttribute &)) &HepMC3::VectorUIntAttribute::operator=, "C++: HepMC3::VectorUIntAttribute::operator=(const class HepMC3::VectorUIntAttribute &) --> class HepMC3::VectorUIntAttribute &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
