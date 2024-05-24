#include <HepMC3/LHEF.h>
#include <functional>
#include <ios>
#include <iterator>
#include <locale>
#include <map>
#include <memory>
#include <ostream>
#include <set>
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

void bind_pyHepMC3_15(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // LHEF::OAttr file:HepMC3/LHEF.h line:
		pybind11::class_<LHEF::OAttr<std::string>, std::shared_ptr<LHEF::OAttr<std::string>>> cl(M("LHEF"), "OAttr_std_string_t", "");
		cl.def( pybind11::init<std::string, const std::string &>(), pybind11::arg("n"), pybind11::arg("v") );

		cl.def( pybind11::init( [](LHEF::OAttr<std::string> const &o){ return new LHEF::OAttr<std::string>(o); } ) );
		cl.def_readwrite("name", &LHEF::OAttr<std::string>::name);
		cl.def_readwrite("val", &LHEF::OAttr<std::string>::val);
		cl.def("assign", (struct LHEF::OAttr<std::string > & (LHEF::OAttr<std::string>::*)(const struct LHEF::OAttr<std::string > &)) &LHEF::OAttr<std::string>::operator=, "C++: LHEF::OAttr<std::string>::operator=(const struct LHEF::OAttr<std::string > &) --> struct LHEF::OAttr<std::string > &", pybind11::return_value_policy::automatic, pybind11::arg(""));

		cl.def("__str__", [](LHEF::OAttr<std::string> const &o) -> std::string { std::ostringstream s; using namespace LHEF; s << o; return s.str(); } );
	}
	{ // LHEF::OAttr file:HepMC3/LHEF.h line:
		pybind11::class_<LHEF::OAttr<long>, std::shared_ptr<LHEF::OAttr<long>>> cl(M("LHEF"), "OAttr_long_t", "");
		cl.def( pybind11::init<std::string, const long &>(), pybind11::arg("n"), pybind11::arg("v") );

		cl.def( pybind11::init( [](LHEF::OAttr<long> const &o){ return new LHEF::OAttr<long>(o); } ) );
		cl.def_readwrite("name", &LHEF::OAttr<long>::name);
		cl.def_readwrite("val", &LHEF::OAttr<long>::val);
		cl.def("assign", (struct LHEF::OAttr<long> & (LHEF::OAttr<long>::*)(const struct LHEF::OAttr<long> &)) &LHEF::OAttr<long>::operator=, "C++: LHEF::OAttr<long>::operator=(const struct LHEF::OAttr<long> &) --> struct LHEF::OAttr<long> &", pybind11::return_value_policy::automatic, pybind11::arg(""));

		cl.def("__str__", [](LHEF::OAttr<long> const &o) -> std::string { std::ostringstream s; using namespace LHEF; s << o; return s.str(); } );
	}
	{ // LHEF::OAttr file:HepMC3/LHEF.h line:
		pybind11::class_<LHEF::OAttr<double>, std::shared_ptr<LHEF::OAttr<double>>> cl(M("LHEF"), "OAttr_double_t", "");
		cl.def( pybind11::init<std::string, const double &>(), pybind11::arg("n"), pybind11::arg("v") );

		cl.def( pybind11::init( [](LHEF::OAttr<double> const &o){ return new LHEF::OAttr<double>(o); } ) );
		cl.def_readwrite("name", &LHEF::OAttr<double>::name);
		cl.def_readwrite("val", &LHEF::OAttr<double>::val);
		cl.def("assign", (struct LHEF::OAttr<double> & (LHEF::OAttr<double>::*)(const struct LHEF::OAttr<double> &)) &LHEF::OAttr<double>::operator=, "C++: LHEF::OAttr<double>::operator=(const struct LHEF::OAttr<double> &) --> struct LHEF::OAttr<double> &", pybind11::return_value_policy::automatic, pybind11::arg(""));

		cl.def("__str__", [](LHEF::OAttr<double> const &o) -> std::string { std::ostringstream s; using namespace LHEF; s << o; return s.str(); } );
	}
	{ // LHEF::OAttr file:HepMC3/LHEF.h line:
		pybind11::class_<LHEF::OAttr<int>, std::shared_ptr<LHEF::OAttr<int>>> cl(M("LHEF"), "OAttr_int_t", "");
		cl.def( pybind11::init<std::string, const int &>(), pybind11::arg("n"), pybind11::arg("v") );

		cl.def( pybind11::init( [](LHEF::OAttr<int> const &o){ return new LHEF::OAttr<int>(o); } ) );
		cl.def_readwrite("name", &LHEF::OAttr<int>::name);
		cl.def_readwrite("val", &LHEF::OAttr<int>::val);
		cl.def("assign", (struct LHEF::OAttr<int> & (LHEF::OAttr<int>::*)(const struct LHEF::OAttr<int> &)) &LHEF::OAttr<int>::operator=, "C++: LHEF::OAttr<int>::operator=(const struct LHEF::OAttr<int> &) --> struct LHEF::OAttr<int> &", pybind11::return_value_policy::automatic, pybind11::arg(""));

		cl.def("__str__", [](LHEF::OAttr<int> const &o) -> std::string { std::ostringstream s; using namespace LHEF; s << o; return s.str(); } );
	}
	// LHEF::oattr(std::string, const std::string &) file:HepMC3/LHEF.h line:
	M("LHEF").def("oattr", (struct LHEF::OAttr<std::string > (*)(std::string, const std::string &)) &LHEF::oattr<std::string>, "C++: LHEF::oattr(std::string, const std::string &) --> struct LHEF::OAttr<std::string >", pybind11::arg("name"), pybind11::arg("value"));

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
		cl.def("getattr", (bool (LHEF::XMLTag::*)(std::string, double &) const) &LHEF::XMLTag::getattr, "Find an attribute named  and set the double variable  to\n the corresponding value. \n\n false if no attribute was found.\n\nC++: LHEF::XMLTag::getattr(std::string, double &) const --> bool", pybind11::arg("n"), pybind11::arg("v"));
		cl.def("getattr", (bool (LHEF::XMLTag::*)(std::string, bool &) const) &LHEF::XMLTag::getattr, "Find an attribute named  and set the bool variable  to\n true if the corresponding value is \"yes\". \n\n false if no\n attribute was found.\n\nC++: LHEF::XMLTag::getattr(std::string, bool &) const --> bool", pybind11::arg("n"), pybind11::arg("v"));
		cl.def("getattr", (bool (LHEF::XMLTag::*)(std::string, long &) const) &LHEF::XMLTag::getattr, "Find an attribute named  and set the long variable  to\n the corresponding value. \n\n false if no attribute was found.\n\nC++: LHEF::XMLTag::getattr(std::string, long &) const --> bool", pybind11::arg("n"), pybind11::arg("v"));
		cl.def("getattr", (bool (LHEF::XMLTag::*)(std::string, int &) const) &LHEF::XMLTag::getattr, "Find an attribute named  and set the long variable  to\n the corresponding value. \n\n false if no attribute was found.\n\nC++: LHEF::XMLTag::getattr(std::string, int &) const --> bool", pybind11::arg("n"), pybind11::arg("v"));
		cl.def("getattr", (bool (LHEF::XMLTag::*)(std::string, std::string &) const) &LHEF::XMLTag::getattr, "Find an attribute named  and set the string variable  to\n the corresponding value. \n\n false if no attribute was found.\n\nC++: LHEF::XMLTag::getattr(std::string, std::string &) const --> bool", pybind11::arg("n"), pybind11::arg("v"));
		cl.def_static("findXMLTags", [](std::string const & a0) -> std::vector<struct LHEF::XMLTag *> { return LHEF::XMLTag::findXMLTags(a0); }, "", pybind11::arg("str"));
		cl.def_static("findXMLTags", (class std::vector<struct LHEF::XMLTag *> (*)(std::string, std::string *)) &LHEF::XMLTag::findXMLTags, "Scan the given string and return all XML tags found as a vector\n of pointers to XMLTag objects. Text which does not belong to any\n tag is stored in tags without name and in the string pointed to\n by leftover (if not null).\n\nC++: LHEF::XMLTag::findXMLTags(std::string, std::string *) --> class std::vector<struct LHEF::XMLTag *>", pybind11::arg("str"), pybind11::arg("leftover"));
		cl.def_static("deleteAll", (void (*)(class std::vector<struct LHEF::XMLTag *> &)) &LHEF::XMLTag::deleteAll, "Delete all tags in a vector.\n\nC++: LHEF::XMLTag::deleteAll(class std::vector<struct LHEF::XMLTag *> &) --> void", pybind11::arg("tags"));
		cl.def("assign", (struct LHEF::XMLTag & (LHEF::XMLTag::*)(const struct LHEF::XMLTag &)) &LHEF::XMLTag::operator=, "C++: LHEF::XMLTag::operator=(const struct LHEF::XMLTag &) --> struct LHEF::XMLTag &", pybind11::return_value_policy::automatic, pybind11::arg(""));

		binder::custom_T_binder<LHEF::XMLTag>(cl);
	}
	// LHEF::hashline(std::string) file:HepMC3/LHEF.h line:
	M("LHEF").def("hashline", (std::string (*)(std::string)) &LHEF::hashline, "Helper function to make sure that each line in the string  starts with a\n #-character and that the string ends with a new-line.\n\nC++: LHEF::hashline(std::string) --> std::string", pybind11::arg("s"));

	{ // LHEF::TagBase file:HepMC3/LHEF.h line:
		pybind11::class_<LHEF::TagBase, std::shared_ptr<LHEF::TagBase>> cl(M("LHEF"), "TagBase", "This is the base class of all classes representing xml tags.");
		cl.def( pybind11::init( [](){ return new LHEF::TagBase(); } ) );
		cl.def( pybind11::init( [](const class std::map<std::string, std::string > & a0){ return new LHEF::TagBase(a0); } ), "doc" , pybind11::arg("attr"));
		cl.def( pybind11::init<const class std::map<std::string, std::string > &, std::string>(), pybind11::arg("attr"), pybind11::arg("conts") );

		cl.def( pybind11::init( [](LHEF::TagBase const &o){ return new LHEF::TagBase(o); } ) );
		cl.def_readwrite("attributes", &LHEF::TagBase::attributes);
		cl.def_readwrite("contents", &LHEF::TagBase::contents);
		cl.def("getattr", [](LHEF::TagBase &o, std::string const & a0, double & a1) -> bool { return o.getattr(a0, a1); }, "", pybind11::arg("n"), pybind11::arg("v"));
		cl.def("getattr", (bool (LHEF::TagBase::*)(std::string, double &, bool)) &LHEF::TagBase::getattr, "Find an attribute named  and set the double variable  to\n the corresponding value. Remove the correspondig attribute from\n the list if found and  is true. \n\n false if no\n attribute was found.\n\nC++: LHEF::TagBase::getattr(std::string, double &, bool) --> bool", pybind11::arg("n"), pybind11::arg("v"), pybind11::arg("erase"));
		cl.def("getattr", [](LHEF::TagBase &o, std::string const & a0, bool & a1) -> bool { return o.getattr(a0, a1); }, "", pybind11::arg("n"), pybind11::arg("v"));
		cl.def("getattr", (bool (LHEF::TagBase::*)(std::string, bool &, bool)) &LHEF::TagBase::getattr, "Find an attribute named  and set the bool variable  to\n true if the corresponding value is \"yes\". Remove the correspondig\n attribute from the list if found and  is true. \n\n\n false if no attribute was found.\n\nC++: LHEF::TagBase::getattr(std::string, bool &, bool) --> bool", pybind11::arg("n"), pybind11::arg("v"), pybind11::arg("erase"));
		cl.def("getattr", [](LHEF::TagBase &o, std::string const & a0, long & a1) -> bool { return o.getattr(a0, a1); }, "", pybind11::arg("n"), pybind11::arg("v"));
		cl.def("getattr", (bool (LHEF::TagBase::*)(std::string, long &, bool)) &LHEF::TagBase::getattr, "Find an attribute named  and set the long variable  to\n the corresponding value. Remove the correspondig attribute from\n the list if found and  is true. \n\n false if no\n attribute was found.\n\nC++: LHEF::TagBase::getattr(std::string, long &, bool) --> bool", pybind11::arg("n"), pybind11::arg("v"), pybind11::arg("erase"));
		cl.def("getattr", [](LHEF::TagBase &o, std::string const & a0, int & a1) -> bool { return o.getattr(a0, a1); }, "", pybind11::arg("n"), pybind11::arg("v"));
		cl.def("getattr", (bool (LHEF::TagBase::*)(std::string, int &, bool)) &LHEF::TagBase::getattr, "Find an attribute named  and set the long variable  to\n the corresponding value. Remove the correspondig attribute from\n the list if found and  is true. \n\n false if no\n attribute was found.\n\nC++: LHEF::TagBase::getattr(std::string, int &, bool) --> bool", pybind11::arg("n"), pybind11::arg("v"), pybind11::arg("erase"));
		cl.def("getattr", [](LHEF::TagBase &o, std::string const & a0, std::string & a1) -> bool { return o.getattr(a0, a1); }, "", pybind11::arg("n"), pybind11::arg("v"));
		cl.def("getattr", (bool (LHEF::TagBase::*)(std::string, std::string &, bool)) &LHEF::TagBase::getattr, "Find an attribute named  and set the string variable  to\n the corresponding value. Remove the correspondig attribute from\n the list if found and  is true. \n\n false if no\n attribute was found.\n\nC++: LHEF::TagBase::getattr(std::string, std::string &, bool) --> bool", pybind11::arg("n"), pybind11::arg("v"), pybind11::arg("erase"));
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

<<<<<<< HEAD
		binder::custom_T_binder<LHEF::ProcInfo>(cl);
=======
		binder::custom_T_binder<LHEF::Clus>(cl);
	}
	{ // LHEF::Scale file:HepMC3/LHEF.h line:
		pybind11::class_<LHEF::Scale, std::shared_ptr<LHEF::Scale>, LHEF::TagBase> cl(M("LHEF"), "Scale", "Store special scales from within a scales tag.");
		cl.def( pybind11::init( [](){ return new LHEF::Scale(); } ), "doc" );
		cl.def( pybind11::init( [](std::string const & a0){ return new LHEF::Scale(a0); } ), "doc" , pybind11::arg("st"));
		cl.def( pybind11::init( [](std::string const & a0, int const & a1){ return new LHEF::Scale(a0, a1); } ), "doc" , pybind11::arg("st"), pybind11::arg("emtr"));
		cl.def( pybind11::init<std::string, int, double>(), pybind11::arg("st"), pybind11::arg("emtr"), pybind11::arg("sc") );

		cl.def( pybind11::init<const struct LHEF::XMLTag &>(), pybind11::arg("tag") );

		cl.def( pybind11::init( [](LHEF::Scale const &o){ return new LHEF::Scale(o); } ) );
		cl.def_readwrite("stype", &LHEF::Scale::stype);
		cl.def_readwrite("emitter", &LHEF::Scale::emitter);
		cl.def_readwrite("recoilers", &LHEF::Scale::recoilers);
		cl.def_readwrite("emitted", &LHEF::Scale::emitted);
		cl.def_readwrite("scale", &LHEF::Scale::scale);
		cl.def("assign", (struct LHEF::Scale & (LHEF::Scale::*)(const struct LHEF::Scale &)) &LHEF::Scale::operator=, "C++: LHEF::Scale::operator=(const struct LHEF::Scale &) --> struct LHEF::Scale &", pybind11::return_value_policy::automatic, pybind11::arg(""));

		binder::custom_T_binder<LHEF::Scale>(cl);
	}
	{ // LHEF::Scales file:HepMC3/LHEF.h line:
		pybind11::class_<LHEF::Scales, std::shared_ptr<LHEF::Scales>, LHEF::TagBase> cl(M("LHEF"), "Scales", "Collect different scales relevant for an event.");
		cl.def( pybind11::init( [](){ return new LHEF::Scales(); } ), "doc" );
		cl.def( pybind11::init( [](double const & a0){ return new LHEF::Scales(a0); } ), "doc" , pybind11::arg("defscale"));
		cl.def( pybind11::init<double, int>(), pybind11::arg("defscale"), pybind11::arg("npart") );

		cl.def( pybind11::init( [](const struct LHEF::XMLTag & a0){ return new LHEF::Scales(a0); } ), "doc" , pybind11::arg("tag"));
		cl.def( pybind11::init( [](const struct LHEF::XMLTag & a0, double const & a1){ return new LHEF::Scales(a0, a1); } ), "doc" , pybind11::arg("tag"), pybind11::arg("defscale"));
		cl.def( pybind11::init<const struct LHEF::XMLTag &, double, int>(), pybind11::arg("tag"), pybind11::arg("defscale"), pybind11::arg("npart") );

		cl.def( pybind11::init( [](LHEF::Scales const &o){ return new LHEF::Scales(o); } ) );
		cl.def_readwrite("muf", &LHEF::Scales::muf);
		cl.def_readwrite("mur", &LHEF::Scales::mur);
		cl.def_readwrite("mups", &LHEF::Scales::mups);
		cl.def_readwrite("SCALUP", &LHEF::Scales::SCALUP);
		cl.def_readwrite("scales", &LHEF::Scales::scales);
		cl.def("hasInfo", (bool (LHEF::Scales::*)() const) &LHEF::Scales::hasInfo, "Check if this object contains useful information besides SCALUP.\n\nC++: LHEF::Scales::hasInfo() const --> bool");
		cl.def("getScale", (double (LHEF::Scales::*)(std::string, int, int, int) const) &LHEF::Scales::getScale, "Return the scale of type st for a given emission of particle type\n pdgem from the emitter with number emr and a recoiler rec. (Note\n that the indices for emr and rec starts at 1 and 0 is interpreted\n as any particle.) First it will check for Scale object with an\n exact match. If not found, it will search for an exact match for\n the emitter and recoiler with an undefined emitted particle. If\n not found, it will look for a match for only emitter and emitted,\n of if not found, a match for only the emitter. Finally a general\n Scale object will be used, or if nothing matches, the mups will\n be returned.\n\nC++: LHEF::Scales::getScale(std::string, int, int, int) const --> double", pybind11::arg("st"), pybind11::arg("pdgem"), pybind11::arg("emr"), pybind11::arg("rec"));
		cl.def("assign", (struct LHEF::Scales & (LHEF::Scales::*)(const struct LHEF::Scales &)) &LHEF::Scales::operator=, "C++: LHEF::Scales::operator=(const struct LHEF::Scales &) --> struct LHEF::Scales &", pybind11::return_value_policy::automatic, pybind11::arg(""));

		binder::custom_T_binder<LHEF::Scales>(cl);
	}
	{ // LHEF::PDFInfo file:HepMC3/LHEF.h line:
		pybind11::class_<LHEF::PDFInfo, std::shared_ptr<LHEF::PDFInfo>, LHEF::TagBase> cl(M("LHEF"), "PDFInfo", "The PDFInfo class represents the information in a pdfinto tag.");
		cl.def( pybind11::init( [](){ return new LHEF::PDFInfo(); } ), "doc" );
		cl.def( pybind11::init<double>(), pybind11::arg("defscale") );

		cl.def( pybind11::init( [](const struct LHEF::XMLTag & a0){ return new LHEF::PDFInfo(a0); } ), "doc" , pybind11::arg("tag"));
		cl.def( pybind11::init<const struct LHEF::XMLTag &, double>(), pybind11::arg("tag"), pybind11::arg("defscale") );

		cl.def( pybind11::init( [](LHEF::PDFInfo const &o){ return new LHEF::PDFInfo(o); } ) );
		cl.def_readwrite("p1", &LHEF::PDFInfo::p1);
		cl.def_readwrite("p2", &LHEF::PDFInfo::p2);
		cl.def_readwrite("x1", &LHEF::PDFInfo::x1);
		cl.def_readwrite("x2", &LHEF::PDFInfo::x2);
		cl.def_readwrite("xf1", &LHEF::PDFInfo::xf1);
		cl.def_readwrite("xf2", &LHEF::PDFInfo::xf2);
		cl.def_readwrite("scale", &LHEF::PDFInfo::scale);
		cl.def_readwrite("SCALUP", &LHEF::PDFInfo::SCALUP);
		cl.def("assign", (struct LHEF::PDFInfo & (LHEF::PDFInfo::*)(const struct LHEF::PDFInfo &)) &LHEF::PDFInfo::operator=, "C++: LHEF::PDFInfo::operator=(const struct LHEF::PDFInfo &) --> struct LHEF::PDFInfo &", pybind11::return_value_policy::automatic, pybind11::arg(""));

		binder::custom_T_binder<LHEF::PDFInfo>(cl);
	}
	{ // LHEF::HEPRUP file:HepMC3/LHEF.h line:
		pybind11::class_<LHEF::HEPRUP, std::shared_ptr<LHEF::HEPRUP>, LHEF::TagBase> cl(M("LHEF"), "HEPRUP", "The HEPRUP class is a simple container corresponding to the Les Houches\n accord (<A HREF=\"http://arxiv.org/abs/hep-ph/0109068\">hep-ph/0109068</A>)\n common block with the same name. The members are named in the same\n way as in the common block. However, fortran arrays are represented\n by vectors, except for the arrays of length two which are\n represented by pair objects.");
		cl.def( pybind11::init( [](){ return new LHEF::HEPRUP(); } ) );
		cl.def( pybind11::init( [](LHEF::HEPRUP const &o){ return new LHEF::HEPRUP(o); } ) );
		cl.def( pybind11::init<const struct LHEF::XMLTag &, int>(), pybind11::arg("tagin"), pybind11::arg("versin") );

		cl.def_readwrite("IDBMUP", &LHEF::HEPRUP::IDBMUP);
		cl.def_readwrite("EBMUP", &LHEF::HEPRUP::EBMUP);
		cl.def_readwrite("PDFGUP", &LHEF::HEPRUP::PDFGUP);
		cl.def_readwrite("PDFSUP", &LHEF::HEPRUP::PDFSUP);
		cl.def_readwrite("IDWTUP", &LHEF::HEPRUP::IDWTUP);
		cl.def_readwrite("NPRUP", &LHEF::HEPRUP::NPRUP);
		cl.def_readwrite("XSECUP", &LHEF::HEPRUP::XSECUP);
		cl.def_readwrite("XERRUP", &LHEF::HEPRUP::XERRUP);
		cl.def_readwrite("XMAXUP", &LHEF::HEPRUP::XMAXUP);
		cl.def_readwrite("LPRUP", &LHEF::HEPRUP::LPRUP);
		cl.def_readwrite("xsecinfos", &LHEF::HEPRUP::xsecinfos);
		cl.def_readwrite("eventfiles", &LHEF::HEPRUP::eventfiles);
		cl.def_readwrite("cuts", &LHEF::HEPRUP::cuts);
		cl.def_readwrite("ptypes", &LHEF::HEPRUP::ptypes);
		cl.def_readwrite("procinfo", &LHEF::HEPRUP::procinfo);
		cl.def_readwrite("mergeinfo", &LHEF::HEPRUP::mergeinfo);
		cl.def_readwrite("generators", &LHEF::HEPRUP::generators);
		cl.def_readwrite("weightinfo", &LHEF::HEPRUP::weightinfo);
		cl.def_readwrite("weightmap", &LHEF::HEPRUP::weightmap);
		cl.def_readwrite("weightgroup", &LHEF::HEPRUP::weightgroup);
		cl.def_readwrite("junk", &LHEF::HEPRUP::junk);
		cl.def_readwrite("version", &LHEF::HEPRUP::version);
		cl.def_readwrite("dprec", &LHEF::HEPRUP::dprec);
		cl.def("assign", (class LHEF::HEPRUP & (LHEF::HEPRUP::*)(const class LHEF::HEPRUP &)) &LHEF::HEPRUP::operator=, "Assignment operator.\n\nC++: LHEF::HEPRUP::operator=(const class LHEF::HEPRUP &) --> class LHEF::HEPRUP &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		cl.def("weightNameHepMC", (std::string (LHEF::HEPRUP::*)(int) const) &LHEF::HEPRUP::weightNameHepMC, "Return the name of the weight with given index suitable to ne\n used for HepMC3 output.\n\nC++: LHEF::HEPRUP::weightNameHepMC(int) const --> std::string", pybind11::arg("i"));
		cl.def("clear", (void (LHEF::HEPRUP::*)()) &LHEF::HEPRUP::clear, "Clear all information.\n\nC++: LHEF::HEPRUP::clear() --> void");
		cl.def("resize", (void (LHEF::HEPRUP::*)(int)) &LHEF::HEPRUP::resize, "Set the NPRUP variable, corresponding to the number of\n sub-processes, to  and resize all relevant vectors\n accordingly.\n\nC++: LHEF::HEPRUP::resize(int) --> void", pybind11::arg("nrup"));
		cl.def("resize", (void (LHEF::HEPRUP::*)()) &LHEF::HEPRUP::resize, "Assuming the NPRUP variable, corresponding to the number of\n sub-processes, is correctly set, resize the relevant vectors\n accordingly.\n\nC++: LHEF::HEPRUP::resize() --> void");
		cl.def("weightIndex", (int (LHEF::HEPRUP::*)(const std::string &) const) &LHEF::HEPRUP::weightIndex, "the index of the weight with the given \n   \n\nC++: LHEF::HEPRUP::weightIndex(const std::string &) const --> int", pybind11::arg("name"));
		cl.def("nWeights", (int (LHEF::HEPRUP::*)() const) &LHEF::HEPRUP::nWeights, "the number of weights (including the nominial one).\n\nC++: LHEF::HEPRUP::nWeights() const --> int");
		cl.def("getXSecInfo", [](LHEF::HEPRUP &o) -> LHEF::XSecInfo & { return o.getXSecInfo(); }, "", pybind11::return_value_policy::automatic);
		cl.def("getXSecInfo", (struct LHEF::XSecInfo & (LHEF::HEPRUP::*)(std::string)) &LHEF::HEPRUP::getXSecInfo, "the XSecInfo object corresponding to the named weight \n If no such object exists, it will be created.\n\nC++: LHEF::HEPRUP::getXSecInfo(std::string) --> struct LHEF::XSecInfo &", pybind11::return_value_policy::automatic, pybind11::arg("weightname"));

		binder::custom_T_binder<LHEF::HEPRUP>(cl);
	}
	{ // LHEF::EventGroup file:HepMC3/LHEF.h line:
		pybind11::class_<LHEF::EventGroup, std::shared_ptr<LHEF::EventGroup>, std::vector<LHEF::HEPEUP *>> cl(M("LHEF"), "EventGroup", "The EventGroup represents a set of events which are to be\n considered together.");
		cl.def( pybind11::init( [](){ return new LHEF::EventGroup(); } ) );
		cl.def( pybind11::init( [](LHEF::EventGroup const &o){ return new LHEF::EventGroup(o); } ) );
		cl.def_readwrite("nreal", &LHEF::EventGroup::nreal);
		cl.def_readwrite("ncounter", &LHEF::EventGroup::ncounter);
		cl.def("assign", (struct LHEF::EventGroup & (LHEF::EventGroup::*)(const struct LHEF::EventGroup &)) &LHEF::EventGroup::operator=, "The assignment also copies the included HEPEUP object.\n\nC++: LHEF::EventGroup::operator=(const struct LHEF::EventGroup &) --> struct LHEF::EventGroup &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		cl.def("clear", (void (LHEF::EventGroup::*)()) &LHEF::EventGroup::clear, "Remove all subevents.\n\nC++: LHEF::EventGroup::clear() --> void");
	}
	{ // LHEF::HEPEUP file:HepMC3/LHEF.h line:
		pybind11::class_<LHEF::HEPEUP, std::shared_ptr<LHEF::HEPEUP>, LHEF::TagBase> cl(M("LHEF"), "HEPEUP", "The HEPEUP class is a simple container corresponding to the Les Houches accord\n (<A HREF=\"http://arxiv.org/abs/hep-ph/0109068\">hep-ph/0109068</A>)\n common block with the same name. The members are named in the same\n way as in the common block. However, fortran arrays are represented\n by vectors, except for the arrays of length two which are\n represented by pair objects.");
		cl.def( pybind11::init( [](){ return new LHEF::HEPEUP(); } ) );
		cl.def( pybind11::init( [](LHEF::HEPEUP const &o){ return new LHEF::HEPEUP(o); } ) );
		cl.def( pybind11::init<const struct LHEF::XMLTag &, class LHEF::HEPRUP &>(), pybind11::arg("tagin"), pybind11::arg("heprupin") );

		cl.def_readwrite("NUP", &LHEF::HEPEUP::NUP);
		cl.def_readwrite("IDPRUP", &LHEF::HEPEUP::IDPRUP);
		cl.def_readwrite("XWGTUP", &LHEF::HEPEUP::XWGTUP);
		cl.def_readwrite("XPDWUP", &LHEF::HEPEUP::XPDWUP);
		cl.def_readwrite("SCALUP", &LHEF::HEPEUP::SCALUP);
		cl.def_readwrite("AQEDUP", &LHEF::HEPEUP::AQEDUP);
		cl.def_readwrite("AQCDUP", &LHEF::HEPEUP::AQCDUP);
		cl.def_readwrite("IDUP", &LHEF::HEPEUP::IDUP);
		cl.def_readwrite("ISTUP", &LHEF::HEPEUP::ISTUP);
		cl.def_readwrite("MOTHUP", &LHEF::HEPEUP::MOTHUP);
		cl.def_readwrite("ICOLUP", &LHEF::HEPEUP::ICOLUP);
		cl.def_readwrite("PUP", &LHEF::HEPEUP::PUP);
		cl.def_readwrite("VTIMUP", &LHEF::HEPEUP::VTIMUP);
		cl.def_readwrite("SPINUP", &LHEF::HEPEUP::SPINUP);
		cl.def_readwrite("namedweights", &LHEF::HEPEUP::namedweights);
		cl.def_readwrite("weights", &LHEF::HEPEUP::weights);
		cl.def_readwrite("clustering", &LHEF::HEPEUP::clustering);
		cl.def_readwrite("pdfinfo", &LHEF::HEPEUP::pdfinfo);
		cl.def_readwrite("PDFGUPsave", &LHEF::HEPEUP::PDFGUPsave);
		cl.def_readwrite("PDFSUPsave", &LHEF::HEPEUP::PDFSUPsave);
		cl.def_readwrite("scales", &LHEF::HEPEUP::scales);
		cl.def_readwrite("ntries", &LHEF::HEPEUP::ntries);
		cl.def_readwrite("isGroup", &LHEF::HEPEUP::isGroup);
		cl.def_readwrite("subevents", &LHEF::HEPEUP::subevents);
		cl.def_readwrite("junk", &LHEF::HEPEUP::junk);
		cl.def("setEvent", (class LHEF::HEPEUP & (LHEF::HEPEUP::*)(const class LHEF::HEPEUP &)) &LHEF::HEPEUP::setEvent, "Copy information from the given HEPEUP. Sub event information is\n left untouched.\n\nC++: LHEF::HEPEUP::setEvent(const class LHEF::HEPEUP &) --> class LHEF::HEPEUP &", pybind11::return_value_policy::automatic, pybind11::arg("x"));
		cl.def("assign", (class LHEF::HEPEUP & (LHEF::HEPEUP::*)(const class LHEF::HEPEUP &)) &LHEF::HEPEUP::operator=, "Assignment operator.\n\nC++: LHEF::HEPEUP::operator=(const class LHEF::HEPEUP &) --> class LHEF::HEPEUP &", pybind11::return_value_policy::automatic, pybind11::arg("x"));
		cl.def("reset", (void (LHEF::HEPEUP::*)()) &LHEF::HEPEUP::reset, "Reset the HEPEUP object (does not touch the sub events).\n\nC++: LHEF::HEPEUP::reset() --> void");
		cl.def("clear", (void (LHEF::HEPEUP::*)()) &LHEF::HEPEUP::clear, "Clear the HEPEUP object.\n\nC++: LHEF::HEPEUP::clear() --> void");
		cl.def("resize", (void (LHEF::HEPEUP::*)(int)) &LHEF::HEPEUP::resize, "Set the NUP variable, corresponding to the number of particles in\n the current event, to  and resize all relevant vectors\n accordingly.\n\nC++: LHEF::HEPEUP::resize(int) --> void", pybind11::arg("nup"));
		cl.def("totalWeight", [](LHEF::HEPEUP const &o) -> double { return o.totalWeight(); }, "");
		cl.def("totalWeight", (double (LHEF::HEPEUP::*)(int) const) &LHEF::HEPEUP::totalWeight, "Return the total weight for this event (including all sub\n evenets) for the given index.\n\nC++: LHEF::HEPEUP::totalWeight(int) const --> double", pybind11::arg("i"));
		cl.def("totalWeight", (double (LHEF::HEPEUP::*)(const std::string &) const) &LHEF::HEPEUP::totalWeight, "Return the total weight for this event (including all sub\n evenets) for the given weight name.\n\nC++: LHEF::HEPEUP::totalWeight(const std::string &) const --> double", pybind11::arg("name"));
		cl.def("weight", [](LHEF::HEPEUP const &o) -> double { return o.weight(); }, "");
		cl.def("weight", (double (LHEF::HEPEUP::*)(int) const) &LHEF::HEPEUP::weight, "Return the weight for the given index.\n\nC++: LHEF::HEPEUP::weight(int) const --> double", pybind11::arg("i"));
		cl.def("weight", (double (LHEF::HEPEUP::*)(const std::string &) const) &LHEF::HEPEUP::weight, "Return the weight for the given weight name.\n\nC++: LHEF::HEPEUP::weight(const std::string &) const --> double", pybind11::arg("name"));
		cl.def("setWeight", (void (LHEF::HEPEUP::*)(int, double)) &LHEF::HEPEUP::setWeight, "Set the weight with the given index.\n\nC++: LHEF::HEPEUP::setWeight(int, double) --> void", pybind11::arg("i"), pybind11::arg("w"));
		cl.def("setWeight", (bool (LHEF::HEPEUP::*)(const std::string &, double)) &LHEF::HEPEUP::setWeight, "Set the weight with the given name.\n\nC++: LHEF::HEPEUP::setWeight(const std::string &, double) --> bool", pybind11::arg("name"), pybind11::arg("w"));
		cl.def("resize", (void (LHEF::HEPEUP::*)()) &LHEF::HEPEUP::resize, "Assuming the NUP variable, corresponding to the number of\n particles in the current event, is correctly set, resize the\n relevant vectors accordingly.\n\nC++: LHEF::HEPEUP::resize() --> void");
		cl.def("setWeightInfo", (bool (LHEF::HEPEUP::*)(unsigned int)) &LHEF::HEPEUP::setWeightInfo, "Setup the current event to use weight i. If zero, the default\n weight will be used.\n\nC++: LHEF::HEPEUP::setWeightInfo(unsigned int) --> bool", pybind11::arg("i"));
		cl.def("setSubEvent", (bool (LHEF::HEPEUP::*)(unsigned int)) &LHEF::HEPEUP::setSubEvent, "Setup the current event to use sub event i. If zero, no sub event\n will be chsen.\n\nC++: LHEF::HEPEUP::setSubEvent(unsigned int) --> bool", pybind11::arg("i"));

		binder::custom_T_binder<LHEF::HEPEUP>(cl);
>>>>>>> origin/master
	}
}
