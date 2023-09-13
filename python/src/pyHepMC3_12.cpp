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

// HepMC3::VectorLongIntAttribute file:HepMC3/Attribute.h line:1087
struct PyCallBack_HepMC3_VectorLongIntAttribute : public HepMC3::VectorLongIntAttribute {
	using HepMC3::VectorLongIntAttribute::VectorLongIntAttribute;

	bool from_string(const std::string & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorLongIntAttribute *>(this), "from_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return VectorLongIntAttribute::from_string(a0);
	}
	bool to_string(std::string & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorLongIntAttribute *>(this), "to_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return VectorLongIntAttribute::to_string(a0);
	}
	bool init() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorLongIntAttribute *>(this), "init");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorLongIntAttribute *>(this), "init");
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

// HepMC3::VectorDoubleAttribute file:HepMC3/Attribute.h line:1134
struct PyCallBack_HepMC3_VectorDoubleAttribute : public HepMC3::VectorDoubleAttribute {
	using HepMC3::VectorDoubleAttribute::VectorDoubleAttribute;

	bool from_string(const std::string & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorDoubleAttribute *>(this), "from_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return VectorDoubleAttribute::from_string(a0);
	}
	bool to_string(std::string & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorDoubleAttribute *>(this), "to_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return VectorDoubleAttribute::to_string(a0);
	}
	bool init() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorDoubleAttribute *>(this), "init");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorDoubleAttribute *>(this), "init");
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

// HepMC3::VectorStringAttribute file:HepMC3/Attribute.h line:1182
struct PyCallBack_HepMC3_VectorStringAttribute : public HepMC3::VectorStringAttribute {
	using HepMC3::VectorStringAttribute::VectorStringAttribute;

	bool from_string(const std::string & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorStringAttribute *>(this), "from_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return VectorStringAttribute::from_string(a0);
	}
	bool to_string(std::string & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorStringAttribute *>(this), "to_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return VectorStringAttribute::to_string(a0);
	}
	bool init() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorStringAttribute *>(this), "init");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::VectorStringAttribute *>(this), "init");
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

