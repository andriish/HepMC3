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

// HepMC3::CharAttribute file:HepMC3/Attribute.h line:387
struct PyCallBack_HepMC3_CharAttribute : public HepMC3::CharAttribute {
	using HepMC3::CharAttribute::CharAttribute;

	bool from_string(const std::string & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::CharAttribute *>(this), "from_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return CharAttribute::from_string(a0);
	}
	bool to_string(std::string & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::CharAttribute *>(this), "to_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return CharAttribute::to_string(a0);
	}
	bool init() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::CharAttribute *>(this), "init");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::CharAttribute *>(this), "init");
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

// HepMC3::LongLongAttribute file:HepMC3/Attribute.h line:434
struct PyCallBack_HepMC3_LongLongAttribute : public HepMC3::LongLongAttribute {
	using HepMC3::LongLongAttribute::LongLongAttribute;

	bool from_string(const std::string & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::LongLongAttribute *>(this), "from_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return LongLongAttribute::from_string(a0);
	}
	bool to_string(std::string & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::LongLongAttribute *>(this), "to_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return LongLongAttribute::to_string(a0);
	}
	bool init() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::LongLongAttribute *>(this), "init");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::LongLongAttribute *>(this), "init");
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

// HepMC3::LongDoubleAttribute file:HepMC3/Attribute.h line:479
struct PyCallBack_HepMC3_LongDoubleAttribute : public HepMC3::LongDoubleAttribute {
	using HepMC3::LongDoubleAttribute::LongDoubleAttribute;

	bool from_string(const std::string & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::LongDoubleAttribute *>(this), "from_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return LongDoubleAttribute::from_string(a0);
	}
	bool to_string(std::string & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::LongDoubleAttribute *>(this), "to_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return LongDoubleAttribute::to_string(a0);
	}
	bool init() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::LongDoubleAttribute *>(this), "init");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::LongDoubleAttribute *>(this), "init");
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

