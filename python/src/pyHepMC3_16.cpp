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

void bind_pyHepMC3_16(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // HepMC3::GenRunInfo file:HepMC3/GenRunInfo.h line:33
		pybind11::class_<HepMC3::GenRunInfo, std::shared_ptr<HepMC3::GenRunInfo>> cl(M("HepMC3"), "GenRunInfo", "Stores run-related information\n\n Manages run-related information.\n Contains run-wide attributes");
		cl.def( pybind11::init( [](){ return new HepMC3::GenRunInfo(); } ) );
		cl.def( pybind11::init( [](HepMC3::GenRunInfo const &o){ return new HepMC3::GenRunInfo(o); } ) );
		cl.def("attribute", (class std::shared_ptr<class HepMC3::GenHeavyIon> (HepMC3::GenRunInfo::*)(const std::string &) const) &HepMC3::GenRunInfo::attribute<HepMC3::GenHeavyIon>, "C++: HepMC3::GenRunInfo::attribute(const std::string &) const --> class std::shared_ptr<class HepMC3::GenHeavyIon>", pybind11::arg("name"));
		cl.def("attribute", (class std::shared_ptr<class HepMC3::GenPdfInfo> (HepMC3::GenRunInfo::*)(const std::string &) const) &HepMC3::GenRunInfo::attribute<HepMC3::GenPdfInfo>, "C++: HepMC3::GenRunInfo::attribute(const std::string &) const --> class std::shared_ptr<class HepMC3::GenPdfInfo>", pybind11::arg("name"));
		cl.def("attribute", (class std::shared_ptr<class HepMC3::GenCrossSection> (HepMC3::GenRunInfo::*)(const std::string &) const) &HepMC3::GenRunInfo::attribute<HepMC3::GenCrossSection>, "C++: HepMC3::GenRunInfo::attribute(const std::string &) const --> class std::shared_ptr<class HepMC3::GenCrossSection>", pybind11::arg("name"));
		cl.def("assign", (class HepMC3::GenRunInfo & (HepMC3::GenRunInfo::*)(const class HepMC3::GenRunInfo &)) &HepMC3::GenRunInfo::operator=, "Assignmet\n\nC++: HepMC3::GenRunInfo::operator=(const class HepMC3::GenRunInfo &) --> class HepMC3::GenRunInfo &", pybind11::return_value_policy::automatic, pybind11::arg("r"));
		cl.def("has_weight", (bool (HepMC3::GenRunInfo::*)(const std::string &) const) &HepMC3::GenRunInfo::has_weight, "Check if a weight name is present.\n\nC++: HepMC3::GenRunInfo::has_weight(const std::string &) const --> bool", pybind11::arg("name"));
		cl.def("weight_indices", (class std::map<std::string, int> (HepMC3::GenRunInfo::*)() const) &HepMC3::GenRunInfo::weight_indices, "Returns a copy of indices map.\n\nC++: HepMC3::GenRunInfo::weight_indices() const --> class std::map<std::string, int>");
		cl.def("weight_index", (int (HepMC3::GenRunInfo::*)(const std::string &) const) &HepMC3::GenRunInfo::weight_index, "Return the index corresponding to a weight name.\n \n\n -1 if name was not found\n\nC++: HepMC3::GenRunInfo::weight_index(const std::string &) const --> int", pybind11::arg("name"));
		cl.def("weight_names", (const class std::vector<std::string > & (HepMC3::GenRunInfo::*)() const) &HepMC3::GenRunInfo::weight_names, "Get the vector of weight names.\n\nC++: HepMC3::GenRunInfo::weight_names() const --> const class std::vector<std::string > &", pybind11::return_value_policy::automatic);
		cl.def("set_weight_names", (void (HepMC3::GenRunInfo::*)(const class std::vector<std::string > &)) &HepMC3::GenRunInfo::set_weight_names, "Set the names of the weights in this run.\n\n For consistency, the length of the vector should be the same as\n the number of weights in the events in the run.\n\nC++: HepMC3::GenRunInfo::set_weight_names(const class std::vector<std::string > &) --> void", pybind11::arg("names"));
		cl.def("add_attribute", (void (HepMC3::GenRunInfo::*)(const std::string &, const class std::shared_ptr<class HepMC3::Attribute> &)) &HepMC3::GenRunInfo::add_attribute, "add an attribute\n This will overwrite existing attribute if an attribute\n with the same name is present\n\nC++: HepMC3::GenRunInfo::add_attribute(const std::string &, const class std::shared_ptr<class HepMC3::Attribute> &) --> void", pybind11::arg("name"), pybind11::arg("att"));
		cl.def("remove_attribute", (void (HepMC3::GenRunInfo::*)(const std::string &)) &HepMC3::GenRunInfo::remove_attribute, "Remove attribute\n\nC++: HepMC3::GenRunInfo::remove_attribute(const std::string &) --> void", pybind11::arg("name"));
		cl.def("attribute_as_string", (std::string (HepMC3::GenRunInfo::*)(const std::string &) const) &HepMC3::GenRunInfo::attribute_as_string, "Get attribute of any type as string\n\nC++: HepMC3::GenRunInfo::attribute_as_string(const std::string &) const --> std::string", pybind11::arg("name"));
		cl.def("attribute_names", (class std::vector<std::string > (HepMC3::GenRunInfo::*)() const) &HepMC3::GenRunInfo::attribute_names, "Get list of attribute names\n\nC++: HepMC3::GenRunInfo::attribute_names() const --> class std::vector<std::string >");
		cl.def("attributes", (class std::map<std::string, class std::shared_ptr<class HepMC3::Attribute> > (HepMC3::GenRunInfo::*)() const) &HepMC3::GenRunInfo::attributes, "Get a copy of the list of attributes\n \n\n To avoid thread issues, this is returns a copy. Better solution may be needed.\n\nC++: HepMC3::GenRunInfo::attributes() const --> class std::map<std::string, class std::shared_ptr<class HepMC3::Attribute> >");
		cl.def("write_data", (void (HepMC3::GenRunInfo::*)(struct HepMC3::GenRunInfoData &) const) &HepMC3::GenRunInfo::write_data, "Fill GenRunInfoData object\n\nC++: HepMC3::GenRunInfo::write_data(struct HepMC3::GenRunInfoData &) const --> void", pybind11::arg("data"));
		cl.def("read_data", (void (HepMC3::GenRunInfo::*)(const struct HepMC3::GenRunInfoData &)) &HepMC3::GenRunInfo::read_data, "Fill GenRunInfo based on GenRunInfoData\n\nC++: HepMC3::GenRunInfo::read_data(const struct HepMC3::GenRunInfoData &) --> void", pybind11::arg("data"));

		 binder::custom_GenRunInfo_binder(cl);

		{ // HepMC3::GenRunInfo::ToolInfo file:HepMC3/GenRunInfo.h line:38
			auto & enclosing_class = cl;
			pybind11::class_<HepMC3::GenRunInfo::ToolInfo, std::shared_ptr<HepMC3::GenRunInfo::ToolInfo>> cl(enclosing_class, "ToolInfo", "Interrnal struct for keeping track of tools.");
			cl.def( pybind11::init( [](HepMC3::GenRunInfo::ToolInfo const &o){ return new HepMC3::GenRunInfo::ToolInfo(o); } ) );
			cl.def( pybind11::init( [](){ return new HepMC3::GenRunInfo::ToolInfo(); } ) );
			cl.def_readwrite("name", &HepMC3::GenRunInfo::ToolInfo::name);
			cl.def_readwrite("version", &HepMC3::GenRunInfo::ToolInfo::version);
			cl.def_readwrite("description", &HepMC3::GenRunInfo::ToolInfo::description);
			cl.def("assign", (struct HepMC3::GenRunInfo::ToolInfo & (HepMC3::GenRunInfo::ToolInfo::*)(const struct HepMC3::GenRunInfo::ToolInfo &)) &HepMC3::GenRunInfo::ToolInfo::operator=, "C++: HepMC3::GenRunInfo::ToolInfo::operator=(const struct HepMC3::GenRunInfo::ToolInfo &) --> struct HepMC3::GenRunInfo::ToolInfo &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		}

	}
}
