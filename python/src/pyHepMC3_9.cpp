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

// HepMC3::BoolAttribute file:HepMC3/Attribute.h line:660
struct PyCallBack_HepMC3_BoolAttribute : public HepMC3::BoolAttribute {
	using HepMC3::BoolAttribute::BoolAttribute;

	bool from_string(const std::string & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::BoolAttribute *>(this), "from_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return BoolAttribute::from_string(a0);
	}
	bool to_string(std::string & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::BoolAttribute *>(this), "to_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return BoolAttribute::to_string(a0);
	}
	bool init() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::BoolAttribute *>(this), "init");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::BoolAttribute *>(this), "init");
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

// HepMC3::VectorCharAttribute file:HepMC3/Attribute.h line:705
struct PyCallBack_HepMC3_VectorCharAttribute : public HepMC3::VectorCharAttribute {
	using HepMC3::VectorCharAttribute::VectorCharAttribute;

	bool from_string(const std::string & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorCharAttribute *>(this), "from_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return VectorCharAttribute::from_string(a0);
	}
	bool to_string(std::string & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorCharAttribute *>(this), "to_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return VectorCharAttribute::to_string(a0);
	}
	bool init() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorCharAttribute *>(this), "init");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorCharAttribute *>(this), "init");
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

// HepMC3::VectorFloatAttribute file:HepMC3/Attribute.h line:753
struct PyCallBack_HepMC3_VectorFloatAttribute : public HepMC3::VectorFloatAttribute {
	using HepMC3::VectorFloatAttribute::VectorFloatAttribute;

	bool from_string(const std::string & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorFloatAttribute *>(this), "from_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return VectorFloatAttribute::from_string(a0);
	}
	bool to_string(std::string & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorFloatAttribute *>(this), "to_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return VectorFloatAttribute::to_string(a0);
	}
	bool init() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorFloatAttribute *>(this), "init");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorFloatAttribute *>(this), "init");
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

