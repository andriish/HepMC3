#include <ios>

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

void bind_pyHepMC3_0(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// std::_Ios_Iostate file:bits/ios_base.h line:154
	pybind11::enum_<std::_Ios_Iostate>(M("std"), "_Ios_Iostate", pybind11::arithmetic(), "")
		.value("_S_goodbit", std::_S_goodbit)
		.value("_S_badbit", std::_S_badbit)
		.value("_S_eofbit", std::_S_eofbit)
		.value("_S_failbit", std::_S_failbit)
		.value("_S_ios_iostate_end", std::_S_ios_iostate_end)
		.value("_S_ios_iostate_max", std::_S_ios_iostate_max)
		.value("_S_ios_iostate_min", std::_S_ios_iostate_min)
		.export_values();

;

}
