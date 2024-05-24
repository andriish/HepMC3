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
#include <HepMC3/HEPEVT_Wrapper_Runtime.h>
#include <HepMC3/Reader.h>
#include <HepMC3/ReaderHEPEVT.h>
#include <HepMC3/Writer.h>
#include <HepMC3/WriterHEPEVT.h>
#include <functional>
#include <ios>
#include <istream>
#include <iterator>
#include <map>
#include <memory>
#include <ostream>
#include <sstream> // __str__
#include <streambuf>
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
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>, false)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*, false)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

// HepMC3::WriterHEPEVT file:HepMC3/WriterHEPEVT.h line:
struct PyCallBack_HepMC3_WriterHEPEVT : public HepMC3::WriterHEPEVT {
	using HepMC3::WriterHEPEVT::WriterHEPEVT;

	void write_hepevt_particle(int a0, bool a1) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::WriterHEPEVT *>(this), "write_hepevt_particle");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return WriterHEPEVT::write_hepevt_particle(a0, a1);
	}
	void write_hepevt_event_header() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::WriterHEPEVT *>(this), "write_hepevt_event_header");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return WriterHEPEVT::write_hepevt_event_header();
	}
	void write_event(const class HepMC3::GenEvent & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::WriterHEPEVT *>(this), "write_event");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return WriterHEPEVT::write_event(a0);
	}
	void close() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::WriterHEPEVT *>(this), "close");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return WriterHEPEVT::close();
	}
	bool failed() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::WriterHEPEVT *>(this), "failed");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return WriterHEPEVT::failed();
	}
	void set_run_info(class std::shared_ptr<class HepMC3::GenRunInfo> a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::WriterHEPEVT *>(this), "set_run_info");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return Writer::set_run_info(a0);
	}
	class std::shared_ptr<class HepMC3::GenRunInfo> run_info() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::WriterHEPEVT *>(this), "run_info");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<class std::shared_ptr<class HepMC3::GenRunInfo>>::value) {
				static pybind11::detail::override_caster_t<class std::shared_ptr<class HepMC3::GenRunInfo>> caster;
				return pybind11::detail::cast_ref<class std::shared_ptr<class HepMC3::GenRunInfo>>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<class std::shared_ptr<class HepMC3::GenRunInfo>>(std::move(o));
		}
		return Writer::run_info();
	}
	void set_options(const class std::map<std::string, std::string > & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::WriterHEPEVT *>(this), "set_options");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return Writer::set_options(a0);
	}
	using _binder_ret_0 = std::map<std::string, std::string >;
	_binder_ret_0 get_options() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::WriterHEPEVT *>(this), "get_options");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<_binder_ret_0>::value) {
				static pybind11::detail::override_caster_t<_binder_ret_0> caster;
				return pybind11::detail::cast_ref<_binder_ret_0>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<_binder_ret_0>(std::move(o));
		}
		return Writer::get_options();
	}
};

// HepMC3::ReaderHEPEVT file:HepMC3/ReaderHEPEVT.h line:
struct PyCallBack_HepMC3_ReaderHEPEVT : public HepMC3::ReaderHEPEVT {
	using HepMC3::ReaderHEPEVT::ReaderHEPEVT;

	bool read_hepevt_event_header() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::ReaderHEPEVT *>(this), "read_hepevt_event_header");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return ReaderHEPEVT::read_hepevt_event_header();
	}
	bool read_hepevt_particle(int a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::ReaderHEPEVT *>(this), "read_hepevt_particle");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return ReaderHEPEVT::read_hepevt_particle(a0);
	}
	bool skip(const int a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::ReaderHEPEVT *>(this), "skip");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return ReaderHEPEVT::skip(a0);
	}
	bool read_event(class HepMC3::GenEvent & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::ReaderHEPEVT *>(this), "read_event");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return ReaderHEPEVT::read_event(a0);
	}
	void close() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::ReaderHEPEVT *>(this), "close");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return ReaderHEPEVT::close();
	}
	bool failed() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::ReaderHEPEVT *>(this), "failed");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return ReaderHEPEVT::failed();
	}
	class std::shared_ptr<class HepMC3::GenRunInfo> run_info() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::ReaderHEPEVT *>(this), "run_info");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<class std::shared_ptr<class HepMC3::GenRunInfo>>::value) {
				static pybind11::detail::override_caster_t<class std::shared_ptr<class HepMC3::GenRunInfo>> caster;
				return pybind11::detail::cast_ref<class std::shared_ptr<class HepMC3::GenRunInfo>>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<class std::shared_ptr<class HepMC3::GenRunInfo>>(std::move(o));
		}
		return Reader::run_info();
	}
	void set_options(const class std::map<std::string, std::string > & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::ReaderHEPEVT *>(this), "set_options");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return Reader::set_options(a0);
	}
	using _binder_ret_0 = std::map<std::string, std::string >;
	_binder_ret_0 get_options() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::ReaderHEPEVT *>(this), "get_options");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<_binder_ret_0>::value) {
				static pybind11::detail::override_caster_t<_binder_ret_0> caster;
				return pybind11::detail::cast_ref<_binder_ret_0>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<_binder_ret_0>(std::move(o));
		}
		return Reader::get_options();
	}
	void set_run_info(class std::shared_ptr<class HepMC3::GenRunInfo> a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const HepMC3::ReaderHEPEVT *>(this), "set_run_info");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return Reader::set_run_info(a0);
	}
};