void bind_pyHepMC3_9(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // HepMC3::BoolAttribute file:HepMC3/Attribute.h line:660
		pybind11::class_<HepMC3::BoolAttribute, std::shared_ptr<HepMC3::BoolAttribute>, PyCallBack_HepMC3_BoolAttribute, HepMC3::Attribute> cl(M("HepMC3"), "BoolAttribute", "Attribute that holds an Booleger implemented as an int\n\n  ");
		cl.def( pybind11::init( [](){ return new HepMC3::BoolAttribute(); }, [](){ return new PyCallBack_HepMC3_BoolAttribute(); } ) );
		cl.def( pybind11::init<bool>(), pybind11::arg("val") );

		cl.def( pybind11::init( [](PyCallBack_HepMC3_BoolAttribute const &o){ return new PyCallBack_HepMC3_BoolAttribute(o); } ) );
		cl.def( pybind11::init( [](HepMC3::BoolAttribute const &o){ return new HepMC3::BoolAttribute(o); } ) );
		cl.def("from_string", (bool (HepMC3::BoolAttribute::*)(const std::string &)) &HepMC3::BoolAttribute::from_string, "Implementation of Attribute::from_string \n\nC++: HepMC3::BoolAttribute::from_string(const std::string &) --> bool", pybind11::arg("att"));
		cl.def("to_string", (bool (HepMC3::BoolAttribute::*)(std::string &) const) &HepMC3::BoolAttribute::to_string, "Implementation of Attribute::to_string \n\nC++: HepMC3::BoolAttribute::to_string(std::string &) const --> bool", pybind11::arg("att"));
		cl.def("value", (bool (HepMC3::BoolAttribute::*)() const) &HepMC3::BoolAttribute::value, "get the value associated to this Attribute. \n\nC++: HepMC3::BoolAttribute::value() const --> bool");
		cl.def("set_value", (void (HepMC3::BoolAttribute::*)(const bool &)) &HepMC3::BoolAttribute::set_value, "set the value associated to this Attribute. \n\nC++: HepMC3::BoolAttribute::set_value(const bool &) --> void", pybind11::arg("i"));
		cl.def("assign", (class HepMC3::BoolAttribute & (HepMC3::BoolAttribute::*)(const class HepMC3::BoolAttribute &)) &HepMC3::BoolAttribute::operator=, "C++: HepMC3::BoolAttribute::operator=(const class HepMC3::BoolAttribute &) --> class HepMC3::BoolAttribute &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // HepMC3::VectorCharAttribute file:HepMC3/Attribute.h line:705
		pybind11::class_<HepMC3::VectorCharAttribute, std::shared_ptr<HepMC3::VectorCharAttribute>, PyCallBack_HepMC3_VectorCharAttribute, HepMC3::Attribute> cl(M("HepMC3"), "VectorCharAttribute", "Attribute that holds a vector of characters of type  char\n\n  \n\n ");
		cl.def( pybind11::init( [](){ return new HepMC3::VectorCharAttribute(); }, [](){ return new PyCallBack_HepMC3_VectorCharAttribute(); } ) );
		cl.def( pybind11::init<class std::vector<char>>(), pybind11::arg("val") );

		cl.def( pybind11::init( [](PyCallBack_HepMC3_VectorCharAttribute const &o){ return new PyCallBack_HepMC3_VectorCharAttribute(o); } ) );
		cl.def( pybind11::init( [](HepMC3::VectorCharAttribute const &o){ return new HepMC3::VectorCharAttribute(o); } ) );
		cl.def("from_string", (bool (HepMC3::VectorCharAttribute::*)(const std::string &)) &HepMC3::VectorCharAttribute::from_string, "Implementation of Attribute::from_string \n\nC++: HepMC3::VectorCharAttribute::from_string(const std::string &) --> bool", pybind11::arg("att"));
		cl.def("to_string", (bool (HepMC3::VectorCharAttribute::*)(std::string &) const) &HepMC3::VectorCharAttribute::to_string, "Implementation of Attribute::to_string \n\nC++: HepMC3::VectorCharAttribute::to_string(std::string &) const --> bool", pybind11::arg("att"));
		cl.def("value", (class std::vector<char> (HepMC3::VectorCharAttribute::*)() const) &HepMC3::VectorCharAttribute::value, "get the value associated to this Attribute. \n\nC++: HepMC3::VectorCharAttribute::value() const --> class std::vector<char>");
		cl.def("set_value", (void (HepMC3::VectorCharAttribute::*)(const class std::vector<char> &)) &HepMC3::VectorCharAttribute::set_value, "set the value associated to this Attribute. \n\nC++: HepMC3::VectorCharAttribute::set_value(const class std::vector<char> &) --> void", pybind11::arg("i"));
		cl.def("assign", (class HepMC3::VectorCharAttribute & (HepMC3::VectorCharAttribute::*)(const class HepMC3::VectorCharAttribute &)) &HepMC3::VectorCharAttribute::operator=, "C++: HepMC3::VectorCharAttribute::operator=(const class HepMC3::VectorCharAttribute &) --> class HepMC3::VectorCharAttribute &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // HepMC3::VectorFloatAttribute file:HepMC3/Attribute.h line:753
		pybind11::class_<HepMC3::VectorFloatAttribute, std::shared_ptr<HepMC3::VectorFloatAttribute>, PyCallBack_HepMC3_VectorFloatAttribute, HepMC3::Attribute> cl(M("HepMC3"), "VectorFloatAttribute", "Attribute that holds a vector of real numbers of type float\n\n  \n\n ");
		cl.def( pybind11::init( [](){ return new HepMC3::VectorFloatAttribute(); }, [](){ return new PyCallBack_HepMC3_VectorFloatAttribute(); } ) );
		cl.def( pybind11::init<class std::vector<float>>(), pybind11::arg("val") );

		cl.def( pybind11::init( [](PyCallBack_HepMC3_VectorFloatAttribute const &o){ return new PyCallBack_HepMC3_VectorFloatAttribute(o); } ) );
		cl.def( pybind11::init( [](HepMC3::VectorFloatAttribute const &o){ return new HepMC3::VectorFloatAttribute(o); } ) );
		cl.def("from_string", (bool (HepMC3::VectorFloatAttribute::*)(const std::string &)) &HepMC3::VectorFloatAttribute::from_string, "Implementation of Attribute::from_string \n\nC++: HepMC3::VectorFloatAttribute::from_string(const std::string &) --> bool", pybind11::arg("att"));
		cl.def("to_string", (bool (HepMC3::VectorFloatAttribute::*)(std::string &) const) &HepMC3::VectorFloatAttribute::to_string, "Implementation of Attribute::to_string \n\nC++: HepMC3::VectorFloatAttribute::to_string(std::string &) const --> bool", pybind11::arg("att"));
		cl.def("value", (class std::vector<float> (HepMC3::VectorFloatAttribute::*)() const) &HepMC3::VectorFloatAttribute::value, "get the value associated to this Attribute. \n\nC++: HepMC3::VectorFloatAttribute::value() const --> class std::vector<float>");
		cl.def("set_value", (void (HepMC3::VectorFloatAttribute::*)(const class std::vector<float> &)) &HepMC3::VectorFloatAttribute::set_value, "set the value associated to this Attribute. \n\nC++: HepMC3::VectorFloatAttribute::set_value(const class std::vector<float> &) --> void", pybind11::arg("i"));
		cl.def("assign", (class HepMC3::VectorFloatAttribute & (HepMC3::VectorFloatAttribute::*)(const class HepMC3::VectorFloatAttribute &)) &HepMC3::VectorFloatAttribute::operator=, "C++: HepMC3::VectorFloatAttribute::operator=(const class HepMC3::VectorFloatAttribute &) --> class HepMC3::VectorFloatAttribute &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
