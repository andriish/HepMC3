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

// HepMC3::UIntAttribute file:HepMC3/Attribute.h line:528
struct PyCallBack_HepMC3_UIntAttribute : public HepMC3::UIntAttribute {
	using HepMC3::UIntAttribute::UIntAttribute;

	bool from_string(const std::string & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::UIntAttribute *>(this), "from_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return UIntAttribute::from_string(a0);
	}
	bool to_string(std::string & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::UIntAttribute *>(this), "to_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return UIntAttribute::to_string(a0);
	}
	bool init() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::UIntAttribute *>(this), "init");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::UIntAttribute *>(this), "init");
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

// HepMC3::ULongAttribute file:HepMC3/Attribute.h line:573
struct PyCallBack_HepMC3_ULongAttribute : public HepMC3::ULongAttribute {
	using HepMC3::ULongAttribute::ULongAttribute;

	bool from_string(const std::string & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::ULongAttribute *>(this), "from_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return ULongAttribute::from_string(a0);
	}
	bool to_string(std::string & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::ULongAttribute *>(this), "to_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return ULongAttribute::to_string(a0);
	}
	bool init() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::ULongAttribute *>(this), "init");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::ULongAttribute *>(this), "init");
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

// HepMC3::ULongLongAttribute file:HepMC3/Attribute.h line:617
struct PyCallBack_HepMC3_ULongLongAttribute : public HepMC3::ULongLongAttribute {
	using HepMC3::ULongLongAttribute::ULongLongAttribute;

	bool from_string(const std::string & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::ULongLongAttribute *>(this), "from_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return ULongLongAttribute::from_string(a0);
	}
	bool to_string(std::string & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::ULongLongAttribute *>(this), "to_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return ULongLongAttribute::to_string(a0);
	}
	bool init() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::ULongLongAttribute *>(this), "init");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::ULongLongAttribute *>(this), "init");
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

