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

// HepMC3::GenHeavyIon file:HepMC3/GenHeavyIon.h line:26
struct PyCallBack_HepMC3_GenHeavyIon : public HepMC3::GenHeavyIon {
	using HepMC3::GenHeavyIon::GenHeavyIon;

	bool from_string(const std::string & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::GenHeavyIon *>(this), "from_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return GenHeavyIon::from_string(a0);
	}
	bool to_string(std::string & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::GenHeavyIon *>(this), "to_string");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return GenHeavyIon::to_string(a0);
	}
	bool init() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::GenHeavyIon *>(this), "init");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::GenHeavyIon *>(this), "init");
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

void bind_pyHepMC3_13(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // HepMC3::GenHeavyIon file:HepMC3/GenHeavyIon.h line:26
		pybind11::class_<HepMC3::GenHeavyIon, std::shared_ptr<HepMC3::GenHeavyIon>, PyCallBack_HepMC3_GenHeavyIon, HepMC3::Attribute> cl(M("HepMC3"), "GenHeavyIon", "");
		cl.def( pybind11::init( [](){ return new HepMC3::GenHeavyIon(); }, [](){ return new PyCallBack_HepMC3_GenHeavyIon(); } ) );
		cl.def( pybind11::init( [](PyCallBack_HepMC3_GenHeavyIon const &o){ return new PyCallBack_HepMC3_GenHeavyIon(o); } ) );
		cl.def( pybind11::init( [](HepMC3::GenHeavyIon const &o){ return new HepMC3::GenHeavyIon(o); } ) );
		cl.def_readwrite("Ncoll_hard", &HepMC3::GenHeavyIon::Ncoll_hard);
		cl.def_readwrite("Npart_proj", &HepMC3::GenHeavyIon::Npart_proj);
		cl.def_readwrite("Npart_targ", &HepMC3::GenHeavyIon::Npart_targ);
		cl.def_readwrite("Ncoll", &HepMC3::GenHeavyIon::Ncoll);
		cl.def_readwrite("spectator_neutrons", &HepMC3::GenHeavyIon::spectator_neutrons);
		cl.def_readwrite("spectator_protons", &HepMC3::GenHeavyIon::spectator_protons);
		cl.def_readwrite("N_Nwounded_collisions", &HepMC3::GenHeavyIon::N_Nwounded_collisions);
		cl.def_readwrite("Nwounded_N_collisions", &HepMC3::GenHeavyIon::Nwounded_N_collisions);
		cl.def_readwrite("Nwounded_Nwounded_collisions", &HepMC3::GenHeavyIon::Nwounded_Nwounded_collisions);
		cl.def_readwrite("impact_parameter", &HepMC3::GenHeavyIon::impact_parameter);
		cl.def_readwrite("event_plane_angle", &HepMC3::GenHeavyIon::event_plane_angle);
		cl.def_readwrite("eccentricity", &HepMC3::GenHeavyIon::eccentricity);
		cl.def_readwrite("sigma_inel_NN", &HepMC3::GenHeavyIon::sigma_inel_NN);
		cl.def_readwrite("centrality", &HepMC3::GenHeavyIon::centrality);
		cl.def_readwrite("user_cent_estimate", &HepMC3::GenHeavyIon::user_cent_estimate);
		cl.def_readwrite("Nspec_proj_n", &HepMC3::GenHeavyIon::Nspec_proj_n);
		cl.def_readwrite("Nspec_targ_n", &HepMC3::GenHeavyIon::Nspec_targ_n);
		cl.def_readwrite("Nspec_proj_p", &HepMC3::GenHeavyIon::Nspec_proj_p);
		cl.def_readwrite("Nspec_targ_p", &HepMC3::GenHeavyIon::Nspec_targ_p);
		cl.def_readwrite("participant_plane_angles", &HepMC3::GenHeavyIon::participant_plane_angles);
		cl.def_readwrite("eccentricities", &HepMC3::GenHeavyIon::eccentricities);
		cl.def_readwrite("forceoldformat", &HepMC3::GenHeavyIon::forceoldformat);
		cl.def("from_string", (bool (HepMC3::GenHeavyIon::*)(const std::string &)) &HepMC3::GenHeavyIon::from_string, "Implementation of Attribute::from_string.\n\nC++: HepMC3::GenHeavyIon::from_string(const std::string &) --> bool", pybind11::arg("att"));
		cl.def("to_string", (bool (HepMC3::GenHeavyIon::*)(std::string &) const) &HepMC3::GenHeavyIon::to_string, "Implementation of Attribute::to_string.\n\nC++: HepMC3::GenHeavyIon::to_string(std::string &) const --> bool", pybind11::arg("att"));
		cl.def("__eq__", (bool (HepMC3::GenHeavyIon::*)(const class HepMC3::GenHeavyIon &) const) &HepMC3::GenHeavyIon::operator==, "Operator ==\n\nC++: HepMC3::GenHeavyIon::operator==(const class HepMC3::GenHeavyIon &) const --> bool", pybind11::arg(""));
		cl.def("__ne__", (bool (HepMC3::GenHeavyIon::*)(const class HepMC3::GenHeavyIon &) const) &HepMC3::GenHeavyIon::operator!=, "Operator !=\n\nC++: HepMC3::GenHeavyIon::operator!=(const class HepMC3::GenHeavyIon &) const --> bool", pybind11::arg(""));
		cl.def("set", [](HepMC3::GenHeavyIon &o, const int & a0, const int & a1, const int & a2, const int & a3, const int & a4, const int & a5) -> void { return o.set(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("nh"), pybind11::arg("np"), pybind11::arg("nt"), pybind11::arg("nc"), pybind11::arg("ns"), pybind11::arg("nsp"));
		cl.def("set", [](HepMC3::GenHeavyIon &o, const int & a0, const int & a1, const int & a2, const int & a3, const int & a4, const int & a5, const int & a6) -> void { return o.set(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("nh"), pybind11::arg("np"), pybind11::arg("nt"), pybind11::arg("nc"), pybind11::arg("ns"), pybind11::arg("nsp"), pybind11::arg("nnw"));
		cl.def("set", [](HepMC3::GenHeavyIon &o, const int & a0, const int & a1, const int & a2, const int & a3, const int & a4, const int & a5, const int & a6, const int & a7) -> void { return o.set(a0, a1, a2, a3, a4, a5, a6, a7); }, "", pybind11::arg("nh"), pybind11::arg("np"), pybind11::arg("nt"), pybind11::arg("nc"), pybind11::arg("ns"), pybind11::arg("nsp"), pybind11::arg("nnw"), pybind11::arg("nwn"));
		cl.def("set", [](HepMC3::GenHeavyIon &o, const int & a0, const int & a1, const int & a2, const int & a3, const int & a4, const int & a5, const int & a6, const int & a7, const int & a8) -> void { return o.set(a0, a1, a2, a3, a4, a5, a6, a7, a8); }, "", pybind11::arg("nh"), pybind11::arg("np"), pybind11::arg("nt"), pybind11::arg("nc"), pybind11::arg("ns"), pybind11::arg("nsp"), pybind11::arg("nnw"), pybind11::arg("nwn"), pybind11::arg("nwnw"));
		cl.def("set", [](HepMC3::GenHeavyIon &o, const int & a0, const int & a1, const int & a2, const int & a3, const int & a4, const int & a5, const int & a6, const int & a7, const int & a8, const double & a9) -> void { return o.set(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9); }, "", pybind11::arg("nh"), pybind11::arg("np"), pybind11::arg("nt"), pybind11::arg("nc"), pybind11::arg("ns"), pybind11::arg("nsp"), pybind11::arg("nnw"), pybind11::arg("nwn"), pybind11::arg("nwnw"), pybind11::arg("im"));
		cl.def("set", [](HepMC3::GenHeavyIon &o, const int & a0, const int & a1, const int & a2, const int & a3, const int & a4, const int & a5, const int & a6, const int & a7, const int & a8, const double & a9, const double & a10) -> void { return o.set(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); }, "", pybind11::arg("nh"), pybind11::arg("np"), pybind11::arg("nt"), pybind11::arg("nc"), pybind11::arg("ns"), pybind11::arg("nsp"), pybind11::arg("nnw"), pybind11::arg("nwn"), pybind11::arg("nwnw"), pybind11::arg("im"), pybind11::arg("pl"));
		cl.def("set", [](HepMC3::GenHeavyIon &o, const int & a0, const int & a1, const int & a2, const int & a3, const int & a4, const int & a5, const int & a6, const int & a7, const int & a8, const double & a9, const double & a10, const double & a11) -> void { return o.set(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); }, "", pybind11::arg("nh"), pybind11::arg("np"), pybind11::arg("nt"), pybind11::arg("nc"), pybind11::arg("ns"), pybind11::arg("nsp"), pybind11::arg("nnw"), pybind11::arg("nwn"), pybind11::arg("nwnw"), pybind11::arg("im"), pybind11::arg("pl"), pybind11::arg("ec"));
		cl.def("set", [](HepMC3::GenHeavyIon &o, const int & a0, const int & a1, const int & a2, const int & a3, const int & a4, const int & a5, const int & a6, const int & a7, const int & a8, const double & a9, const double & a10, const double & a11, const double & a12) -> void { return o.set(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12); }, "", pybind11::arg("nh"), pybind11::arg("np"), pybind11::arg("nt"), pybind11::arg("nc"), pybind11::arg("ns"), pybind11::arg("nsp"), pybind11::arg("nnw"), pybind11::arg("nwn"), pybind11::arg("nwnw"), pybind11::arg("im"), pybind11::arg("pl"), pybind11::arg("ec"), pybind11::arg("s"));
		cl.def("set", [](HepMC3::GenHeavyIon &o, const int & a0, const int & a1, const int & a2, const int & a3, const int & a4, const int & a5, const int & a6, const int & a7, const int & a8, const double & a9, const double & a10, const double & a11, const double & a12, const double & a13) -> void { return o.set(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13); }, "", pybind11::arg("nh"), pybind11::arg("np"), pybind11::arg("nt"), pybind11::arg("nc"), pybind11::arg("ns"), pybind11::arg("nsp"), pybind11::arg("nnw"), pybind11::arg("nwn"), pybind11::arg("nwnw"), pybind11::arg("im"), pybind11::arg("pl"), pybind11::arg("ec"), pybind11::arg("s"), pybind11::arg("cent"));
		cl.def("set", (void (HepMC3::GenHeavyIon::*)(const int &, const int &, const int &, const int &, const int &, const int &, const int &, const int &, const int &, const double &, const double &, const double &, const double &, const double &, const double &)) &HepMC3::GenHeavyIon::set, "Set all fields.\n\n HEPMC3_DEPRECATED(\"Set individual fields directly instead.\")\n \n\n Set all fields \n\nC++: HepMC3::GenHeavyIon::set(const int &, const int &, const int &, const int &, const int &, const int &, const int &, const int &, const int &, const double &, const double &, const double &, const double &, const double &, const double &) --> void", pybind11::arg("nh"), pybind11::arg("np"), pybind11::arg("nt"), pybind11::arg("nc"), pybind11::arg("ns"), pybind11::arg("nsp"), pybind11::arg("nnw"), pybind11::arg("nwn"), pybind11::arg("nwnw"), pybind11::arg("im"), pybind11::arg("pl"), pybind11::arg("ec"), pybind11::arg("s"), pybind11::arg("cent"), pybind11::arg("usrcent"));
		cl.def("is_valid", (bool (HepMC3::GenHeavyIon::*)() const) &HepMC3::GenHeavyIon::is_valid, "Verify that the instance contains non-zero information.\n\n HEPMC3_DEPRECATED(\"Each filed now have default values meaning\n that they have not been set\")\n\nC++: HepMC3::GenHeavyIon::is_valid() const --> bool");
		cl.def("assign", (class HepMC3::GenHeavyIon & (HepMC3::GenHeavyIon::*)(const class HepMC3::GenHeavyIon &)) &HepMC3::GenHeavyIon::operator=, "C++: HepMC3::GenHeavyIon::operator=(const class HepMC3::GenHeavyIon &) --> class HepMC3::GenHeavyIon &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
