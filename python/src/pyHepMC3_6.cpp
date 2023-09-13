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

// HepMC3::DoubleAttribute file:HepMC3/Attribute.h line:245
struct PyCallBack_HepMC3_DoubleAttribute : public HepMC3::DoubleAttribute {
	using HepMC3::DoubleAttribute::DoubleAttribute;

	bool from_string(const std::string & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::DoubleAttribute *>(this), "from_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return DoubleAttribute::from_string(a0);
	}
	bool to_string(std::string & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::DoubleAttribute *>(this), "to_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return DoubleAttribute::to_string(a0);
	}
	bool init() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::DoubleAttribute *>(this), "init");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::DoubleAttribute *>(this), "init");
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

// HepMC3::FloatAttribute file:HepMC3/Attribute.h line:292
struct PyCallBack_HepMC3_FloatAttribute : public HepMC3::FloatAttribute {
	using HepMC3::FloatAttribute::FloatAttribute;

	bool from_string(const std::string & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::FloatAttribute *>(this), "from_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return FloatAttribute::from_string(a0);
	}
	bool to_string(std::string & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::FloatAttribute *>(this), "to_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return FloatAttribute::to_string(a0);
	}
	bool init() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::FloatAttribute *>(this), "init");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::FloatAttribute *>(this), "init");
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

// HepMC3::StringAttribute file:HepMC3/Attribute.h line:343
struct PyCallBack_HepMC3_StringAttribute : public HepMC3::StringAttribute {
	using HepMC3::StringAttribute::StringAttribute;

	bool from_string(const std::string & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::StringAttribute *>(this), "from_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return StringAttribute::from_string(a0);
	}
	bool to_string(std::string & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::StringAttribute *>(this), "to_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return StringAttribute::to_string(a0);
	}
	bool init() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::StringAttribute *>(this), "init");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::StringAttribute *>(this), "init");
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

