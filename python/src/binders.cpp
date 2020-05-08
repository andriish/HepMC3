#include "binders.h"
#include <HepMC3/Print.h>
namespace binder {




void custom_HEPEVT_Wrapper_binder(pybind11::class_<HepMC3::HEPEVT_Wrapper, std::shared_ptr<HepMC3::HEPEVT_Wrapper>> cl)
{
		cl.def_static("print_hepevt", []() -> void { return HepMC3::HEPEVT_Wrapper::print_hepevt(); }, "");
		//cl.def_static("print_hepevt", (void (*)(std::ostream &)) &HepMC3::HEPEVT_Wrapper::print_hepevt, "Print information from HEPEVT common block \n\nC++: HepMC3::HEPEVT_Wrapper::print_hepevt(std::ostream &) --> void", pybind11::arg("ostr"));
		cl.def_static("print_hepevt", [](pybind11::object  & a1) -> void {  std::stringstream b;  HepMC3::HEPEVT_Wrapper::print_hepevt(b); a1.attr("write")(pybind11::str(b.str().c_str())); }, "Print information from HEPEVT common block \n\nC++: HepMC3::HEPEVT_Wrapper::print_hepevt(std::ostream &) --> void", pybind11::arg("ostr"));
		cl.def_static("print_hepevt_particle", [](int const & a0) -> void { return HepMC3::HEPEVT_Wrapper::print_hepevt_particle(a0); }, "", pybind11::arg("index"));
		//cl.def_static("print_hepevt_particle", (void (*)(int, std::ostream &)) &HepMC3::HEPEVT_Wrapper::print_hepevt_particle, "Print particle information \n\nC++: HepMC3::HEPEVT_Wrapper::print_hepevt_particle(int, std::ostream &) --> void", pybind11::arg("index"), pybind11::arg("ostr"));
		cl.def_static("print_hepevt_particle", [](int a0, pybind11::object  & a1) -> void {  std::stringstream b;  HepMC3::HEPEVT_Wrapper::print_hepevt_particle(a0,b); a1.attr("write")(pybind11::str(b.str().c_str())); }, "Print particle information \n\nC++: HepMC3::HEPEVT_Wrapper::print_hepevt_particle(int, std::ostream &) --> void", pybind11::arg("index"), pybind11::arg("ostr"));
	
	};

void custom_GenEvent_binder(pybind11::class_<HepMC3::GenEvent, std::shared_ptr<HepMC3::GenEvent>> cl)
{
		//cl.def("attribute", [](HepMC3::GenEvent const &o, const class std::basic_string<char> & a0) -> std::shared_ptr<class HepMC3::GenHeavyIon> { return o.attribute(a0); }, "", pybind11::arg("name"));
		cl.def("attribute", (class std::shared_ptr<class HepMC3::GenHeavyIon> (HepMC3::GenEvent::*)(const std::string &, const int &) const) &HepMC3::GenEvent::attribute<HepMC3::GenHeavyIon>, "C++: HepMC3::GenEvent::attribute(const std::string &, const int &) const --> class std::shared_ptr<class HepMC3::GenHeavyIon>", pybind11::arg("name"), pybind11::arg("id"));
		//cl.def("attribute", [](HepMC3::GenEvent const &o, const class std::basic_string<char> & a0) -> std::shared_ptr<class HepMC3::GenPdfInfo> { return o.attribute(a0); }, "", pybind11::arg("name"));
		cl.def("attribute", (class std::shared_ptr<class HepMC3::GenPdfInfo> (HepMC3::GenEvent::*)(const std::string &, const int &) const) &HepMC3::GenEvent::attribute<HepMC3::GenPdfInfo>, "C++: HepMC3::GenEvent::attribute(const std::string &, const int &) const --> class std::shared_ptr<class HepMC3::GenPdfInfo>", pybind11::arg("name"), pybind11::arg("id"));
		//cl.def("attribute", [](HepMC3::GenEvent const &o, const class std::basic_string<char> & a0) -> std::shared_ptr<class HepMC3::GenCrossSection> { return o.attribute(a0); }, "", pybind11::arg("name"));
		cl.def("attribute", (class std::shared_ptr<class HepMC3::GenCrossSection> (HepMC3::GenEvent::*)(const std::string &, const int &) const) &HepMC3::GenEvent::attribute<HepMC3::GenCrossSection>, "C++: HepMC3::GenEvent::attribute(const std::string &, const int &) const --> class std::shared_ptr<class HepMC3::GenCrossSection>", pybind11::arg("name"), pybind11::arg("id"));

}

void custom_GenRunInfo_binder(pybind11::class_<HepMC3::GenRunInfo, std::shared_ptr<HepMC3::GenRunInfo>> cl)
{

		cl.def("tools", (class std::vector<struct HepMC3::GenRunInfo::ToolInfo, class std::allocator<struct HepMC3::GenRunInfo::ToolInfo> > & (HepMC3::GenRunInfo::*)()) &HepMC3::GenRunInfo::tools, "The vector of tools used to produce this run.\n\nC++: HepMC3::GenRunInfo::tools() --> class std::vector<struct HepMC3::GenRunInfo::ToolInfo, class std::allocator<struct HepMC3::GenRunInfo::ToolInfo> > &", pybind11::return_value_policy::reference_internal);
}


void custom_Units_binder(pybind11::class_<HepMC3::Units, std::shared_ptr<HepMC3::Units>> cl)
{

		//cl.def_static("convert",  []( auto & a1, enum HepMC3::Units::MomentumUnit a2, enum HepMC3::Units::MomentumUnit a3)-> void { HepMC3::Units::convert<decltype(a1)>(a1,a2,a3); }, "C++: HepMC3::Units::convert(class HepMC3::FourVector &, enum HepMC3::Units::MomentumUnit, enum HepMC3::Units::MomentumUnit) --> void", pybind11::arg("m"), pybind11::arg("from"), pybind11::arg("to"));
		//cl.def_static("convert", []( auto & a1, enum HepMC3::Units::LengthUnit a2, enum HepMC3::Units::LengthUnit a3)-> void { HepMC3::Units::convert<decltype(a1)>(a1,a2,a3); }, "C++: HepMC3::Units::convert(class HepMC3::FourVector &, enum HepMC3::Units::MomentumUnit, enum HepMC3::Units::MomentumUnit) --> void", pybind11::arg("m"), pybind11::arg("from"), pybind11::arg("to"));

		cl.def_static("convert",  [](HepMC3::FourVector & a1, enum HepMC3::Units::MomentumUnit a2, enum HepMC3::Units::MomentumUnit a3)-> void { HepMC3::Units::convert<HepMC3::FourVector>(a1,a2,a3); }, "C++: HepMC3::Units::convert(class HepMC3::FourVector &, enum HepMC3::Units::MomentumUnit, enum HepMC3::Units::MomentumUnit) --> void", pybind11::arg("m"), pybind11::arg("from"), pybind11::arg("to"));
		cl.def_static("convert", []( HepMC3::FourVector & a1, enum HepMC3::Units::LengthUnit a2, enum HepMC3::Units::LengthUnit a3)-> void { HepMC3::Units::convert<HepMC3::FourVector>(a1,a2,a3); }, "C++: HepMC3::Units::convert(class HepMC3::FourVector &, enum HepMC3::Units::MomentumUnit, enum HepMC3::Units::MomentumUnit) --> void", pybind11::arg("m"), pybind11::arg("from"), pybind11::arg("to"));
		
		
}


void custom_FourVector_binder(pybind11::class_<HepMC3::FourVector, std::shared_ptr<HepMC3::FourVector>> cl)
{

		cl.def("__getitem__", [](const HepMC3::FourVector& v, size_t i) { if (i==0) return  v.x(); if (i==1) return  v.y(); if (i==2) return  v.z();  if (i==3) return  v.t(); return 0.0;});
		cl.def("__setitem__", [](HepMC3::FourVector& v, size_t i, double  a ) { if (i==0)   { v.setX(a); return; }if (i==1)  { v.setY(a);return; } if (i==2)  { v.setZ(a);return; }  if (i==3) {v.setT(a);return; }});
		cl.def("__len__", [](const HepMC3::FourVector& v) { return 4;});
		
}