void bind_pyHepMC3_7(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // HepMC3::CharAttribute file:HepMC3/Attribute.h line:387
		pybind11::class_<HepMC3::CharAttribute, std::shared_ptr<HepMC3::CharAttribute>, PyCallBack_HepMC3_CharAttribute, HepMC3::Attribute> cl(M("HepMC3"), "CharAttribute", "Attribute that holds an Character implemented as an int\n\n  \n\n ");
		cl.def( pybind11::init( [](){ return new HepMC3::CharAttribute(); }, [](){ return new PyCallBack_HepMC3_CharAttribute(); } ) );
		cl.def( pybind11::init<char>(), pybind11::arg("val") );

		cl.def( pybind11::init( [](PyCallBack_HepMC3_CharAttribute const &o){ return new PyCallBack_HepMC3_CharAttribute(o); } ) );
		cl.def( pybind11::init( [](HepMC3::CharAttribute const &o){ return new HepMC3::CharAttribute(o); } ) );
		cl.def("from_string", (bool (HepMC3::CharAttribute::*)(const std::string &)) &HepMC3::CharAttribute::from_string, "Implementation of Attribute::from_string \n\nC++: HepMC3::CharAttribute::from_string(const std::string &) --> bool", pybind11::arg("att"));
		cl.def("to_string", (bool (HepMC3::CharAttribute::*)(std::string &) const) &HepMC3::CharAttribute::to_string, "Implementation of Attribute::to_string \n\nC++: HepMC3::CharAttribute::to_string(std::string &) const --> bool", pybind11::arg("att"));
		cl.def("value", (char (HepMC3::CharAttribute::*)() const) &HepMC3::CharAttribute::value, "get the value associated to this Attribute. \n\nC++: HepMC3::CharAttribute::value() const --> char");
		cl.def("set_value", (void (HepMC3::CharAttribute::*)(const char &)) &HepMC3::CharAttribute::set_value, "set the value associated to this Attribute. \n\nC++: HepMC3::CharAttribute::set_value(const char &) --> void", pybind11::arg("i"));
		cl.def("assign", (class HepMC3::CharAttribute & (HepMC3::CharAttribute::*)(const class HepMC3::CharAttribute &)) &HepMC3::CharAttribute::operator=, "C++: HepMC3::CharAttribute::operator=(const class HepMC3::CharAttribute &) --> class HepMC3::CharAttribute &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // HepMC3::LongLongAttribute file:HepMC3/Attribute.h line:434
		pybind11::class_<HepMC3::LongLongAttribute, std::shared_ptr<HepMC3::LongLongAttribute>, PyCallBack_HepMC3_LongLongAttribute, HepMC3::Attribute> cl(M("HepMC3"), "LongLongAttribute", "Attribute that holds an Integer implemented as a long long int\n\n  \n\n ");
		cl.def( pybind11::init( [](){ return new HepMC3::LongLongAttribute(); }, [](){ return new PyCallBack_HepMC3_LongLongAttribute(); } ) );
		cl.def( pybind11::init<long long>(), pybind11::arg("val") );

		cl.def( pybind11::init( [](PyCallBack_HepMC3_LongLongAttribute const &o){ return new PyCallBack_HepMC3_LongLongAttribute(o); } ) );
		cl.def( pybind11::init( [](HepMC3::LongLongAttribute const &o){ return new HepMC3::LongLongAttribute(o); } ) );
		cl.def("from_string", (bool (HepMC3::LongLongAttribute::*)(const std::string &)) &HepMC3::LongLongAttribute::from_string, "Implementation of Attribute::from_string \n\nC++: HepMC3::LongLongAttribute::from_string(const std::string &) --> bool", pybind11::arg("att"));
		cl.def("to_string", (bool (HepMC3::LongLongAttribute::*)(std::string &) const) &HepMC3::LongLongAttribute::to_string, "Implementation of Attribute::to_string \n\nC++: HepMC3::LongLongAttribute::to_string(std::string &) const --> bool", pybind11::arg("att"));
		cl.def("value", (long long (HepMC3::LongLongAttribute::*)() const) &HepMC3::LongLongAttribute::value, "get the value associated to this Attribute. \n\nC++: HepMC3::LongLongAttribute::value() const --> long long");
		cl.def("set_value", (void (HepMC3::LongLongAttribute::*)(const long long &)) &HepMC3::LongLongAttribute::set_value, "set the value associated to this Attribute. \n\nC++: HepMC3::LongLongAttribute::set_value(const long long &) --> void", pybind11::arg("l"));
		cl.def("assign", (class HepMC3::LongLongAttribute & (HepMC3::LongLongAttribute::*)(const class HepMC3::LongLongAttribute &)) &HepMC3::LongLongAttribute::operator=, "C++: HepMC3::LongLongAttribute::operator=(const class HepMC3::LongLongAttribute &) --> class HepMC3::LongLongAttribute &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // HepMC3::LongDoubleAttribute file:HepMC3/Attribute.h line:479
		pybind11::class_<HepMC3::LongDoubleAttribute, std::shared_ptr<HepMC3::LongDoubleAttribute>, PyCallBack_HepMC3_LongDoubleAttribute, HepMC3::Attribute> cl(M("HepMC3"), "LongDoubleAttribute", "Attribute that holds a real number as a long double.\n\n  \n\n ");
		cl.def( pybind11::init( [](){ return new HepMC3::LongDoubleAttribute(); }, [](){ return new PyCallBack_HepMC3_LongDoubleAttribute(); } ) );
		cl.def( pybind11::init<long double>(), pybind11::arg("val") );

		cl.def( pybind11::init( [](PyCallBack_HepMC3_LongDoubleAttribute const &o){ return new PyCallBack_HepMC3_LongDoubleAttribute(o); } ) );
		cl.def( pybind11::init( [](HepMC3::LongDoubleAttribute const &o){ return new HepMC3::LongDoubleAttribute(o); } ) );
		cl.def("from_string", (bool (HepMC3::LongDoubleAttribute::*)(const std::string &)) &HepMC3::LongDoubleAttribute::from_string, "Implementation of Attribute::from_string \n\nC++: HepMC3::LongDoubleAttribute::from_string(const std::string &) --> bool", pybind11::arg("att"));
		cl.def("to_string", (bool (HepMC3::LongDoubleAttribute::*)(std::string &) const) &HepMC3::LongDoubleAttribute::to_string, "Implementation of Attribute::to_string \n\nC++: HepMC3::LongDoubleAttribute::to_string(std::string &) const --> bool", pybind11::arg("att"));
		cl.def("value", (long double (HepMC3::LongDoubleAttribute::*)() const) &HepMC3::LongDoubleAttribute::value, "get the value associated to this Attribute. \n\nC++: HepMC3::LongDoubleAttribute::value() const --> long double");
		cl.def("set_value", (void (HepMC3::LongDoubleAttribute::*)(const long double &)) &HepMC3::LongDoubleAttribute::set_value, "set the value associated to this Attribute. \n\nC++: HepMC3::LongDoubleAttribute::set_value(const long double &) --> void", pybind11::arg("d"));
		cl.def("assign", (class HepMC3::LongDoubleAttribute & (HepMC3::LongDoubleAttribute::*)(const class HepMC3::LongDoubleAttribute &)) &HepMC3::LongDoubleAttribute::operator=, "C++: HepMC3::LongDoubleAttribute::operator=(const class HepMC3::LongDoubleAttribute &) --> class HepMC3::LongDoubleAttribute &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