void bind_pyHepMC3_6(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // HepMC3::DoubleAttribute file:HepMC3/Attribute.h line:245
		pybind11::class_<HepMC3::DoubleAttribute, std::shared_ptr<HepMC3::DoubleAttribute>, PyCallBack_HepMC3_DoubleAttribute, HepMC3::Attribute> cl(M("HepMC3"), "DoubleAttribute", "Attribute that holds a real number as a double.\n\n  \n\n ");
		cl.def( pybind11::init( [](){ return new HepMC3::DoubleAttribute(); }, [](){ return new PyCallBack_HepMC3_DoubleAttribute(); } ) );
		cl.def( pybind11::init<double>(), pybind11::arg("val") );

		cl.def( pybind11::init( [](PyCallBack_HepMC3_DoubleAttribute const &o){ return new PyCallBack_HepMC3_DoubleAttribute(o); } ) );
		cl.def( pybind11::init( [](HepMC3::DoubleAttribute const &o){ return new HepMC3::DoubleAttribute(o); } ) );
		cl.def("from_string", (bool (HepMC3::DoubleAttribute::*)(const std::string &)) &HepMC3::DoubleAttribute::from_string, "Implementation of Attribute::from_string \n\nC++: HepMC3::DoubleAttribute::from_string(const std::string &) --> bool", pybind11::arg("att"));
		cl.def("to_string", (bool (HepMC3::DoubleAttribute::*)(std::string &) const) &HepMC3::DoubleAttribute::to_string, "Implementation of Attribute::to_string \n\nC++: HepMC3::DoubleAttribute::to_string(std::string &) const --> bool", pybind11::arg("att"));
		cl.def("value", (double (HepMC3::DoubleAttribute::*)() const) &HepMC3::DoubleAttribute::value, "get the value associated to this Attribute. \n\nC++: HepMC3::DoubleAttribute::value() const --> double");
		cl.def("set_value", (void (HepMC3::DoubleAttribute::*)(const double &)) &HepMC3::DoubleAttribute::set_value, "set the value associated to this Attribute. \n\nC++: HepMC3::DoubleAttribute::set_value(const double &) --> void", pybind11::arg("d"));
		cl.def("assign", (class HepMC3::DoubleAttribute & (HepMC3::DoubleAttribute::*)(const class HepMC3::DoubleAttribute &)) &HepMC3::DoubleAttribute::operator=, "C++: HepMC3::DoubleAttribute::operator=(const class HepMC3::DoubleAttribute &) --> class HepMC3::DoubleAttribute &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // HepMC3::FloatAttribute file:HepMC3/Attribute.h line:292
		pybind11::class_<HepMC3::FloatAttribute, std::shared_ptr<HepMC3::FloatAttribute>, PyCallBack_HepMC3_FloatAttribute, HepMC3::Attribute> cl(M("HepMC3"), "FloatAttribute", "Attribute that holds a real number as a float.\n\n  \n\n ");
		cl.def( pybind11::init( [](){ return new HepMC3::FloatAttribute(); }, [](){ return new PyCallBack_HepMC3_FloatAttribute(); } ) );
		cl.def( pybind11::init<float>(), pybind11::arg("val") );

		cl.def( pybind11::init( [](PyCallBack_HepMC3_FloatAttribute const &o){ return new PyCallBack_HepMC3_FloatAttribute(o); } ) );
		cl.def( pybind11::init( [](HepMC3::FloatAttribute const &o){ return new HepMC3::FloatAttribute(o); } ) );
		cl.def("from_string", (bool (HepMC3::FloatAttribute::*)(const std::string &)) &HepMC3::FloatAttribute::from_string, "Implementation of Attribute::from_string \n\nC++: HepMC3::FloatAttribute::from_string(const std::string &) --> bool", pybind11::arg("att"));
		cl.def("to_string", (bool (HepMC3::FloatAttribute::*)(std::string &) const) &HepMC3::FloatAttribute::to_string, "Implementation of Attribute::to_string \n\nC++: HepMC3::FloatAttribute::to_string(std::string &) const --> bool", pybind11::arg("att"));
		cl.def("value", (float (HepMC3::FloatAttribute::*)() const) &HepMC3::FloatAttribute::value, "get the value associated to this Attribute. \n\nC++: HepMC3::FloatAttribute::value() const --> float");
		cl.def("set_value", (void (HepMC3::FloatAttribute::*)(const float &)) &HepMC3::FloatAttribute::set_value, "set the value associated to this Attribute. \n\nC++: HepMC3::FloatAttribute::set_value(const float &) --> void", pybind11::arg("f"));
		cl.def("assign", (class HepMC3::FloatAttribute & (HepMC3::FloatAttribute::*)(const class HepMC3::FloatAttribute &)) &HepMC3::FloatAttribute::operator=, "C++: HepMC3::FloatAttribute::operator=(const class HepMC3::FloatAttribute &) --> class HepMC3::FloatAttribute &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // HepMC3::StringAttribute file:HepMC3/Attribute.h line:343
		pybind11::class_<HepMC3::StringAttribute, std::shared_ptr<HepMC3::StringAttribute>, PyCallBack_HepMC3_StringAttribute, HepMC3::Attribute> cl(M("HepMC3"), "StringAttribute", "Attribute that holds a string\n\n  Default attribute constructed when reading input files.\n  It can be then parsed by other attributes or left as a string.\n\n  \n\n ");
		cl.def( pybind11::init( [](){ return new HepMC3::StringAttribute(); }, [](){ return new PyCallBack_HepMC3_StringAttribute(); } ) );
		cl.def( pybind11::init<const std::string &>(), pybind11::arg("st") );

		cl.def( pybind11::init( [](PyCallBack_HepMC3_StringAttribute const &o){ return new PyCallBack_HepMC3_StringAttribute(o); } ) );
		cl.def( pybind11::init( [](HepMC3::StringAttribute const &o){ return new HepMC3::StringAttribute(o); } ) );
		cl.def("from_string", (bool (HepMC3::StringAttribute::*)(const std::string &)) &HepMC3::StringAttribute::from_string, "Implementation of Attribute::from_string \n\nC++: HepMC3::StringAttribute::from_string(const std::string &) --> bool", pybind11::arg("att"));
		cl.def("to_string", (bool (HepMC3::StringAttribute::*)(std::string &) const) &HepMC3::StringAttribute::to_string, "Implementation of Attribute::to_string \n\nC++: HepMC3::StringAttribute::to_string(std::string &) const --> bool", pybind11::arg("att"));
		cl.def("value", (std::string (HepMC3::StringAttribute::*)() const) &HepMC3::StringAttribute::value, "get the value associated to this Attribute. \n\nC++: HepMC3::StringAttribute::value() const --> std::string");
		cl.def("set_value", (void (HepMC3::StringAttribute::*)(const std::string &)) &HepMC3::StringAttribute::set_value, "set the value associated to this Attribute. \n\nC++: HepMC3::StringAttribute::set_value(const std::string &) --> void", pybind11::arg("s"));
		cl.def("assign", (class HepMC3::StringAttribute & (HepMC3::StringAttribute::*)(const class HepMC3::StringAttribute &)) &HepMC3::StringAttribute::operator=, "C++: HepMC3::StringAttribute::operator=(const class HepMC3::StringAttribute &) --> class HepMC3::StringAttribute &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