 void custom_LHEFTagBase_binder (pybind11::class_<LHEF::TagBase, std::shared_ptr<LHEF::TagBase>> cl)
{

		//cl.def("printattrs", (void (LHEF::TagBase::*)(std::ostream &) const) &LHEF::TagBase::printattrs, "print out ' name=\"value\"' for all unparsed attributes.\n\nC++: LHEF::TagBase::printattrs(std::ostream &) const --> void", pybind11::arg("file"));
		cl.def("printattrs", [](LHEF::TagBase const &o, pybind11::object  & a1) -> void { std::stringstream b;  o.printattrs(b); a1.attr("write")(pybind11::str(b.str().c_str())); }, "print out ' name=\"value\"' for all unparsed attributes.\n\nC++: LHEF::TagBase::printattrs(std::ostream &) const --> void", pybind11::arg("file"));
		//cl.def("closetag", (void (LHEF::TagBase::*)(std::ostream &, std::string) const) &LHEF::TagBase::closetag, "Print out end of tag marker. Print contents if not empty else\n print simple close tag.\n\nC++: LHEF::TagBase::closetag(std::ostream &, std::string) const --> void", pybind11::arg("file"), pybind11::arg("tag"));
		cl.def("closetag", [](LHEF::TagBase const &o, pybind11::object  & a1, std::string a2) -> void { std::stringstream b;  o.closetag(b,a2); a1.attr("write")(pybind11::str(b.str().c_str())); }, "Print out end of tag marker. Print contents if not empty else\n print simple close tag.\n\nC++: LHEF::TagBase::closetag(std::ostream &, std::string) const --> void", pybind11::arg("file"), pybind11::arg("tag"));

};


void	print_binder(pybind11::module &M)
	