void bind_pyHepMC3_8(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // HepMC3::UIntAttribute file:HepMC3/Attribute.h line:528
		pybind11::class_<HepMC3::UIntAttribute, std::shared_ptr<HepMC3::UIntAttribute>, PyCallBack_HepMC3_UIntAttribute, HepMC3::Attribute> cl(M("HepMC3"), "UIntAttribute", "Attribute that holds an unsigned int\n\n  \n\n ");
		cl.def( pybind11::init( [](){ return new HepMC3::UIntAttribute(); }, [](){ return new PyCallBack_HepMC3_UIntAttribute(); } ) );
		cl.def( pybind11::init<unsigned int>(), pybind11::arg("val") );

		cl.def( pybind11::init( [](PyCallBack_HepMC3_UIntAttribute const &o){ return new PyCallBack_HepMC3_UIntAttribute(o); } ) );
		cl.def( pybind11::init( [](HepMC3::UIntAttribute const &o){ return new HepMC3::UIntAttribute(o); } ) );
		cl.def("from_string", (bool (HepMC3::UIntAttribute::*)(const std::string &)) &HepMC3::UIntAttribute::from_string, "Implementation of Attribute::from_string \n\nC++: HepMC3::UIntAttribute::from_string(const std::string &) --> bool", pybind11::arg("att"));
		cl.def("to_string", (bool (HepMC3::UIntAttribute::*)(std::string &) const) &HepMC3::UIntAttribute::to_string, "Implementation of Attribute::to_string \n\nC++: HepMC3::UIntAttribute::to_string(std::string &) const --> bool", pybind11::arg("att"));
		cl.def("value", (unsigned int (HepMC3::UIntAttribute::*)() const) &HepMC3::UIntAttribute::value, "get the value associated to this Attribute. \n\nC++: HepMC3::UIntAttribute::value() const --> unsigned int");
		cl.def("set_value", (void (HepMC3::UIntAttribute::*)(const unsigned int &)) &HepMC3::UIntAttribute::set_value, "set the value associated to this Attribute. \n\nC++: HepMC3::UIntAttribute::set_value(const unsigned int &) --> void", pybind11::arg("i"));
		cl.def("assign", (class HepMC3::UIntAttribute & (HepMC3::UIntAttribute::*)(const class HepMC3::UIntAttribute &)) &HepMC3::UIntAttribute::operator=, "C++: HepMC3::UIntAttribute::operator=(const class HepMC3::UIntAttribute &) --> class HepMC3::UIntAttribute &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // HepMC3::ULongAttribute file:HepMC3/Attribute.h line:573
		pybind11::class_<HepMC3::ULongAttribute, std::shared_ptr<HepMC3::ULongAttribute>, PyCallBack_HepMC3_ULongAttribute, HepMC3::Attribute> cl(M("HepMC3"), "ULongAttribute", "Attribute that holds an unsigned long\n\n  \n\n ");
		cl.def( pybind11::init( [](){ return new HepMC3::ULongAttribute(); }, [](){ return new PyCallBack_HepMC3_ULongAttribute(); } ) );
		cl.def( pybind11::init<unsigned long>(), pybind11::arg("val") );

		cl.def( pybind11::init( [](PyCallBack_HepMC3_ULongAttribute const &o){ return new PyCallBack_HepMC3_ULongAttribute(o); } ) );
		cl.def( pybind11::init( [](HepMC3::ULongAttribute const &o){ return new HepMC3::ULongAttribute(o); } ) );
		cl.def("from_string", (bool (HepMC3::ULongAttribute::*)(const std::string &)) &HepMC3::ULongAttribute::from_string, "Implementation of Attribute::from_string \n\nC++: HepMC3::ULongAttribute::from_string(const std::string &) --> bool", pybind11::arg("att"));
		cl.def("to_string", (bool (HepMC3::ULongAttribute::*)(std::string &) const) &HepMC3::ULongAttribute::to_string, "Implementation of Attribute::to_string \n\nC++: HepMC3::ULongAttribute::to_string(std::string &) const --> bool", pybind11::arg("att"));
		cl.def("value", (unsigned long (HepMC3::ULongAttribute::*)() const) &HepMC3::ULongAttribute::value, "get the value associated to this Attribute. \n\nC++: HepMC3::ULongAttribute::value() const --> unsigned long");
		cl.def("set_value", (void (HepMC3::ULongAttribute::*)(const unsigned long &)) &HepMC3::ULongAttribute::set_value, "set the value associated to this Attribute. \n\nC++: HepMC3::ULongAttribute::set_value(const unsigned long &) --> void", pybind11::arg("i"));
		cl.def("assign", (class HepMC3::ULongAttribute & (HepMC3::ULongAttribute::*)(const class HepMC3::ULongAttribute &)) &HepMC3::ULongAttribute::operator=, "C++: HepMC3::ULongAttribute::operator=(const class HepMC3::ULongAttribute &) --> class HepMC3::ULongAttribute &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // HepMC3::ULongLongAttribute file:HepMC3/Attribute.h line:617
		pybind11::class_<HepMC3::ULongLongAttribute, std::shared_ptr<HepMC3::ULongLongAttribute>, PyCallBack_HepMC3_ULongLongAttribute, HepMC3::Attribute> cl(M("HepMC3"), "ULongLongAttribute", "Attribute that holds an unsigned long long\n\n  \n\n ");
		cl.def( pybind11::init( [](){ return new HepMC3::ULongLongAttribute(); }, [](){ return new PyCallBack_HepMC3_ULongLongAttribute(); } ) );
		cl.def( pybind11::init<unsigned long long>(), pybind11::arg("val") );

		cl.def( pybind11::init( [](PyCallBack_HepMC3_ULongLongAttribute const &o){ return new PyCallBack_HepMC3_ULongLongAttribute(o); } ) );
		cl.def( pybind11::init( [](HepMC3::ULongLongAttribute const &o){ return new HepMC3::ULongLongAttribute(o); } ) );
		cl.def("from_string", (bool (HepMC3::ULongLongAttribute::*)(const std::string &)) &HepMC3::ULongLongAttribute::from_string, "Implementation of Attribute::from_string \n\nC++: HepMC3::ULongLongAttribute::from_string(const std::string &) --> bool", pybind11::arg("att"));
		cl.def("to_string", (bool (HepMC3::ULongLongAttribute::*)(std::string &) const) &HepMC3::ULongLongAttribute::to_string, "Implementation of Attribute::to_string \n\nC++: HepMC3::ULongLongAttribute::to_string(std::string &) const --> bool", pybind11::arg("att"));
		cl.def("value", (unsigned long long (HepMC3::ULongLongAttribute::*)() const) &HepMC3::ULongLongAttribute::value, "get the value associated to this Attribute. \n\nC++: HepMC3::ULongLongAttribute::value() const --> unsigned long long");
		cl.def("set_value", (void (HepMC3::ULongLongAttribute::*)(const unsigned long long &)) &HepMC3::ULongLongAttribute::set_value, "set the value associated to this Attribute. \n\nC++: HepMC3::ULongLongAttribute::set_value(const unsigned long long &) --> void", pybind11::arg("i"));
		cl.def("assign", (class HepMC3::ULongLongAttribute & (HepMC3::ULongLongAttribute::*)(const class HepMC3::ULongLongAttribute &)) &HepMC3::ULongLongAttribute::operator=, "C++: HepMC3::ULongLongAttribute::operator=(const class HepMC3::ULongLongAttribute &) --> class HepMC3::ULongLongAttribute &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
