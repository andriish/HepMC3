#include <HepMC3/Attribute.h>
#include <HepMC3/Data/GenEventData.h>
#include <HepMC3/Data/GenRunInfoData.h>
#include <HepMC3/FourVector.h>
#include <HepMC3/GenCrossSection.h>
#include <HepMC3/GenEvent.h>
#include <HepMC3/GenHeavyIon.h>
#include <HepMC3/GenParticle.h>
#include <HepMC3/GenRunInfo.h>
#include <HepMC3/GenVertex.h>
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

// HepMC3::Attribute file:HepMC3/Attribute.h line:44
struct PyCallBack_HepMC3_Attribute : public HepMC3::Attribute {
	using HepMC3::Attribute::Attribute;

	bool from_string(const std::string & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::Attribute *>(this), "from_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"Attribute::from_string\"");
	}
	bool init() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::Attribute *>(this), "init");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::Attribute *>(this), "init");
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
	bool to_string(std::string & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::Attribute *>(this), "to_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"Attribute::to_string\"");
	}
};

// HepMC3::IntAttribute file:HepMC3/Attribute.h line:157
struct PyCallBack_HepMC3_IntAttribute : public HepMC3::IntAttribute {
	using HepMC3::IntAttribute::IntAttribute;

	bool from_string(const std::string & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::IntAttribute *>(this), "from_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return IntAttribute::from_string(a0);
	}
	bool to_string(std::string & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::IntAttribute *>(this), "to_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return IntAttribute::to_string(a0);
	}
	bool init() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::IntAttribute *>(this), "init");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::IntAttribute *>(this), "init");
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

// HepMC3::LongAttribute file:HepMC3/Attribute.h line:200
struct PyCallBack_HepMC3_LongAttribute : public HepMC3::LongAttribute {
	using HepMC3::LongAttribute::LongAttribute;

	bool from_string(const std::string & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::LongAttribute *>(this), "from_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return LongAttribute::from_string(a0);
	}
	bool to_string(std::string & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::LongAttribute *>(this), "to_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return LongAttribute::to_string(a0);
	}
	bool init() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::LongAttribute *>(this), "init");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::LongAttribute *>(this), "init");
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