	{ // HepMC3::Print file: line:27
        pybind11::class_<HepMC3::Print, std::unique_ptr<HepMC3::Print, pybind11::nodelete> > cl(M, "Print","Implementation of bindings for HepMC3::Print.h");
        pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new HepMC3::Print(); } ) );

		//cl.def_static("content", (void (*)(std::ostream &, const class HepMC3::GenEvent &)) &HepMC3::Print::content, "Print content of all GenEvent containers\n\nC++: HepMC3::Print::content(std::ostream &, const class HepMC3::GenEvent &) --> void", pybind11::arg("os"), pybind11::arg("event"));
		cl.def_static("content", [](pybind11::object  & a0, const class HepMC3::GenEvent & a1) -> void {  std::stringstream b; HepMC3::Print::content(b,a1);   a0.attr("write")(pybind11::str(b.str().c_str()));  }, "Print content of all GenEvent containers\n\nC++: HepMC3::Print::content(std::ostream &, const class HepMC3::GenEvent &) --> void", pybind11::arg("os"), pybind11::arg("event"));
		cl.def_static("content", (void (*)(const class HepMC3::GenEvent &)) &HepMC3::Print::content, "Print content of all GenEvent containers to std::cout\n\nC++: HepMC3::Print::content(const class HepMC3::GenEvent &) --> void", pybind11::arg("event"));
		
		//
		cl.def_static("listing", [](pybind11::object  & a0, const class HepMC3::GenEvent & a1) -> void {  std::stringstream b; HepMC3::Print::listing(b, a1);   a0.attr("write")(pybind11::str(b.str().c_str()));  }, "", pybind11::arg("os"), pybind11::arg("event"));
		//cl.def_static("listing", (void (*)(std::ostream &, const class HepMC3::GenEvent &, unsigned short)) &HepMC3::Print::listing, "Print event in listing (HepMC2) format\n\nC++: HepMC3::Print::listing(std::ostream &, const class HepMC3::GenEvent &, unsigned short) --> void", pybind11::arg("os"), pybind11::arg("event"), pybind11::arg("precision"));
		cl.def_static("listing", [](pybind11::object  & a0, const class HepMC3::GenEvent & a1,unsigned short a2) -> void {  std::stringstream b; HepMC3::Print::listing(b, a1,a2);   a0.attr("write")(pybind11::str(b.str().c_str()));  }, "Print event in listing (HepMC2) format\n\nC++: HepMC3::Print::listing(std::ostream &, const class HepMC3::GenEvent &, unsigned short) --> void", pybind11::arg("os"), pybind11::arg("event"), pybind11::arg("precision"));
		cl.def_static("listing", [](const class HepMC3::GenEvent & a0) -> void { return HepMC3::Print::listing(a0); }, "", pybind11::arg("event"));
		cl.def_static("listing", (void (*)(const class HepMC3::GenEvent &, unsigned short)) &HepMC3::Print::listing, "Print event in listing (HepMC2) format  to std::cout\n\nC++: HepMC3::Print::listing(const class HepMC3::GenEvent &, unsigned short) --> void", pybind11::arg("event"), pybind11::arg("precision"));
		
		//cl.def_static("listing", [](class std::basic_ostream<char> & a0, const class HepMC3::GenRunInfo & a1) -> void { return HepMC3::Print::listing(a0, a1); }, "", pybind11::arg("os"), pybind11::arg("ri"));
		cl.def_static("listing", [](pybind11::object  & a0, const class HepMC3::GenRunInfo & a1) -> void {  std::stringstream b; HepMC3::Print::listing(b, a1);   a0.attr("write")(pybind11::str(b.str().c_str()));  }, "", pybind11::arg("os"), pybind11::arg("ri"));
		
		//cl.def_static("listing", (void (*)(std::ostream &, const class HepMC3::GenRunInfo &, unsigned short)) &HepMC3::Print::listing, "Print runinfo in listing\n\nC++: HepMC3::Print::listing(std::ostream &, const class HepMC3::GenRunInfo &, unsigned short) --> void", pybind11::arg("os"), pybind11::arg("ri"), pybind11::arg("precision"));
		cl.def_static("listing", [](pybind11::object  & a0, const class HepMC3::GenRunInfo & a1,unsigned short a2) -> void {  std::stringstream b; HepMC3::Print::listing(b, a1,a2);   a0.attr("write")(pybind11::str(b.str().c_str()));  }, "Print runinfo in listing\n\nC++: HepMC3::Print::listing(std::ostream &, const class HepMC3::GenRunInfo &, unsigned short) --> void", pybind11::arg("os"), pybind11::arg("ri"), pybind11::arg("precision"));
		cl.def_static("listing", [](const class HepMC3::GenRunInfo & a0) -> void { return HepMC3::Print::listing(a0); }, "", pybind11::arg("ri"));
		cl.def_static("listing", (void (*)(const class HepMC3::GenRunInfo &, unsigned short)) &HepMC3::Print::listing, "Print runinfo in listing  to std::cout\n\nC++: HepMC3::Print::listing(const class HepMC3::GenRunInfo &, unsigned short) --> void", pybind11::arg("ri"), pybind11::arg("precision"));
		
		//cl.def_static("line", [](class std::basic_ostream<char> & a0, const class HepMC3::GenEvent & a1) -> void { return HepMC3::Print::line(a0, a1); }, "", pybind11::arg("os"), pybind11::arg("event"));
		cl.def_static("line", [](pybind11::object  & a0, const class HepMC3::GenEvent & a1) -> void {  std::stringstream b; HepMC3::Print::line(b, a1);   a0.attr("write")(pybind11::str(b.str().c_str()));  }, "", pybind11::arg("os"), pybind11::arg("event"));
		//cl.def_static("line", (void (*)(std::ostream &, const class HepMC3::GenEvent &, bool)) &HepMC3::Print::line, "Print one-line info\n\nC++: HepMC3::Print::line(std::ostream &, const class HepMC3::GenEvent &, bool) --> void", pybind11::arg("os"), pybind11::arg("event"), pybind11::arg("attributes"));
		cl.def_static("line", [](pybind11::object  & a0, const class HepMC3::GenEvent & a1, bool a2) -> void {  std::stringstream b; HepMC3::Print::line(b, a1, a2);   a0.attr("write")(pybind11::str(b.str().c_str()));  }, "Print one-line info\n\nC++: HepMC3::Print::line(std::ostream &, const class HepMC3::GenEvent &, bool) --> void", pybind11::arg("os"), pybind11::arg("event"), pybind11::arg("attributes"));
		cl.def_static("line", [](const class HepMC3::GenEvent & a0) -> void { return HepMC3::Print::line(a0); }, "", pybind11::arg("event"));
		cl.def_static("line", (void (*)(const class HepMC3::GenEvent &, bool)) &HepMC3::Print::line, "Print one-line info to std::cout\n\nC++: HepMC3::Print::line(const class HepMC3::GenEvent &, bool) --> void", pybind11::arg("event"), pybind11::arg("attributes"));
		
		//cl.def_static("line", [](class std::basic_ostream<char> & a0, const class HepMC3::GenRunInfo & a1) -> void { return HepMC3::Print::line(a0, a1); }, "", pybind11::arg("os"), pybind11::arg("RunInfo"));
		cl.def_static("line", [](pybind11::object  & a0, const class HepMC3::GenRunInfo & a1) -> void {  std::stringstream b; HepMC3::Print::line(b, a1);   a0.attr("write")(pybind11::str(b.str().c_str()));  }, "", pybind11::arg("os"), pybind11::arg("RunInfo"));
		//cl.def_static("line", (void (*)(std::ostream &, const class HepMC3::GenRunInfo &, bool)) &HepMC3::Print::line, "Print one-line info\n\nC++: HepMC3::Print::line(std::ostream &, const class HepMC3::GenRunInfo &, bool) --> void", pybind11::arg("os"), pybind11::arg("RunInfo"), pybind11::arg("attributes"));
		cl.def_static("line", [](pybind11::object  & a0, const class HepMC3::GenRunInfo & a1, bool a2) -> void {  std::stringstream b; HepMC3::Print::line(b, a1, a2);   a0.attr("write")(pybind11::str(b.str().c_str()));  }, "Print one-line info\n\nC++: HepMC3::Print::line(std::ostream &, const class HepMC3::GenRunInfo &, bool) --> void", pybind11::arg("os"), pybind11::arg("RunInfo"), pybind11::arg("attributes"));
		cl.def_static("line", [](const class HepMC3::GenRunInfo & a0) -> void { return HepMC3::Print::line(a0); }, "", pybind11::arg("RunInfo"));
		cl.def_static("line", (void (*)(const class HepMC3::GenRunInfo &, bool)) &HepMC3::Print::line, "Print one-line info to std::cout\n\nC++: HepMC3::Print::line(const class HepMC3::GenRunInfo &, bool) --> void", pybind11::arg("RunInfo"), pybind11::arg("attributes"));
		
		//cl.def_static("line", (void (*)(std::ostream &, const struct HepMC3::GenRunInfo::ToolInfo &)) &HepMC3::Print::line, "Print one-line info\n\nC++: HepMC3::Print::line(std::ostream &, const struct HepMC3::GenRunInfo::ToolInfo &) --> void", pybind11::arg("os"), pybind11::arg("t"));
		cl.def_static("line", [](pybind11::object  & a0, const struct HepMC3::GenRunInfo::ToolInfo & a1) -> void {  std::stringstream b; HepMC3::Print::line(b, a1);   a0.attr("write")(pybind11::str(b.str().c_str()));  }, "Print one-line info\n\nC++: HepMC3::Print::line(std::ostream &, const struct HepMC3::GenRunInfo::ToolInfo &) --> void", pybind11::arg("os"), pybind11::arg("t"));
		cl.def_static("line", (void (*)(const struct HepMC3::GenRunInfo::ToolInfo &)) &HepMC3::Print::line, "Print one-line info to std::cout\n\nC++: HepMC3::Print::line(const struct HepMC3::GenRunInfo::ToolInfo &) --> void", pybind11::arg("t"));
		
		//cl.def_static("line", (void (*)(std::ostream &, const class HepMC3::FourVector &)) &HepMC3::Print::line, "Print one-line info\n\nC++: HepMC3::Print::line(std::ostream &, const class HepMC3::FourVector &) --> void", pybind11::arg("os"), pybind11::arg("p"));
		cl.def_static("line", [](pybind11::object  & a0, const class HepMC3::FourVector & a1) -> void {  std::stringstream b; HepMC3::Print::line(b, a1);   a0.attr("write")(pybind11::str(b.str().c_str()));  }, "Print one-line info\n\nC++: HepMC3::Print::line(std::ostream &, const class HepMC3::FourVector &) --> void", pybind11::arg("os"), pybind11::arg("p"));
		cl.def_static("line", (void (*)(const class HepMC3::FourVector &)) &HepMC3::Print::line, "Print one-line info to std::cout\n\nC++: HepMC3::Print::line(const class HepMC3::FourVector &) --> void", pybind11::arg("p"));

		//cl.def_static("line", (void (*)(std::ostream &, class std::shared_ptr<class HepMC3::GenCrossSection> &)) &HepMC3::Print::line, "Print one-line info\n\nC++: HepMC3::Print::line(std::ostream &, class std::shared_ptr<class HepMC3::GenCrossSection> &) --> void", pybind11::arg("os"), pybind11::arg("cs"));
		cl.def_static("line", [](pybind11::object  & a0, class std::shared_ptr<class HepMC3::GenCrossSection> & a1) -> void {  std::stringstream b; HepMC3::Print::line(b, a1);   a0.attr("write")(pybind11::str(b.str().c_str()));  }, "Print one-line info\n\nC++: HepMC3::Print::line(std::ostream &, class std::shared_ptr<class HepMC3::GenCrossSection> &) --> void", pybind11::arg("os"), pybind11::arg("cs"));
		cl.def_static("line", (void (*)(class std::shared_ptr<class HepMC3::GenCrossSection> &)) &HepMC3::Print::line, "Print one-line info to std::cout\n\nC++: HepMC3::Print::line(class std::shared_ptr<class HepMC3::GenCrossSection> &) --> void", pybind11::arg("cs"));
		
		//cl.def_static("line", (void (*)(std::ostream &, class std::shared_ptr<class HepMC3::GenHeavyIon> &)) &HepMC3::Print::line, "Print one-line info\n\nC++: HepMC3::Print::line(std::ostream &, class std::shared_ptr<class HepMC3::GenHeavyIon> &) --> void", pybind11::arg("os"), pybind11::arg("hi"));
		cl.def_static("line", [](pybind11::object  & a0, class std::shared_ptr<class HepMC3::GenHeavyIon> & a1) -> void {  std::stringstream b; HepMC3::Print::line(b, a1);   a0.attr("write")(pybind11::str(b.str().c_str()));  }, "Print one-line info\n\nC++: HepMC3::Print::line(std::ostream &, class std::shared_ptr<class HepMC3::GenHeavyIon> &) --> void", pybind11::arg("os"), pybind11::arg("hi"));
		cl.def_static("line", (void (*)(class std::shared_ptr<class HepMC3::GenHeavyIon> &)) &HepMC3::Print::line, "Print one-line info to std::cout\n\nC++: HepMC3::Print::line(class std::shared_ptr<class HepMC3::GenHeavyIon> &) --> void", pybind11::arg("hi"));
		
		//cl.def_static("line", (void (*)(std::ostream &, class std::shared_ptr<class HepMC3::GenPdfInfo> &)) &HepMC3::Print::line, "Print one-line info\n\nC++: HepMC3::Print::line(std::ostream &, class std::shared_ptr<class HepMC3::GenPdfInfo> &) --> void", pybind11::arg("os"), pybind11::arg("pi"));
		cl.def_static("line", [](pybind11::object  & a0, class std::shared_ptr<class HepMC3::GenPdfInfo> & a1) -> void {  std::stringstream b; HepMC3::Print::line(b, a1);   a0.attr("write")(pybind11::str(b.str().c_str()));  }, "Print one-line info\n\nC++: HepMC3::Print::line(std::ostream &, class std::shared_ptr<class HepMC3::GenPdfInfo> &) --> void", pybind11::arg("os"), pybind11::arg("pi"));
		cl.def_static("line", (void (*)(class std::shared_ptr<class HepMC3::GenPdfInfo> &)) &HepMC3::Print::line, "Print one-line info to std::cout\n\nC++: HepMC3::Print::line(class std::shared_ptr<class HepMC3::GenPdfInfo> &) --> void", pybind11::arg("pi"));


		//cl.def_static("line", [](class std::basic_ostream<char> & a0, class std::shared_ptr<const class HepMC3::GenVertex> const & a1) -> void { return HepMC3::Print::line(a0, a1); }, "", pybind11::arg("os"), pybind11::arg("v"));
		cl.def_static("line", [](pybind11::object  & a0, class std::shared_ptr<const class HepMC3::GenVertex> const & a1) -> void {  std::stringstream b; HepMC3::Print::line(b, a1);   a0.attr("write")(pybind11::str(b.str().c_str()));  }, "", pybind11::arg("os"), pybind11::arg("v"));
		//cl.def_static("line", (void (*)(std::ostream &, class std::shared_ptr<const class HepMC3::GenVertex>, bool)) &HepMC3::Print::line, "Print one-line info\n\nC++: HepMC3::Print::line(std::ostream &, class std::shared_ptr<const class HepMC3::GenVertex>, bool) --> void", pybind11::arg("os"), pybind11::arg("v"), pybind11::arg("attributes"));
		cl.def_static("line", [](pybind11::object  & a0, class std::shared_ptr<const class HepMC3::GenVertex> const & a1, bool a2) -> void {  std::stringstream b; HepMC3::Print::line(b, a1,a2);   a0.attr("write")(pybind11::str(b.str().c_str()));  }, "Print one-line info\n\nC++: HepMC3::Print::line(std::ostream &, class std::shared_ptr<const class HepMC3::GenVertex>, bool) --> void", pybind11::arg("os"), pybind11::arg("v"), pybind11::arg("attributes"));
		cl.def_static("line", [](class std::shared_ptr<const class HepMC3::GenVertex> const & a0) -> void { return HepMC3::Print::line(a0); }, "", pybind11::arg("v"));
		cl.def_static("line", (void (*)(class std::shared_ptr<const class HepMC3::GenVertex>, bool)) &HepMC3::Print::line, "Print one-line info to std::cout\n\nC++: HepMC3::Print::line(class std::shared_ptr<const class HepMC3::GenVertex>, bool) --> void", pybind11::arg("v"), pybind11::arg("attributes"));
		
		
		//cl.def_static("line", [](class std::basic_ostream<char> & a0, class std::shared_ptr<const class HepMC3::GenParticle> const & a1) -> void { return HepMC3::Print::line(a0, a1); }, "", pybind11::arg("os"), pybind11::arg("p"));
		cl.def_static("line", [](pybind11::object  & a0, class std::shared_ptr<const class HepMC3::GenParticle> const & a1) -> void {  std::stringstream b; HepMC3::Print::line(b, a1);   a0.attr("write")(pybind11::str(b.str().c_str()));  }, "", pybind11::arg("os"), pybind11::arg("p"));
		//cl.def_static("line", (void (*)(std::ostream &, class std::shared_ptr<const class HepMC3::GenParticle>, bool)) &HepMC3::Print::line, "Print one-line info\n\nC++: HepMC3::Print::line(std::ostream &, class std::shared_ptr<const class HepMC3::GenParticle>, bool) --> void", pybind11::arg("os"), pybind11::arg("p"), pybind11::arg("attributes"));
		cl.def_static("line", [](pybind11::object  & a0, class std::shared_ptr<const class HepMC3::GenParticle> const & a1, bool a2) -> void {  std::stringstream b; HepMC3::Print::line(b, a1,a2);   a0.attr("write")(pybind11::str(b.str().c_str()));  }, "Print one-line info\n\nC++: HepMC3::Print::line(std::ostream &, class std::shared_ptr<const class HepMC3::GenParticle>, bool) --> void", pybind11::arg("os"), pybind11::arg("p"), pybind11::arg("attributes"));
		cl.def_static("line", [](class std::shared_ptr<const class HepMC3::GenParticle> const & a0) -> void { return HepMC3::Print::line(a0); }, "", pybind11::arg("p"));
		cl.def_static("line", (void (*)(class std::shared_ptr<const class HepMC3::GenParticle>, bool)) &HepMC3::Print::line, "Print one-line info to std::cout\n\nC++: HepMC3::Print::line(class std::shared_ptr<const class HepMC3::GenParticle>, bool) --> void", pybind11::arg("p"), pybind11::arg("attributes"));
		
	}

} // namespace binder

