#include <HepMC3/FourVector.h>

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
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>, false)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*, false)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_pyHepMC3_2(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// HepMC3::delta_r_rap(const class HepMC3::FourVector &, const class HepMC3::FourVector &) file:HepMC3/FourVector.h line:
	M("HepMC3").def("delta_r_rap", (double (*)(const class HepMC3::FourVector &, const class HepMC3::FourVector &)) &HepMC3::delta_r_rap, "R_rap-distance separation dR = sqrt(dphi^2 + drap^2) between vecs  and \n\nC++: HepMC3::delta_r_rap(const class HepMC3::FourVector &, const class HepMC3::FourVector &) --> double", pybind11::arg("a"), pybind11::arg("b"));

}
