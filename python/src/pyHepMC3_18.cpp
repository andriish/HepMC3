#include <HepMC3/Attribute.h>
#include <HepMC3/Data/GenEventData.h>
#include <HepMC3/Data/GenParticleData.h>
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

void bind_pyHepMC3_18(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // HepMC3::GenParticle file:HepMC3/GenParticle.h line:28
		pybind11::class_<HepMC3::GenParticle, std::shared_ptr<HepMC3::GenParticle>> cl(M("HepMC3"), "GenParticle", "");
		cl.def( pybind11::init( [](){ return new HepMC3::GenParticle(); } ), "doc" );
		cl.def( pybind11::init( [](const class HepMC3::FourVector & a0){ return new HepMC3::GenParticle(a0); } ), "doc" , pybind11::arg("momentum"));
		cl.def( pybind11::init( [](const class HepMC3::FourVector & a0, int const & a1){ return new HepMC3::GenParticle(a0, a1); } ), "doc" , pybind11::arg("momentum"), pybind11::arg("pid"));
		cl.def( pybind11::init<const class HepMC3::FourVector &, int, int>(), pybind11::arg("momentum"), pybind11::arg("pid"), pybind11::arg("status") );

		cl.def( pybind11::init<const struct HepMC3::GenParticleData &>(), pybind11::arg("data") );

		cl.def( pybind11::init( [](HepMC3::GenParticle const &o){ return new HepMC3::GenParticle(o); } ) );
		cl.def("in_event", (bool (HepMC3::GenParticle::*)() const) &HepMC3::GenParticle::in_event, "Check if this particle belongs to an event\n\nC++: HepMC3::GenParticle::in_event() const --> bool");
		cl.def("parent_event", (class HepMC3::GenEvent * (HepMC3::GenParticle::*)()) &HepMC3::GenParticle::parent_event, "Get the parent event\n\nC++: HepMC3::GenParticle::parent_event() --> class HepMC3::GenEvent *", pybind11::return_value_policy::automatic);
		cl.def("id", (int (HepMC3::GenParticle::*)() const) &HepMC3::GenParticle::id, "Get the particle ID number (*not* PDG ID)\n\nC++: HepMC3::GenParticle::id() const --> int");
		cl.def("data", (const struct HepMC3::GenParticleData & (HepMC3::GenParticle::*)() const) &HepMC3::GenParticle::data, "C++: HepMC3::GenParticle::data() const --> const struct HepMC3::GenParticleData &", pybind11::return_value_policy::automatic);
		cl.def("production_vertex", (class std::shared_ptr<class HepMC3::GenVertex> (HepMC3::GenParticle::*)()) &HepMC3::GenParticle::production_vertex, "C++: HepMC3::GenParticle::production_vertex() --> class std::shared_ptr<class HepMC3::GenVertex>");
		cl.def("end_vertex", (class std::shared_ptr<class HepMC3::GenVertex> (HepMC3::GenParticle::*)()) &HepMC3::GenParticle::end_vertex, "C++: HepMC3::GenParticle::end_vertex() --> class std::shared_ptr<class HepMC3::GenVertex>");
		cl.def("parents", (class std::vector<class std::shared_ptr<class HepMC3::GenParticle> > (HepMC3::GenParticle::*)()) &HepMC3::GenParticle::parents, "Convenience access to immediate incoming particles via production vertex\n \n\n Less efficient than via the vertex since return must be by value (in case there is no vertex)\n\nC++: HepMC3::GenParticle::parents() --> class std::vector<class std::shared_ptr<class HepMC3::GenParticle> >");
		cl.def("children", (class std::vector<class std::shared_ptr<class HepMC3::GenParticle> > (HepMC3::GenParticle::*)()) &HepMC3::GenParticle::children, "Convenience access to immediate outgoing particles via end vertex\n \n\n Less efficient than via the vertex since return must be by value (in case there is no vertex)\n\nC++: HepMC3::GenParticle::children() --> class std::vector<class std::shared_ptr<class HepMC3::GenParticle> >");
		cl.def("pid", (int (HepMC3::GenParticle::*)() const) &HepMC3::GenParticle::pid, "C++: HepMC3::GenParticle::pid() const --> int");
		cl.def("abs_pid", (int (HepMC3::GenParticle::*)() const) &HepMC3::GenParticle::abs_pid, "C++: HepMC3::GenParticle::abs_pid() const --> int");
		cl.def("status", (int (HepMC3::GenParticle::*)() const) &HepMC3::GenParticle::status, "C++: HepMC3::GenParticle::status() const --> int");
		cl.def("momentum", (const class HepMC3::FourVector & (HepMC3::GenParticle::*)() const) &HepMC3::GenParticle::momentum, "C++: HepMC3::GenParticle::momentum() const --> const class HepMC3::FourVector &", pybind11::return_value_policy::automatic);
		cl.def("is_generated_mass_set", (bool (HepMC3::GenParticle::*)() const) &HepMC3::GenParticle::is_generated_mass_set, "C++: HepMC3::GenParticle::is_generated_mass_set() const --> bool");
		cl.def("generated_mass", (double (HepMC3::GenParticle::*)() const) &HepMC3::GenParticle::generated_mass, "Get generated mass\n\n This function will return mass as set by a generator/tool.\n If not set, it will return momentum().m()\n\nC++: HepMC3::GenParticle::generated_mass() const --> double");
		cl.def("set_pid", (void (HepMC3::GenParticle::*)(int)) &HepMC3::GenParticle::set_pid, "C++: HepMC3::GenParticle::set_pid(int) --> void", pybind11::arg("pid"));
		cl.def("set_status", (void (HepMC3::GenParticle::*)(int)) &HepMC3::GenParticle::set_status, "C++: HepMC3::GenParticle::set_status(int) --> void", pybind11::arg("status"));
		cl.def("set_momentum", (void (HepMC3::GenParticle::*)(const class HepMC3::FourVector &)) &HepMC3::GenParticle::set_momentum, "C++: HepMC3::GenParticle::set_momentum(const class HepMC3::FourVector &) --> void", pybind11::arg("momentum"));
		cl.def("set_generated_mass", (void (HepMC3::GenParticle::*)(double)) &HepMC3::GenParticle::set_generated_mass, "C++: HepMC3::GenParticle::set_generated_mass(double) --> void", pybind11::arg("m"));
		cl.def("unset_generated_mass", (void (HepMC3::GenParticle::*)()) &HepMC3::GenParticle::unset_generated_mass, "C++: HepMC3::GenParticle::unset_generated_mass() --> void");
		cl.def("add_attribute", (bool (HepMC3::GenParticle::*)(const std::string &, class std::shared_ptr<class HepMC3::Attribute>)) &HepMC3::GenParticle::add_attribute, "Add an attribute to this particle\n\n  This will overwrite existing attribute if an attribute with\n  the same name is present. The attribute will be stored in the\n  parent_event(). \n\n false if there is no parent_event();\n\nC++: HepMC3::GenParticle::add_attribute(const std::string &, class std::shared_ptr<class HepMC3::Attribute>) --> bool", pybind11::arg("name"), pybind11::arg("att"));
		cl.def("attribute_names", (class std::vector<std::string > (HepMC3::GenParticle::*)() const) &HepMC3::GenParticle::attribute_names, "Get list of names of attributes assigned to this particle\n\nC++: HepMC3::GenParticle::attribute_names() const --> class std::vector<std::string >");
		cl.def("remove_attribute", (void (HepMC3::GenParticle::*)(const std::string &)) &HepMC3::GenParticle::remove_attribute, "Remove attribute\n\nC++: HepMC3::GenParticle::remove_attribute(const std::string &) --> void", pybind11::arg("name"));
		cl.def("attribute_as_string", (std::string (HepMC3::GenParticle::*)(const std::string &) const) &HepMC3::GenParticle::attribute_as_string, "Get attribute of any type as string\n\nC++: HepMC3::GenParticle::attribute_as_string(const std::string &) const --> std::string", pybind11::arg("name"));
		cl.def("pdg_id", (int (HepMC3::GenParticle::*)() const) &HepMC3::GenParticle::pdg_id, "Get PDG ID\n \n\n Use pid() instead\n\nC++: HepMC3::GenParticle::pdg_id() const --> int");
		cl.def("set_pdg_id", (void (HepMC3::GenParticle::*)(const int &)) &HepMC3::GenParticle::set_pdg_id, "Set PDG ID\n \n\n Use set_pid() instead\n\nC++: HepMC3::GenParticle::set_pdg_id(const int &) --> void", pybind11::arg("pidin"));
		cl.def("assign", (class HepMC3::GenParticle & (HepMC3::GenParticle::*)(const class HepMC3::GenParticle &)) &HepMC3::GenParticle::operator=, "C++: HepMC3::GenParticle::operator=(const class HepMC3::GenParticle &) --> class HepMC3::GenParticle &", pybind11::return_value_policy::automatic, pybind11::arg(""));

		 binder::custom_GenParticle_binder(cl);
	}
}