void bind_pyHepMC3_5(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // HepMC3::Attribute file:HepMC3/Attribute.h line:44
		pybind11::class_<HepMC3::Attribute, std::shared_ptr<HepMC3::Attribute>, PyCallBack_HepMC3_Attribute> cl(M("HepMC3"), "Attribute", "Base attribute class. ");
		cl.def( pybind11::init( [](){ return new PyCallBack_HepMC3_Attribute(); } ) );
		cl.def(pybind11::init<PyCallBack_HepMC3_Attribute const &>());
		cl.def("from_string", (bool (HepMC3::Attribute::*)(const std::string &)) &HepMC3::Attribute::from_string, "Fill class content from string.\n\nC++: HepMC3::Attribute::from_string(const std::string &) --> bool", pybind11::arg("att"));
		cl.def("init", (bool (HepMC3::Attribute::*)()) &HepMC3::Attribute::init, "Optionally initialize the attribute after from_string.\n\nC++: HepMC3::Attribute::init() --> bool");
		cl.def("init", (bool (HepMC3::Attribute::*)(const class HepMC3::GenRunInfo &)) &HepMC3::Attribute::init, "Optionally initialize the attribute after from_string\n\n Is passed a reference to the GenRunInfo object to which the\n Attribute belongs.\n\nC++: HepMC3::Attribute::init(const class HepMC3::GenRunInfo &) --> bool", pybind11::arg(""));
		cl.def("to_string", (bool (HepMC3::Attribute::*)(std::string &) const) &HepMC3::Attribute::to_string, "Fill string from class content \n\nC++: HepMC3::Attribute::to_string(std::string &) const --> bool", pybind11::arg("att"));
		cl.def("is_parsed", (bool (HepMC3::Attribute::*)() const) &HepMC3::Attribute::is_parsed, "Check if this attribute is parsed \n\nC++: HepMC3::Attribute::is_parsed() const --> bool");
		cl.def("unparsed_string", (const std::string & (HepMC3::Attribute::*)() const) &HepMC3::Attribute::unparsed_string, "Get unparsed string \n\nC++: HepMC3::Attribute::unparsed_string() const --> const std::string &", pybind11::return_value_policy::automatic);
		cl.def("event", (const class HepMC3::GenEvent * (HepMC3::Attribute::*)() const) &HepMC3::Attribute::event, "return the GenEvent to which this Attribute belongs, if at all. \n\nC++: HepMC3::Attribute::event() const --> const class HepMC3::GenEvent *", pybind11::return_value_policy::automatic);
		cl.def("particle", (class std::shared_ptr<class HepMC3::GenParticle> (HepMC3::Attribute::*)()) &HepMC3::Attribute::particle, "return the GenParticle to which this Attribute belongs, if at all. \n\nC++: HepMC3::Attribute::particle() --> class std::shared_ptr<class HepMC3::GenParticle>");
		cl.def("vertex", (class std::shared_ptr<class HepMC3::GenVertex> (HepMC3::Attribute::*)()) &HepMC3::Attribute::vertex, "return the GenVertex to which this Attribute belongs, if at all. \n\nC++: HepMC3::Attribute::vertex() --> class std::shared_ptr<class HepMC3::GenVertex>");
		cl.def("assign", (class HepMC3::Attribute & (HepMC3::Attribute::*)(const class HepMC3::Attribute &)) &HepMC3::Attribute::operator=, "C++: HepMC3::Attribute::operator=(const class HepMC3::Attribute &) --> class HepMC3::Attribute &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // HepMC3::IntAttribute file:HepMC3/Attribute.h line:157
		pybind11::class_<HepMC3::IntAttribute, std::shared_ptr<HepMC3::IntAttribute>, PyCallBack_HepMC3_IntAttribute, HepMC3::Attribute> cl(M("HepMC3"), "IntAttribute", "Attribute that holds an Integer implemented as an int\n\n  \n\n ");
		cl.def( pybind11::init( [](){ return new HepMC3::IntAttribute(); }, [](){ return new PyCallBack_HepMC3_IntAttribute(); } ) );
		cl.def( pybind11::init<int>(), pybind11::arg("val") );

		cl.def( pybind11::init( [](PyCallBack_HepMC3_IntAttribute const &o){ return new PyCallBack_HepMC3_IntAttribute(o); } ) );
		cl.def( pybind11::init( [](HepMC3::IntAttribute const &o){ return new HepMC3::IntAttribute(o); } ) );
		cl.def("from_string", (bool (HepMC3::IntAttribute::*)(const std::string &)) &HepMC3::IntAttribute::from_string, "Implementation of Attribute::from_string \n\nC++: HepMC3::IntAttribute::from_string(const std::string &) --> bool", pybind11::arg("att"));
		cl.def("to_string", (bool (HepMC3::IntAttribute::*)(std::string &) const) &HepMC3::IntAttribute::to_string, "Implementation of Attribute::to_string \n\nC++: HepMC3::IntAttribute::to_string(std::string &) const --> bool", pybind11::arg("att"));
		cl.def("value", (int (HepMC3::IntAttribute::*)() const) &HepMC3::IntAttribute::value, "get the value associated to this Attribute. \n\nC++: HepMC3::IntAttribute::value() const --> int");
		cl.def("set_value", (void (HepMC3::IntAttribute::*)(const int &)) &HepMC3::IntAttribute::set_value, "set the value associated to this Attribute. \n\nC++: HepMC3::IntAttribute::set_value(const int &) --> void", pybind11::arg("i"));
		cl.def("assign", (class HepMC3::IntAttribute & (HepMC3::IntAttribute::*)(const class HepMC3::IntAttribute &)) &HepMC3::IntAttribute::operator=, "C++: HepMC3::IntAttribute::operator=(const class HepMC3::IntAttribute &) --> class HepMC3::IntAttribute &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // HepMC3::LongAttribute file:HepMC3/Attribute.h line:200
		pybind11::class_<HepMC3::LongAttribute, std::shared_ptr<HepMC3::LongAttribute>, PyCallBack_HepMC3_LongAttribute, HepMC3::Attribute> cl(M("HepMC3"), "LongAttribute", "Attribute that holds an Integer implemented as a long int\n\n  \n\n ");
		cl.def( pybind11::init( [](){ return new HepMC3::LongAttribute(); }, [](){ return new PyCallBack_HepMC3_LongAttribute(); } ) );
		cl.def( pybind11::init<long>(), pybind11::arg("val") );

		cl.def( pybind11::init( [](PyCallBack_HepMC3_LongAttribute const &o){ return new PyCallBack_HepMC3_LongAttribute(o); } ) );
		cl.def( pybind11::init( [](HepMC3::LongAttribute const &o){ return new HepMC3::LongAttribute(o); } ) );
		cl.def("from_string", (bool (HepMC3::LongAttribute::*)(const std::string &)) &HepMC3::LongAttribute::from_string, "Implementation of Attribute::from_string \n\nC++: HepMC3::LongAttribute::from_string(const std::string &) --> bool", pybind11::arg("att"));
		cl.def("to_string", (bool (HepMC3::LongAttribute::*)(std::string &) const) &HepMC3::LongAttribute::to_string, "Implementation of Attribute::to_string \n\nC++: HepMC3::LongAttribute::to_string(std::string &) const --> bool", pybind11::arg("att"));
		cl.def("value", (long (HepMC3::LongAttribute::*)() const) &HepMC3::LongAttribute::value, "get the value associated to this Attribute. \n\nC++: HepMC3::LongAttribute::value() const --> long");
		cl.def("set_value", (void (HepMC3::LongAttribute::*)(const long &)) &HepMC3::LongAttribute::set_value, "set the value associated to this Attribute. \n\nC++: HepMC3::LongAttribute::set_value(const long &) --> void", pybind11::arg("l"));
		cl.def("assign", (class HepMC3::LongAttribute & (HepMC3::LongAttribute::*)(const class HepMC3::LongAttribute &)) &HepMC3::LongAttribute::operator=, "C++: HepMC3::LongAttribute::operator=(const class HepMC3::LongAttribute &) --> class HepMC3::LongAttribute &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