void bind_pyHepMC3_14(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
<<<<<<< HEAD
	{ // HepMC3::HEPEVT_Pointers file: line:
		pybind11::class_<HepMC3::HEPEVT_Pointers<double>, std::shared_ptr<HepMC3::HEPEVT_Pointers<double>>> cl(M("HepMC3"), "HEPEVT_Pointers_double_t", "");
		cl.def( pybind11::init( [](){ return new HepMC3::HEPEVT_Pointers<double>(); } ) );
	}
	{ // HepMC3::GenParticlePtr_greater file: line:
		pybind11::class_<HepMC3::GenParticlePtr_greater, std::shared_ptr<HepMC3::GenParticlePtr_greater>> cl(M("HepMC3"), "GenParticlePtr_greater", "comparison of two particles ");
		cl.def( pybind11::init( [](){ return new HepMC3::GenParticlePtr_greater(); } ) );
		cl.def( pybind11::init( [](HepMC3::GenParticlePtr_greater const &o){ return new HepMC3::GenParticlePtr_greater(o); } ) );
		cl.def("__call__", (bool (HepMC3::GenParticlePtr_greater::*)(class std::shared_ptr<const class HepMC3::GenParticle>, class std::shared_ptr<const class HepMC3::GenParticle>) const) &HepMC3::GenParticlePtr_greater::operator(), "comparison of two particles \n\nC++: HepMC3::GenParticlePtr_greater::operator()(class std::shared_ptr<const class HepMC3::GenParticle>, class std::shared_ptr<const class HepMC3::GenParticle>) const --> bool", pybind11::arg("lx"), pybind11::arg("rx"));
	}
	{ // HepMC3::pair_GenVertexPtr_int_greater file: line:
		pybind11::class_<HepMC3::pair_GenVertexPtr_int_greater, std::shared_ptr<HepMC3::pair_GenVertexPtr_int_greater>> cl(M("HepMC3"), "pair_GenVertexPtr_int_greater", "Order vertices with equal paths. ");
		cl.def( pybind11::init( [](){ return new HepMC3::pair_GenVertexPtr_int_greater(); } ) );
		cl.def( pybind11::init( [](HepMC3::pair_GenVertexPtr_int_greater const &o){ return new HepMC3::pair_GenVertexPtr_int_greater(o); } ) );
		cl.def("__call__", (bool (HepMC3::pair_GenVertexPtr_int_greater::*)(const struct std::pair<class std::shared_ptr<const class HepMC3::GenVertex>, int> &, const struct std::pair<class std::shared_ptr<const class HepMC3::GenVertex>, int> &) const) &HepMC3::pair_GenVertexPtr_int_greater::operator(), "Order vertices with equal paths. If the paths are equal, order in other quantities.\n We cannot use id, as it can be assigned in different way\n\nC++: HepMC3::pair_GenVertexPtr_int_greater::operator()(const struct std::pair<class std::shared_ptr<const class HepMC3::GenVertex>, int> &, const struct std::pair<class std::shared_ptr<const class HepMC3::GenVertex>, int> &) const --> bool", pybind11::arg("lx"), pybind11::arg("rx"));
	}
	// HepMC3::calculate_longest_path_to_top(class std::shared_ptr<const class HepMC3::GenVertex>, class std::map<class std::shared_ptr<const class HepMC3::GenVertex>, int> &) file: line:
	M("HepMC3").def("calculate_longest_path_to_top", (void (*)(class std::shared_ptr<const class HepMC3::GenVertex>, class std::map<class std::shared_ptr<const class HepMC3::GenVertex>, int> &)) &HepMC3::calculate_longest_path_to_top, "Calculates the path to the top (beam) particles \n\nC++: HepMC3::calculate_longest_path_to_top(class std::shared_ptr<const class HepMC3::GenVertex>, class std::map<class std::shared_ptr<const class HepMC3::GenVertex>, int> &) --> void", pybind11::arg("v"), pybind11::arg("pathl"));
=======
	{ // LHEF::OAttr file:HepMC3/LHEF.h line:
		pybind11::class_<LHEF::OAttr<std::string>, std::shared_ptr<LHEF::OAttr<std::string>>> cl(M("LHEF"), "OAttr_std_string_t", "");
		cl.def( pybind11::init<const std::string &, const std::string &>(), pybind11::arg("n"), pybind11::arg("v") );

		cl.def( pybind11::init( [](LHEF::OAttr<std::string> const &o){ return new LHEF::OAttr<std::string>(o); } ) );
		cl.def_readwrite("name", &LHEF::OAttr<std::string>::name);
		cl.def_readwrite("val", &LHEF::OAttr<std::string>::val);
		cl.def("assign", (struct LHEF::OAttr<std::string > & (LHEF::OAttr<std::string>::*)(const struct LHEF::OAttr<std::string > &)) &LHEF::OAttr<std::string>::operator=, "C++: LHEF::OAttr<std::string>::operator=(const struct LHEF::OAttr<std::string > &) --> struct LHEF::OAttr<std::string > &", pybind11::return_value_policy::automatic, pybind11::arg(""));

		cl.def("__str__", [](LHEF::OAttr<std::string> const &o) -> std::string { std::ostringstream s; using namespace LHEF; s << o; return s.str(); } );
	}
	{ // LHEF::OAttr file:HepMC3/LHEF.h line:
		pybind11::class_<LHEF::OAttr<long>, std::shared_ptr<LHEF::OAttr<long>>> cl(M("LHEF"), "OAttr_long_t", "");
		cl.def( pybind11::init<const std::string &, const long &>(), pybind11::arg("n"), pybind11::arg("v") );

		cl.def( pybind11::init( [](LHEF::OAttr<long> const &o){ return new LHEF::OAttr<long>(o); } ) );
		cl.def_readwrite("name", &LHEF::OAttr<long>::name);
		cl.def_readwrite("val", &LHEF::OAttr<long>::val);
		cl.def("assign", (struct LHEF::OAttr<long> & (LHEF::OAttr<long>::*)(const struct LHEF::OAttr<long> &)) &LHEF::OAttr<long>::operator=, "C++: LHEF::OAttr<long>::operator=(const struct LHEF::OAttr<long> &) --> struct LHEF::OAttr<long> &", pybind11::return_value_policy::automatic, pybind11::arg(""));

		cl.def("__str__", [](LHEF::OAttr<long> const &o) -> std::string { std::ostringstream s; using namespace LHEF; s << o; return s.str(); } );
	}
	{ // LHEF::OAttr file:HepMC3/LHEF.h line:
		pybind11::class_<LHEF::OAttr<double>, std::shared_ptr<LHEF::OAttr<double>>> cl(M("LHEF"), "OAttr_double_t", "");
		cl.def( pybind11::init<const std::string &, const double &>(), pybind11::arg("n"), pybind11::arg("v") );

		cl.def( pybind11::init( [](LHEF::OAttr<double> const &o){ return new LHEF::OAttr<double>(o); } ) );
		cl.def_readwrite("name", &LHEF::OAttr<double>::name);
		cl.def_readwrite("val", &LHEF::OAttr<double>::val);
		cl.def("assign", (struct LHEF::OAttr<double> & (LHEF::OAttr<double>::*)(const struct LHEF::OAttr<double> &)) &LHEF::OAttr<double>::operator=, "C++: LHEF::OAttr<double>::operator=(const struct LHEF::OAttr<double> &) --> struct LHEF::OAttr<double> &", pybind11::return_value_policy::automatic, pybind11::arg(""));

		cl.def("__str__", [](LHEF::OAttr<double> const &o) -> std::string { std::ostringstream s; using namespace LHEF; s << o; return s.str(); } );
	}
	{ // LHEF::OAttr file:HepMC3/LHEF.h line:
		pybind11::class_<LHEF::OAttr<int>, std::shared_ptr<LHEF::OAttr<int>>> cl(M("LHEF"), "OAttr_int_t", "");
		cl.def( pybind11::init<const std::string &, const int &>(), pybind11::arg("n"), pybind11::arg("v") );
>>>>>>> origin/master

	// HepMC3::HEPEVT_to_GenEvent_nonstatic(class HepMC3::GenEvent *, const class HepMC3::HEPEVT_Wrapper_Runtime *) file: line:
	M("HepMC3").def("HEPEVT_to_GenEvent_nonstatic", (bool (*)(class HepMC3::GenEvent *, const class HepMC3::HEPEVT_Wrapper_Runtime *)) &HepMC3::HEPEVT_to_GenEvent_nonstatic<const HepMC3::HEPEVT_Wrapper_Runtime>, "C++: HepMC3::HEPEVT_to_GenEvent_nonstatic(class HepMC3::GenEvent *, const class HepMC3::HEPEVT_Wrapper_Runtime *) --> bool", pybind11::arg("evt"), pybind11::arg("A"));

	// HepMC3::GenEvent_to_HEPEVT_nonstatic(const class HepMC3::GenEvent *, class HepMC3::HEPEVT_Wrapper_Runtime *) file: line:
	M("HepMC3").def("GenEvent_to_HEPEVT_nonstatic", (bool (*)(const class HepMC3::GenEvent *, class HepMC3::HEPEVT_Wrapper_Runtime *)) &HepMC3::GenEvent_to_HEPEVT_nonstatic<HepMC3::HEPEVT_Wrapper_Runtime>, "C++: HepMC3::GenEvent_to_HEPEVT_nonstatic(const class HepMC3::GenEvent *, class HepMC3::HEPEVT_Wrapper_Runtime *) --> bool", pybind11::arg("evt"), pybind11::arg("A"));

	{ // HepMC3::HEPEVT_Wrapper_Template file: line:
		pybind11::class_<HepMC3::HEPEVT_Wrapper_Template<100000,double>, std::shared_ptr<HepMC3::HEPEVT_Wrapper_Template<100000,double>>> cl(M("HepMC3"), "HEPEVT_Wrapper_Template_100000_double_t", "");
		cl.def( pybind11::init( [](){ return new HepMC3::HEPEVT_Wrapper_Template<100000,double>(); } ) );
		cl.def( pybind11::init( [](HepMC3::HEPEVT_Wrapper_Template<100000,double> const &o){ return new HepMC3::HEPEVT_Wrapper_Template<100000,double>(o); } ) );
		cl.def("zero_everything", (void (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)()) &HepMC3::HEPEVT_Wrapper_Template<100000>::zero_everything, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::zero_everything() --> void");
		cl.def("GenEvent_to_HEPEVT", (bool (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const class HepMC3::GenEvent *)) &HepMC3::HEPEVT_Wrapper_Template<100000>::GenEvent_to_HEPEVT, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::GenEvent_to_HEPEVT(const class HepMC3::GenEvent *) --> bool", pybind11::arg("evt"));
		cl.def("HEPEVT_to_GenEvent", (bool (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(class HepMC3::GenEvent *) const) &HepMC3::HEPEVT_Wrapper_Template<100000>::HEPEVT_to_GenEvent, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::HEPEVT_to_GenEvent(class HepMC3::GenEvent *) const --> bool", pybind11::arg("evt"));
		cl.def("fix_daughters", (bool (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)()) &HepMC3::HEPEVT_Wrapper_Template<100000>::fix_daughters, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::fix_daughters() --> bool");
		cl.def("allocate_internal_storage", (void (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)()) &HepMC3::HEPEVT_Wrapper_Template<100000>::allocate_internal_storage, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::allocate_internal_storage() --> void");
		cl.def("copy_to_internal_storage", (void (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(char *, int)) &HepMC3::HEPEVT_Wrapper_Template<100000>::copy_to_internal_storage, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::copy_to_internal_storage(char *, int) --> void", pybind11::arg("c"), pybind11::arg("N"));
		cl.def("set_max_number_entries", (void (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(unsigned int)) &HepMC3::HEPEVT_Wrapper_Template<100000>::set_max_number_entries, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::set_max_number_entries(unsigned int) --> void", pybind11::arg("size"));
		cl.def("set_hepevt_address", (void (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(char *)) &HepMC3::HEPEVT_Wrapper_Template<100000>::set_hepevt_address, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::set_hepevt_address(char *) --> void", pybind11::arg("c"));
		cl.def("max_number_entries", (int (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)() const) &HepMC3::HEPEVT_Wrapper_Template<100000>::max_number_entries, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::max_number_entries() const --> int");
		cl.def("event_number", (int (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)() const) &HepMC3::HEPEVT_Wrapper_Template<100000>::event_number, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::event_number() const --> int");
		cl.def("number_entries", (int (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)() const) &HepMC3::HEPEVT_Wrapper_Template<100000>::number_entries, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::number_entries() const --> int");
		cl.def("status", (int (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int) const) &HepMC3::HEPEVT_Wrapper_Template<100000>::status, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::status(const int) const --> int", pybind11::arg("index"));
		cl.def("id", (int (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int) const) &HepMC3::HEPEVT_Wrapper_Template<100000>::id, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::id(const int) const --> int", pybind11::arg("index"));
		cl.def("first_parent", (int (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int) const) &HepMC3::HEPEVT_Wrapper_Template<100000>::first_parent, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::first_parent(const int) const --> int", pybind11::arg("index"));
		cl.def("last_parent", (int (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int) const) &HepMC3::HEPEVT_Wrapper_Template<100000>::last_parent, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::last_parent(const int) const --> int", pybind11::arg("index"));
		cl.def("first_child", (int (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int) const) &HepMC3::HEPEVT_Wrapper_Template<100000>::first_child, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::first_child(const int) const --> int", pybind11::arg("index"));
		cl.def("last_child", (int (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int) const) &HepMC3::HEPEVT_Wrapper_Template<100000>::last_child, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::last_child(const int) const --> int", pybind11::arg("index"));
		cl.def("px", (double (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int) const) &HepMC3::HEPEVT_Wrapper_Template<100000>::px, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::px(const int) const --> double", pybind11::arg("index"));
		cl.def("py", (double (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int) const) &HepMC3::HEPEVT_Wrapper_Template<100000>::py, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::py(const int) const --> double", pybind11::arg("index"));
		cl.def("pz", (double (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int) const) &HepMC3::HEPEVT_Wrapper_Template<100000>::pz, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::pz(const int) const --> double", pybind11::arg("index"));
		cl.def("e", (double (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int) const) &HepMC3::HEPEVT_Wrapper_Template<100000>::e, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::e(const int) const --> double", pybind11::arg("index"));
		cl.def("m", (double (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int) const) &HepMC3::HEPEVT_Wrapper_Template<100000>::m, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::m(const int) const --> double", pybind11::arg("index"));
		cl.def("x", (double (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int) const) &HepMC3::HEPEVT_Wrapper_Template<100000>::x, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::x(const int) const --> double", pybind11::arg("index"));
		cl.def("y", (double (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int) const) &HepMC3::HEPEVT_Wrapper_Template<100000>::y, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::y(const int) const --> double", pybind11::arg("index"));
		cl.def("z", (double (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int) const) &HepMC3::HEPEVT_Wrapper_Template<100000>::z, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::z(const int) const --> double", pybind11::arg("index"));
		cl.def("t", (double (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int) const) &HepMC3::HEPEVT_Wrapper_Template<100000>::t, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::t(const int) const --> double", pybind11::arg("index"));
		cl.def("number_parents", (int (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int) const) &HepMC3::HEPEVT_Wrapper_Template<100000>::number_parents, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::number_parents(const int) const --> int", pybind11::arg("index"));
		cl.def("number_children", (int (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int) const) &HepMC3::HEPEVT_Wrapper_Template<100000>::number_children, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::number_children(const int) const --> int", pybind11::arg("index"));
		cl.def("number_children_exact", (int (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int) const) &HepMC3::HEPEVT_Wrapper_Template<100000>::number_children_exact, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::number_children_exact(const int) const --> int", pybind11::arg("index"));
		cl.def("set_event_number", (void (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int)) &HepMC3::HEPEVT_Wrapper_Template<100000>::set_event_number, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::set_event_number(const int) --> void", pybind11::arg("evtno"));
		cl.def("set_number_entries", (void (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int)) &HepMC3::HEPEVT_Wrapper_Template<100000>::set_number_entries, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::set_number_entries(const int) --> void", pybind11::arg("noentries"));
		cl.def("set_status", (void (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int, const int)) &HepMC3::HEPEVT_Wrapper_Template<100000>::set_status, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::set_status(const int, const int) --> void", pybind11::arg("index"), pybind11::arg("status"));
		cl.def("set_id", (void (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int, const int)) &HepMC3::HEPEVT_Wrapper_Template<100000>::set_id, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::set_id(const int, const int) --> void", pybind11::arg("index"), pybind11::arg("id"));
		cl.def("set_parents", (void (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int, const int, const int)) &HepMC3::HEPEVT_Wrapper_Template<100000>::set_parents, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::set_parents(const int, const int, const int) --> void", pybind11::arg("index"), pybind11::arg("firstparent"), pybind11::arg("lastparent"));
		cl.def("set_children", (void (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int, const int, const int)) &HepMC3::HEPEVT_Wrapper_Template<100000>::set_children, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::set_children(const int, const int, const int) --> void", pybind11::arg("index"), pybind11::arg("firstchild"), pybind11::arg("lastchild"));
		cl.def("set_momentum", (void (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int, const double, const double, const double, const double)) &HepMC3::HEPEVT_Wrapper_Template<100000>::set_momentum, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::set_momentum(const int, const double, const double, const double, const double) --> void", pybind11::arg("index"), pybind11::arg("px"), pybind11::arg("py"), pybind11::arg("pz"), pybind11::arg("e"));
		cl.def("set_mass", (void (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int, double)) &HepMC3::HEPEVT_Wrapper_Template<100000>::set_mass, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::set_mass(const int, double) --> void", pybind11::arg("index"), pybind11::arg("mass"));
		cl.def("set_position", (void (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const int, const double, const double, const double, const double)) &HepMC3::HEPEVT_Wrapper_Template<100000>::set_position, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::set_position(const int, const double, const double, const double, const double) --> void", pybind11::arg("index"), pybind11::arg("x"), pybind11::arg("y"), pybind11::arg("z"), pybind11::arg("t"));
		cl.def("assign", (class HepMC3::HEPEVT_Wrapper_Template<100000> & (HepMC3::HEPEVT_Wrapper_Template<100000,double>::*)(const class HepMC3::HEPEVT_Wrapper_Template<100000> &)) &HepMC3::HEPEVT_Wrapper_Template<100000>::operator=, "C++: HepMC3::HEPEVT_Wrapper_Template<100000>::operator=(const class HepMC3::HEPEVT_Wrapper_Template<100000> &) --> class HepMC3::HEPEVT_Wrapper_Template<100000> &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // HepMC3::WriterHEPEVT file:HepMC3/WriterHEPEVT.h line:
		pybind11::class_<HepMC3::WriterHEPEVT, std::shared_ptr<HepMC3::WriterHEPEVT>, PyCallBack_HepMC3_WriterHEPEVT, HepMC3::Writer> cl(M("HepMC3"), "WriterHEPEVT", "");
		cl.def( pybind11::init( [](const std::string & a0){ return new HepMC3::WriterHEPEVT(a0); }, [](const std::string & a0){ return new PyCallBack_HepMC3_WriterHEPEVT(a0); } ), "doc");
		cl.def( pybind11::init<const std::string &, class std::shared_ptr<class HepMC3::GenRunInfo>>(), pybind11::arg("filename"), pybind11::arg("run") );

<<<<<<< HEAD
		cl.def("write_hepevt_particle", [](HepMC3::WriterHEPEVT &o, int const & a0) -> void { return o.write_hepevt_particle(a0); }, "", pybind11::arg("index"));
		cl.def("write_hepevt_particle", (void (HepMC3::WriterHEPEVT::*)(int, bool)) &HepMC3::WriterHEPEVT::write_hepevt_particle, "Write particle to file\n\n  \n Particle to be serialized\n  \n\n Format of record\n\nC++: HepMC3::WriterHEPEVT::write_hepevt_particle(int, bool) --> void", pybind11::arg("index"), pybind11::arg("iflong"));
		cl.def("write_hepevt_event_header", (void (HepMC3::WriterHEPEVT::*)()) &HepMC3::WriterHEPEVT::write_hepevt_event_header, "Write event header to file\n\n     \n\nC++: HepMC3::WriterHEPEVT::write_hepevt_event_header() --> void");
		cl.def("write_event", (void (HepMC3::WriterHEPEVT::*)(const class HepMC3::GenEvent &)) &HepMC3::WriterHEPEVT::write_event, "Write event to file\n\n  \n Event to be serialized\n\nC++: HepMC3::WriterHEPEVT::write_event(const class HepMC3::GenEvent &) --> void", pybind11::arg("evt"));
		cl.def("close", (void (HepMC3::WriterHEPEVT::*)()) &HepMC3::WriterHEPEVT::close, "Close file stream \n\nC++: HepMC3::WriterHEPEVT::close() --> void");
		cl.def("failed", (bool (HepMC3::WriterHEPEVT::*)()) &HepMC3::WriterHEPEVT::failed, "Get stream error state flag \n\nC++: HepMC3::WriterHEPEVT::failed() --> bool");
		cl.def("set_vertices_positions_present", (void (HepMC3::WriterHEPEVT::*)(bool)) &HepMC3::WriterHEPEVT::set_vertices_positions_present, "set flag if vertex positions are available.\n  Effectively this adds or removes key \"vertices_positions_are_absent\"\n  to/from the m_options.\n\nC++: HepMC3::WriterHEPEVT::set_vertices_positions_present(bool) --> void", pybind11::arg("iflong"));
		cl.def("get_vertices_positions_present", (bool (HepMC3::WriterHEPEVT::*)() const) &HepMC3::WriterHEPEVT::get_vertices_positions_present, "get flag if vertex positions are available.\n The flag is deduced from m_options. If the m_options have the key\n \"vertices_positions_are_absent\" the result if false. True otherwise. \n\nC++: HepMC3::WriterHEPEVT::get_vertices_positions_present() const --> bool");
=======
	// LHEF::oattr(std::string, const long &) file:HepMC3/LHEF.h line:
	M("LHEF").def("oattr", (struct LHEF::OAttr<long> (*)(std::string, const long &)) &LHEF::oattr<long>, "C++: LHEF::oattr(std::string, const long &) --> struct LHEF::OAttr<long>", pybind11::arg("name"), pybind11::arg("value"));

	// LHEF::oattr(std::string, const double &) file:HepMC3/LHEF.h line:
	M("LHEF").def("oattr", (struct LHEF::OAttr<double> (*)(std::string, const double &)) &LHEF::oattr<double>, "C++: LHEF::oattr(std::string, const double &) --> struct LHEF::OAttr<double>", pybind11::arg("name"), pybind11::arg("value"));

	// LHEF::oattr(std::string, const int &) file:HepMC3/LHEF.h line:
	M("LHEF").def("oattr", (struct LHEF::OAttr<int> (*)(std::string, const int &)) &LHEF::oattr<int>, "C++: LHEF::oattr(std::string, const int &) --> struct LHEF::OAttr<int>", pybind11::arg("name"), pybind11::arg("value"));

	{ // LHEF::XMLTag file:HepMC3/LHEF.h line:
		pybind11::class_<LHEF::XMLTag, std::shared_ptr<LHEF::XMLTag>> cl(M("LHEF"), "XMLTag", "The XMLTag struct is used to represent all information within an\n XML tag. It contains the attributes as a map, any sub-tags as a\n vector of pointers to other XMLTag objects, and any other\n information as a single string.");
		cl.def( pybind11::init( [](){ return new LHEF::XMLTag(); } ) );
		cl.def( pybind11::init( [](LHEF::XMLTag const &o){ return new LHEF::XMLTag(o); } ) );
		cl.def_readwrite("name", &LHEF::XMLTag::name);
		cl.def_readwrite("attr", &LHEF::XMLTag::attr);
		cl.def_readwrite("tags", &LHEF::XMLTag::tags);
		cl.def_readwrite("contents", &LHEF::XMLTag::contents);
		cl.def("getattr", (bool (LHEF::XMLTag::*)(const std::string &, double &) const) &LHEF::XMLTag::getattr, "Find an attribute named  and set the double variable  to\n the corresponding value. \n\n false if no attribute was found.\n\nC++: LHEF::XMLTag::getattr(const std::string &, double &) const --> bool", pybind11::arg("n"), pybind11::arg("v"));
		cl.def("getattr", (bool (LHEF::XMLTag::*)(const std::string &, bool &) const) &LHEF::XMLTag::getattr, "Find an attribute named  and set the bool variable  to\n true if the corresponding value is \"yes\". \n\n false if no\n attribute was found.\n\nC++: LHEF::XMLTag::getattr(const std::string &, bool &) const --> bool", pybind11::arg("n"), pybind11::arg("v"));
		cl.def("getattr", (bool (LHEF::XMLTag::*)(const std::string &, long &) const) &LHEF::XMLTag::getattr, "Find an attribute named  and set the long variable  to\n the corresponding value. \n\n false if no attribute was found.\n\nC++: LHEF::XMLTag::getattr(const std::string &, long &) const --> bool", pybind11::arg("n"), pybind11::arg("v"));
		cl.def("getattr", (bool (LHEF::XMLTag::*)(const std::string &, int &) const) &LHEF::XMLTag::getattr, "Find an attribute named  and set the long variable  to\n the corresponding value. \n\n false if no attribute was found.\n\nC++: LHEF::XMLTag::getattr(const std::string &, int &) const --> bool", pybind11::arg("n"), pybind11::arg("v"));
		cl.def("getattr", (bool (LHEF::XMLTag::*)(const std::string &, std::string &) const) &LHEF::XMLTag::getattr, "Find an attribute named  and set the string variable  to\n the corresponding value. \n\n false if no attribute was found.\n\nC++: LHEF::XMLTag::getattr(const std::string &, std::string &) const --> bool", pybind11::arg("n"), pybind11::arg("v"));
		cl.def_static("findXMLTags", [](std::string const & a0) -> std::vector<struct LHEF::XMLTag *> { return LHEF::XMLTag::findXMLTags(a0); }, "", pybind11::arg("str"));
		cl.def_static("findXMLTags", (class std::vector<struct LHEF::XMLTag *> (*)(std::string, std::string *)) &LHEF::XMLTag::findXMLTags, "Scan the given string and return all XML tags found as a vector\n of pointers to XMLTag objects. Text which does not belong to any\n tag is stored in tags without name and in the string pointed to\n by leftover (if not null).\n\nC++: LHEF::XMLTag::findXMLTags(std::string, std::string *) --> class std::vector<struct LHEF::XMLTag *>", pybind11::arg("str"), pybind11::arg("leftover"));
		cl.def_static("deleteAll", (void (*)(class std::vector<struct LHEF::XMLTag *> &)) &LHEF::XMLTag::deleteAll, "Delete all tags in a vector.\n\nC++: LHEF::XMLTag::deleteAll(class std::vector<struct LHEF::XMLTag *> &) --> void", pybind11::arg("tags"));
		cl.def("assign", (struct LHEF::XMLTag & (LHEF::XMLTag::*)(const struct LHEF::XMLTag &)) &LHEF::XMLTag::operator=, "C++: LHEF::XMLTag::operator=(const struct LHEF::XMLTag &) --> struct LHEF::XMLTag &", pybind11::return_value_policy::automatic, pybind11::arg(""));

		binder::custom_T_binder<LHEF::XMLTag>(cl);
>>>>>>> origin/master
	}
	{ // HepMC3::ReaderHEPEVT file:HepMC3/ReaderHEPEVT.h line:
		pybind11::class_<HepMC3::ReaderHEPEVT, std::shared_ptr<HepMC3::ReaderHEPEVT>, PyCallBack_HepMC3_ReaderHEPEVT, HepMC3::Reader> cl(M("HepMC3"), "ReaderHEPEVT", "");
		cl.def( pybind11::init<const std::string &>(), pybind11::arg("filename") );

<<<<<<< HEAD
		cl.def("read_hepevt_event_header", (bool (HepMC3::ReaderHEPEVT::*)()) &HepMC3::ReaderHEPEVT::read_hepevt_event_header, "Find and read event header line  from file\n\n    \n\nC++: HepMC3::ReaderHEPEVT::read_hepevt_event_header() --> bool");
		cl.def("read_hepevt_particle", (bool (HepMC3::ReaderHEPEVT::*)(int)) &HepMC3::ReaderHEPEVT::read_hepevt_particle, "read particle from file\n\n \n Particle id\n\nC++: HepMC3::ReaderHEPEVT::read_hepevt_particle(int) --> bool", pybind11::arg("i"));
		cl.def("skip", (bool (HepMC3::ReaderHEPEVT::*)(const int)) &HepMC3::ReaderHEPEVT::skip, "skip events\n\nC++: HepMC3::ReaderHEPEVT::skip(const int) --> bool", pybind11::arg(""));
		cl.def("read_event", (bool (HepMC3::ReaderHEPEVT::*)(class HepMC3::GenEvent &)) &HepMC3::ReaderHEPEVT::read_event, "Read event from file\n\nC++: HepMC3::ReaderHEPEVT::read_event(class HepMC3::GenEvent &) --> bool", pybind11::arg("evt"));
		cl.def("close", (void (HepMC3::ReaderHEPEVT::*)()) &HepMC3::ReaderHEPEVT::close, "Close file stream \n\nC++: HepMC3::ReaderHEPEVT::close() --> void");
		cl.def("failed", (bool (HepMC3::ReaderHEPEVT::*)()) &HepMC3::ReaderHEPEVT::failed, "Get stream error state \n\nC++: HepMC3::ReaderHEPEVT::failed() --> bool");
=======
	{ // LHEF::TagBase file:HepMC3/LHEF.h line:
		pybind11::class_<LHEF::TagBase, std::shared_ptr<LHEF::TagBase>> cl(M("LHEF"), "TagBase", "This is the base class of all classes representing xml tags.");
		cl.def( pybind11::init( [](){ return new LHEF::TagBase(); } ) );
		cl.def( pybind11::init( [](const class std::map<std::string, std::string > & a0){ return new LHEF::TagBase(a0); } ), "doc" , pybind11::arg("attr"));
		cl.def( pybind11::init<const class std::map<std::string, std::string > &, const std::string &>(), pybind11::arg("attr"), pybind11::arg("conts") );

		cl.def( pybind11::init( [](LHEF::TagBase const &o){ return new LHEF::TagBase(o); } ) );
		cl.def_readwrite("attributes", &LHEF::TagBase::attributes);
		cl.def_readwrite("contents", &LHEF::TagBase::contents);
		cl.def("getattr", [](LHEF::TagBase &o, const std::string & a0, double & a1) -> bool { return o.getattr(a0, a1); }, "", pybind11::arg("n"), pybind11::arg("v"));
		cl.def("getattr", (bool (LHEF::TagBase::*)(const std::string &, double &, bool)) &LHEF::TagBase::getattr, "Find an attribute named  and set the double variable  to\n the corresponding value. Remove the correspondig attribute from\n the list if found and  is true. \n\n false if no\n attribute was found.\n\nC++: LHEF::TagBase::getattr(const std::string &, double &, bool) --> bool", pybind11::arg("n"), pybind11::arg("v"), pybind11::arg("erase"));
		cl.def("getattr", [](LHEF::TagBase &o, const std::string & a0, bool & a1) -> bool { return o.getattr(a0, a1); }, "", pybind11::arg("n"), pybind11::arg("v"));
		cl.def("getattr", (bool (LHEF::TagBase::*)(const std::string &, bool &, bool)) &LHEF::TagBase::getattr, "Find an attribute named  and set the bool variable  to\n true if the corresponding value is \"yes\". Remove the correspondig\n attribute from the list if found and  is true. \n\n\n false if no attribute was found.\n\nC++: LHEF::TagBase::getattr(const std::string &, bool &, bool) --> bool", pybind11::arg("n"), pybind11::arg("v"), pybind11::arg("erase"));
		cl.def("getattr", [](LHEF::TagBase &o, const std::string & a0, long & a1) -> bool { return o.getattr(a0, a1); }, "", pybind11::arg("n"), pybind11::arg("v"));
		cl.def("getattr", (bool (LHEF::TagBase::*)(const std::string &, long &, bool)) &LHEF::TagBase::getattr, "Find an attribute named  and set the long variable  to\n the corresponding value. Remove the correspondig attribute from\n the list if found and  is true. \n\n false if no\n attribute was found.\n\nC++: LHEF::TagBase::getattr(const std::string &, long &, bool) --> bool", pybind11::arg("n"), pybind11::arg("v"), pybind11::arg("erase"));
		cl.def("getattr", [](LHEF::TagBase &o, const std::string & a0, int & a1) -> bool { return o.getattr(a0, a1); }, "", pybind11::arg("n"), pybind11::arg("v"));
		cl.def("getattr", (bool (LHEF::TagBase::*)(const std::string &, int &, bool)) &LHEF::TagBase::getattr, "Find an attribute named  and set the long variable  to\n the corresponding value. Remove the correspondig attribute from\n the list if found and  is true. \n\n false if no\n attribute was found.\n\nC++: LHEF::TagBase::getattr(const std::string &, int &, bool) --> bool", pybind11::arg("n"), pybind11::arg("v"), pybind11::arg("erase"));
		cl.def("getattr", [](LHEF::TagBase &o, const std::string & a0, std::string & a1) -> bool { return o.getattr(a0, a1); }, "", pybind11::arg("n"), pybind11::arg("v"));
		cl.def("getattr", (bool (LHEF::TagBase::*)(const std::string &, std::string &, bool)) &LHEF::TagBase::getattr, "Find an attribute named  and set the string variable  to\n the corresponding value. Remove the correspondig attribute from\n the list if found and  is true. \n\n false if no\n attribute was found.\n\nC++: LHEF::TagBase::getattr(const std::string &, std::string &, bool) --> bool", pybind11::arg("n"), pybind11::arg("v"), pybind11::arg("erase"));
		cl.def_static("yes", (std::string (*)()) &LHEF::TagBase::yes, "Static string token for truth values.\n\nC++: LHEF::TagBase::yes() --> std::string");
		cl.def("assign", (struct LHEF::TagBase & (LHEF::TagBase::*)(const struct LHEF::TagBase &)) &LHEF::TagBase::operator=, "C++: LHEF::TagBase::operator=(const struct LHEF::TagBase &) --> struct LHEF::TagBase &", pybind11::return_value_policy::automatic, pybind11::arg(""));

		binder::custom_LHEFTagBase_binder(cl);
	}
	{ // LHEF::Generator file:HepMC3/LHEF.h line:
		pybind11::class_<LHEF::Generator, std::shared_ptr<LHEF::Generator>, LHEF::TagBase> cl(M("LHEF"), "Generator", "The Generator class contains information about a generator used in a run.");
		cl.def( pybind11::init<const struct LHEF::XMLTag &>(), pybind11::arg("tag") );

		cl.def( pybind11::init( [](LHEF::Generator const &o){ return new LHEF::Generator(o); } ) );
		cl.def_readwrite("name", &LHEF::Generator::name);
		cl.def_readwrite("version", &LHEF::Generator::version);
		cl.def("assign", (struct LHEF::Generator & (LHEF::Generator::*)(const struct LHEF::Generator &)) &LHEF::Generator::operator=, "C++: LHEF::Generator::operator=(const struct LHEF::Generator &) --> struct LHEF::Generator &", pybind11::return_value_policy::automatic, pybind11::arg(""));

		binder::custom_T_binder<LHEF::Generator>(cl);
	}
	{ // LHEF::XSecInfo file:HepMC3/LHEF.h line:
		pybind11::class_<LHEF::XSecInfo, std::shared_ptr<LHEF::XSecInfo>, LHEF::TagBase> cl(M("LHEF"), "XSecInfo", "The XSecInfo class contains information given in the xsecinfo tag.");
		cl.def( pybind11::init( [](){ return new LHEF::XSecInfo(); } ) );
		cl.def( pybind11::init<const struct LHEF::XMLTag &>(), pybind11::arg("tag") );

		cl.def( pybind11::init( [](LHEF::XSecInfo const &o){ return new LHEF::XSecInfo(o); } ) );
		cl.def_readwrite("neve", &LHEF::XSecInfo::neve);
		cl.def_readwrite("ntries", &LHEF::XSecInfo::ntries);
		cl.def_readwrite("totxsec", &LHEF::XSecInfo::totxsec);
		cl.def_readwrite("xsecerr", &LHEF::XSecInfo::xsecerr);
		cl.def_readwrite("maxweight", &LHEF::XSecInfo::maxweight);
		cl.def_readwrite("meanweight", &LHEF::XSecInfo::meanweight);
		cl.def_readwrite("negweights", &LHEF::XSecInfo::negweights);
		cl.def_readwrite("varweights", &LHEF::XSecInfo::varweights);
		cl.def_readwrite("weightname", &LHEF::XSecInfo::weightname);
		cl.def("assign", (struct LHEF::XSecInfo & (LHEF::XSecInfo::*)(const struct LHEF::XSecInfo &)) &LHEF::XSecInfo::operator=, "C++: LHEF::XSecInfo::operator=(const struct LHEF::XSecInfo &) --> struct LHEF::XSecInfo &", pybind11::return_value_policy::automatic, pybind11::arg(""));

		binder::custom_T_binder<LHEF::XSecInfo>(cl);
	}
	{ // LHEF::EventFile file:HepMC3/LHEF.h line:
		pybind11::class_<LHEF::EventFile, std::shared_ptr<LHEF::EventFile>, LHEF::TagBase> cl(M("LHEF"), "EventFile", "Simple struct to store information about separate eventfiles to be\n loaded.");
		cl.def( pybind11::init( [](){ return new LHEF::EventFile(); } ) );
		cl.def( pybind11::init<const struct LHEF::XMLTag &>(), pybind11::arg("tag") );

		cl.def( pybind11::init( [](LHEF::EventFile const &o){ return new LHEF::EventFile(o); } ) );
		cl.def_readwrite("filename", &LHEF::EventFile::filename);
		cl.def_readwrite("neve", &LHEF::EventFile::neve);
		cl.def_readwrite("ntries", &LHEF::EventFile::ntries);
		cl.def("assign", (struct LHEF::EventFile & (LHEF::EventFile::*)(const struct LHEF::EventFile &)) &LHEF::EventFile::operator=, "C++: LHEF::EventFile::operator=(const struct LHEF::EventFile &) --> struct LHEF::EventFile &", pybind11::return_value_policy::automatic, pybind11::arg(""));

		binder::custom_T_binder<LHEF::EventFile>(cl);
	}
	{ // LHEF::Cut file:HepMC3/LHEF.h line:
		pybind11::class_<LHEF::Cut, std::shared_ptr<LHEF::Cut>, LHEF::TagBase> cl(M("LHEF"), "Cut", "The Cut class represents a cut used by the Matrix Element generator.");
		cl.def( pybind11::init( [](){ return new LHEF::Cut(); } ) );
		cl.def( pybind11::init<const struct LHEF::XMLTag &, const class std::map<std::string, class std::set<long> > &>(), pybind11::arg("tag"), pybind11::arg("ptypes") );

		cl.def( pybind11::init( [](LHEF::Cut const &o){ return new LHEF::Cut(o); } ) );
		cl.def_readwrite("type", &LHEF::Cut::type);
		cl.def_readwrite("p1", &LHEF::Cut::p1);
		cl.def_readwrite("np1", &LHEF::Cut::np1);
		cl.def_readwrite("p2", &LHEF::Cut::p2);
		cl.def_readwrite("np2", &LHEF::Cut::np2);
		cl.def_readwrite("min", &LHEF::Cut::min);
		cl.def_readwrite("max", &LHEF::Cut::max);
		cl.def("match", [](LHEF::Cut const &o, long const & a0) -> bool { return o.match(a0); }, "", pybind11::arg("id1"));
		cl.def("match", (bool (LHEF::Cut::*)(long, long) const) &LHEF::Cut::match, "Check if a  matches p1 and  matches p2. Only non-zero\n values are considered.\n\nC++: LHEF::Cut::match(long, long) const --> bool", pybind11::arg("id1"), pybind11::arg("id2"));
		cl.def("passCuts", (bool (LHEF::Cut::*)(const class std::vector<long> &, const class std::vector<class std::vector<double> > &) const) &LHEF::Cut::passCuts, "Check if the particles given as a vector of PDG  numbers,\n and a vector of vectors of momentum components,  will pass\n the cut defined in this event.\n\nC++: LHEF::Cut::passCuts(const class std::vector<long> &, const class std::vector<class std::vector<double> > &) const --> bool", pybind11::arg("id"), pybind11::arg("p"));
		cl.def_static("eta", (double (*)(const class std::vector<double> &)) &LHEF::Cut::eta, "Return the pseudorapidity of a particle with momentum \n   \n\nC++: LHEF::Cut::eta(const class std::vector<double> &) --> double", pybind11::arg("p"));
		cl.def_static("rap", (double (*)(const class std::vector<double> &)) &LHEF::Cut::rap, "Return the true rapidity of a particle with momentum \n   \n\nC++: LHEF::Cut::rap(const class std::vector<double> &) --> double", pybind11::arg("p"));
		cl.def_static("deltaR", (double (*)(const class std::vector<double> &, const class std::vector<double> &)) &LHEF::Cut::deltaR, "Return the delta-R of a particle pair with momenta  and \n   \n\nC++: LHEF::Cut::deltaR(const class std::vector<double> &, const class std::vector<double> &) --> double", pybind11::arg("p1"), pybind11::arg("p2"));
		cl.def("outside", (bool (LHEF::Cut::*)(double) const) &LHEF::Cut::outside, "Return true if the given  is outside limits.\n\nC++: LHEF::Cut::outside(double) const --> bool", pybind11::arg("value"));
		cl.def("assign", (struct LHEF::Cut & (LHEF::Cut::*)(const struct LHEF::Cut &)) &LHEF::Cut::operator=, "C++: LHEF::Cut::operator=(const struct LHEF::Cut &) --> struct LHEF::Cut &", pybind11::return_value_policy::automatic, pybind11::arg(""));

		binder::custom_T_binder<LHEF::Cut>(cl);
	}
	{ // LHEF::ProcInfo file:HepMC3/LHEF.h line:
		pybind11::class_<LHEF::ProcInfo, std::shared_ptr<LHEF::ProcInfo>, LHEF::TagBase> cl(M("LHEF"), "ProcInfo", "The ProcInfo class represents the information in a procinfo tag.");
		cl.def( pybind11::init( [](){ return new LHEF::ProcInfo(); } ) );
		cl.def( pybind11::init<const struct LHEF::XMLTag &>(), pybind11::arg("tag") );

		cl.def( pybind11::init( [](LHEF::ProcInfo const &o){ return new LHEF::ProcInfo(o); } ) );
		cl.def_readwrite("iproc", &LHEF::ProcInfo::iproc);
		cl.def_readwrite("loops", &LHEF::ProcInfo::loops);
		cl.def_readwrite("qcdorder", &LHEF::ProcInfo::qcdorder);
		cl.def_readwrite("eworder", &LHEF::ProcInfo::eworder);
		cl.def_readwrite("fscheme", &LHEF::ProcInfo::fscheme);
		cl.def_readwrite("rscheme", &LHEF::ProcInfo::rscheme);
		cl.def_readwrite("scheme", &LHEF::ProcInfo::scheme);
		cl.def("assign", (struct LHEF::ProcInfo & (LHEF::ProcInfo::*)(const struct LHEF::ProcInfo &)) &LHEF::ProcInfo::operator=, "C++: LHEF::ProcInfo::operator=(const struct LHEF::ProcInfo &) --> struct LHEF::ProcInfo &", pybind11::return_value_policy::automatic, pybind11::arg(""));

		binder::custom_T_binder<LHEF::ProcInfo>(cl);
>>>>>>> origin/master
	}
}
