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
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_pyHepMC3_2(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// HepMC3::delta_phi(const class HepMC3::FourVector &, const class HepMC3::FourVector &) file:HepMC3/FourVector.h line:317
	M("HepMC3").def("delta_phi", (double (*)(const class HepMC3::FourVector &, const class HepMC3::FourVector &)) &HepMC3::delta_phi, "Signed azimuthal angle separation in [-pi, pi] between vecs  and \n\nC++: HepMC3::delta_phi(const class HepMC3::FourVector &, const class HepMC3::FourVector &) --> double", pybind11::arg("a"), pybind11::arg("b"));

	// HepMC3::delta_eta(const class HepMC3::FourVector &, const class HepMC3::FourVector &) file:HepMC3/FourVector.h line:320
	M("HepMC3").def("delta_eta", (double (*)(const class HepMC3::FourVector &, const class HepMC3::FourVector &)) &HepMC3::delta_eta, "Pseudorapidity separation between vecs  and \n\nC++: HepMC3::delta_eta(const class HepMC3::FourVector &, const class HepMC3::FourVector &) --> double", pybind11::arg("a"), pybind11::arg("b"));

	// HepMC3::delta_rap(const class HepMC3::FourVector &, const class HepMC3::FourVector &) file:HepMC3/FourVector.h line:323
	M("HepMC3").def("delta_rap", (double (*)(const class HepMC3::FourVector &, const class HepMC3::FourVector &)) &HepMC3::delta_rap, "Rapidity separation between vecs  and \n\nC++: HepMC3::delta_rap(const class HepMC3::FourVector &, const class HepMC3::FourVector &) --> double", pybind11::arg("a"), pybind11::arg("b"));

	// HepMC3::delta_r2_eta(const class HepMC3::FourVector &, const class HepMC3::FourVector &) file:HepMC3/FourVector.h line:326
	M("HepMC3").def("delta_r2_eta", (double (*)(const class HepMC3::FourVector &, const class HepMC3::FourVector &)) &HepMC3::delta_r2_eta, "R_eta^2-distance separation dR^2 = dphi^2 + deta^2 between vecs  and \n\nC++: HepMC3::delta_r2_eta(const class HepMC3::FourVector &, const class HepMC3::FourVector &) --> double", pybind11::arg("a"), pybind11::arg("b"));

	// HepMC3::delta_r_eta(const class HepMC3::FourVector &, const class HepMC3::FourVector &) file:HepMC3/FourVector.h line:329
	M("HepMC3").def("delta_r_eta", (double (*)(const class HepMC3::FourVector &, const class HepMC3::FourVector &)) &HepMC3::delta_r_eta, "R_eta-distance separation dR = sqrt(dphi^2 + deta^2) between vecs  and \n\nC++: HepMC3::delta_r_eta(const class HepMC3::FourVector &, const class HepMC3::FourVector &) --> double", pybind11::arg("a"), pybind11::arg("b"));

	// HepMC3::delta_r2_rap(const class HepMC3::FourVector &, const class HepMC3::FourVector &) file:HepMC3/FourVector.h line:332
	M("HepMC3").def("delta_r2_rap", (double (*)(const class HepMC3::FourVector &, const class HepMC3::FourVector &)) &HepMC3::delta_r2_rap, "R_rap^2-distance separation dR^2 = dphi^2 + drap^2 between vecs  and \n\nC++: HepMC3::delta_r2_rap(const class HepMC3::FourVector &, const class HepMC3::FourVector &) --> double", pybind11::arg("a"), pybind11::arg("b"));

	// HepMC3::delta_r_rap(const class HepMC3::FourVector &, const class HepMC3::FourVector &) file:HepMC3/FourVector.h line:335
	M("HepMC3").def("delta_r_rap", (double (*)(const class HepMC3::FourVector &, const class HepMC3::FourVector &)) &HepMC3::delta_r_rap, "R_rap-distance separation dR = sqrt(dphi^2 + drap^2) between vecs  and \n\nC++: HepMC3::delta_r_rap(const class HepMC3::FourVector &, const class HepMC3::FourVector &) --> double", pybind11::arg("a"), pybind11::arg("b"));

}