void bind_pyHepMC3_12(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // HepMC3::VectorLongIntAttribute file:HepMC3/Attribute.h line:1087
		pybind11::class_<HepMC3::VectorLongIntAttribute, std::shared_ptr<HepMC3::VectorLongIntAttribute>, PyCallBack_HepMC3_VectorLongIntAttribute, HepMC3::Attribute> cl(M("HepMC3"), "VectorLongIntAttribute", "Attribute that holds a vector of integers of type long int\n\n  \n\n ");
		cl.def( pybind11::init( [](){ return new HepMC3::VectorLongIntAttribute(); }, [](){ return new PyCallBack_HepMC3_VectorLongIntAttribute(); } ) );
		cl.def( pybind11::init<class std::vector<long>>(), pybind11::arg("val") );

		cl.def( pybind11::init( [](PyCallBack_HepMC3_VectorLongIntAttribute const &o){ return new PyCallBack_HepMC3_VectorLongIntAttribute(o); } ) );
		cl.def( pybind11::init( [](HepMC3::VectorLongIntAttribute const &o){ return new HepMC3::VectorLongIntAttribute(o); } ) );
		cl.def("from_string", (bool (HepMC3::VectorLongIntAttribute::*)(const std::string &)) &HepMC3::VectorLongIntAttribute::from_string, "Implementation of Attribute::from_string \n\nC++: HepMC3::VectorLongIntAttribute::from_string(const std::string &) --> bool", pybind11::arg("att"));
		cl.def("to_string", (bool (HepMC3::VectorLongIntAttribute::*)(std::string &) const) &HepMC3::VectorLongIntAttribute::to_string, "Implementation of Attribute::to_string \n\nC++: HepMC3::VectorLongIntAttribute::to_string(std::string &) const --> bool", pybind11::arg("att"));
		cl.def("value", (class std::vector<long> (HepMC3::VectorLongIntAttribute::*)() const) &HepMC3::VectorLongIntAttribute::value, "get the value associated to this Attribute. \n\nC++: HepMC3::VectorLongIntAttribute::value() const --> class std::vector<long>");
		cl.def("set_value", (void (HepMC3::VectorLongIntAttribute::*)(const class std::vector<long> &)) &HepMC3::VectorLongIntAttribute::set_value, "set the value associated to this Attribute. \n\nC++: HepMC3::VectorLongIntAttribute::set_value(const class std::vector<long> &) --> void", pybind11::arg("i"));
		cl.def("assign", (class HepMC3::VectorLongIntAttribute & (HepMC3::VectorLongIntAttribute::*)(const class HepMC3::VectorLongIntAttribute &)) &HepMC3::VectorLongIntAttribute::operator=, "C++: HepMC3::VectorLongIntAttribute::operator=(const class HepMC3::VectorLongIntAttribute &) --> class HepMC3::VectorLongIntAttribute &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // HepMC3::VectorDoubleAttribute file:HepMC3/Attribute.h line:1134
		pybind11::class_<HepMC3::VectorDoubleAttribute, std::shared_ptr<HepMC3::VectorDoubleAttribute>, PyCallBack_HepMC3_VectorDoubleAttribute, HepMC3::Attribute> cl(M("HepMC3"), "VectorDoubleAttribute", "Attribute that holds a vector of real numbers of type  double\n\n  \n\n ");
		cl.def( pybind11::init( [](){ return new HepMC3::VectorDoubleAttribute(); }, [](){ return new PyCallBack_HepMC3_VectorDoubleAttribute(); } ) );
		cl.def( pybind11::init<class std::vector<double>>(), pybind11::arg("val") );

		cl.def( pybind11::init( [](PyCallBack_HepMC3_VectorDoubleAttribute const &o){ return new PyCallBack_HepMC3_VectorDoubleAttribute(o); } ) );
		cl.def( pybind11::init( [](HepMC3::VectorDoubleAttribute const &o){ return new HepMC3::VectorDoubleAttribute(o); } ) );
		cl.def("from_string", (bool (HepMC3::VectorDoubleAttribute::*)(const std::string &)) &HepMC3::VectorDoubleAttribute::from_string, "Implementation of Attribute::from_string \n\nC++: HepMC3::VectorDoubleAttribute::from_string(const std::string &) --> bool", pybind11::arg("att"));
		cl.def("to_string", (bool (HepMC3::VectorDoubleAttribute::*)(std::string &) const) &HepMC3::VectorDoubleAttribute::to_string, "Implementation of Attribute::to_string \n\nC++: HepMC3::VectorDoubleAttribute::to_string(std::string &) const --> bool", pybind11::arg("att"));
		cl.def("value", (class std::vector<double> (HepMC3::VectorDoubleAttribute::*)() const) &HepMC3::VectorDoubleAttribute::value, "get the value associated to this Attribute. \n\nC++: HepMC3::VectorDoubleAttribute::value() const --> class std::vector<double>");
		cl.def("set_value", (void (HepMC3::VectorDoubleAttribute::*)(const class std::vector<double> &)) &HepMC3::VectorDoubleAttribute::set_value, "set the value associated to this Attribute. \n\nC++: HepMC3::VectorDoubleAttribute::set_value(const class std::vector<double> &) --> void", pybind11::arg("i"));
		cl.def("assign", (class HepMC3::VectorDoubleAttribute & (HepMC3::VectorDoubleAttribute::*)(const class HepMC3::VectorDoubleAttribute &)) &HepMC3::VectorDoubleAttribute::operator=, "C++: HepMC3::VectorDoubleAttribute::operator=(const class HepMC3::VectorDoubleAttribute &) --> class HepMC3::VectorDoubleAttribute &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // HepMC3::VectorStringAttribute file:HepMC3/Attribute.h line:1182
		pybind11::class_<HepMC3::VectorStringAttribute, std::shared_ptr<HepMC3::VectorStringAttribute>, PyCallBack_HepMC3_VectorStringAttribute, HepMC3::Attribute> cl(M("HepMC3"), "VectorStringAttribute", "Attribute that holds a vector of type  string\n\n  \n\n ");
		cl.def( pybind11::init( [](){ return new HepMC3::VectorStringAttribute(); }, [](){ return new PyCallBack_HepMC3_VectorStringAttribute(); } ) );
		cl.def( pybind11::init<class std::vector<std::string >>(), pybind11::arg("val") );

		cl.def( pybind11::init( [](PyCallBack_HepMC3_VectorStringAttribute const &o){ return new PyCallBack_HepMC3_VectorStringAttribute(o); } ) );
		cl.def( pybind11::init( [](HepMC3::VectorStringAttribute const &o){ return new HepMC3::VectorStringAttribute(o); } ) );
		cl.def("from_string", (bool (HepMC3::VectorStringAttribute::*)(const std::string &)) &HepMC3::VectorStringAttribute::from_string, "Implementation of Attribute::from_string \n\nC++: HepMC3::VectorStringAttribute::from_string(const std::string &) --> bool", pybind11::arg("att"));
		cl.def("to_string", (bool (HepMC3::VectorStringAttribute::*)(std::string &) const) &HepMC3::VectorStringAttribute::to_string, "Implementation of Attribute::to_string \n\nC++: HepMC3::VectorStringAttribute::to_string(std::string &) const --> bool", pybind11::arg("att"));
		cl.def("value", (class std::vector<std::string > (HepMC3::VectorStringAttribute::*)() const) &HepMC3::VectorStringAttribute::value, "get the value associated to this Attribute. \n\nC++: HepMC3::VectorStringAttribute::value() const --> class std::vector<std::string >");
		cl.def("set_value", (void (HepMC3::VectorStringAttribute::*)(const class std::vector<std::string > &)) &HepMC3::VectorStringAttribute::set_value, "set the value associated to this Attribute. \n\nC++: HepMC3::VectorStringAttribute::set_value(const class std::vector<std::string > &) --> void", pybind11::arg("i"));
		cl.def("assign", (class HepMC3::VectorStringAttribute & (HepMC3::VectorStringAttribute::*)(const class HepMC3::VectorStringAttribute &)) &HepMC3::VectorStringAttribute::operator=, "C++: HepMC3::VectorStringAttribute::operator=(const class HepMC3::VectorStringAttribute &) --> class HepMC3::VectorStringAttribute &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
