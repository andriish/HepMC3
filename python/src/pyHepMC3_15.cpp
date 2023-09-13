#include <iterator>
#include <memory>
#include <sstream> // __str__
#include <string>

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

void bind_pyHepMC3_15(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // HepMC3::Units file: line:26
		pybind11::class_<HepMC3::Units, std::shared_ptr<HepMC3::Units>> cl(M("HepMC3"), "Units", "");
		cl.def( pybind11::init( [](){ return new HepMC3::Units(); } ) );

		pybind11::enum_<HepMC3::Units::MomentumUnit>(cl, "MomentumUnit", pybind11::arithmetic(), "Momentum units ")
			.value("MEV", HepMC3::Units::MEV)
			.value("GEV", HepMC3::Units::GEV)
			.export_values();


		pybind11::enum_<HepMC3::Units::LengthUnit>(cl, "LengthUnit", pybind11::arithmetic(), "Position units ")
			.value("MM", HepMC3::Units::MM)
			.value("CM", HepMC3::Units::CM)
			.export_values();

		cl.def_static("momentum_unit", (enum HepMC3::Units::MomentumUnit (*)(const std::string &)) &HepMC3::Units::momentum_unit, "Get momentum unit based on its name\n\nC++: HepMC3::Units::momentum_unit(const std::string &) --> enum HepMC3::Units::MomentumUnit", pybind11::arg("name"));
		cl.def_static("length_unit", (enum HepMC3::Units::LengthUnit (*)(const std::string &)) &HepMC3::Units::length_unit, "Get length unit based on its name\n\nC++: HepMC3::Units::length_unit(const std::string &) --> enum HepMC3::Units::LengthUnit", pybind11::arg("name"));
		cl.def_static("name", (std::string (*)(enum HepMC3::Units::MomentumUnit)) &HepMC3::Units::name, "Get name of momentum unit \n\nC++: HepMC3::Units::name(enum HepMC3::Units::MomentumUnit) --> std::string", pybind11::arg("u"));
		cl.def_static("name", (std::string (*)(enum HepMC3::Units::LengthUnit)) &HepMC3::Units::name, "Get name of length unit \n\nC++: HepMC3::Units::name(enum HepMC3::Units::LengthUnit) --> std::string", pybind11::arg("u"));

		 binder::custom_Units_binder(cl);
	}
}
