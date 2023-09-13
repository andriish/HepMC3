#include <map>
#include <algorithm>
#include <functional>
#include <memory>
#include <stdexcept>
#include <string>

#include <pybind11/pybind11.h>

typedef std::function< pybind11::module & (std::string const &) > ModuleGetter;

void bind_pyHepMC3_0(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_1(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_2(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_3(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_4(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_5(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_6(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_7(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_8(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_9(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_10(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_11(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_12(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_13(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_14(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_15(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_16(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_17(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_18(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_19(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_20(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_21(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_22(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_23(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_24(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_25(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_26(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_27(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_28(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_29(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_30(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_31(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_32(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_33(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_34(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_pyHepMC3_35(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(pyHepMC3, root_module) {
	root_module.doc() = "pyHepMC3 module";

	std::map <std::string, pybind11::module> modules;
	ModuleGetter M = [&](std::string const &namespace_) -> pybind11::module & {
		auto it = modules.find(namespace_);
		if( it == modules.end() ) throw std::runtime_error("Attempt to access pybind11::module for namespace " + namespace_ + " before it was created!!!");
		return it->second;
	};

	modules[""] = root_module;

	static std::vector<std::string> const reserved_python_words {"nonlocal", "global", };

	auto mangle_namespace_name(
		[](std::string const &ns) -> std::string {
			if ( std::find(reserved_python_words.begin(), reserved_python_words.end(), ns) == reserved_python_words.end() ) return ns;
			else return ns+'_';
		}
	);

	std::vector< std::pair<std::string, std::string> > sub_modules {
		{"", "HepMC3"},
		{"", "LHEF"},
		{"", "std"},
	};
	for(auto &p : sub_modules ) modules[p.first.size() ? p.first+"::"+p.second : p.second] = modules[p.first].def_submodule( mangle_namespace_name(p.second).c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind_pyHepMC3_0(M);
	bind_pyHepMC3_1(M);
	bind_pyHepMC3_2(M);
	bind_pyHepMC3_3(M);
	bind_pyHepMC3_4(M);
	bind_pyHepMC3_5(M);
	bind_pyHepMC3_6(M);
	bind_pyHepMC3_7(M);
	bind_pyHepMC3_8(M);
	bind_pyHepMC3_9(M);
	bind_pyHepMC3_10(M);
	bind_pyHepMC3_11(M);
	bind_pyHepMC3_12(M);
	bind_pyHepMC3_13(M);
	bind_pyHepMC3_14(M);
	bind_pyHepMC3_15(M);
	bind_pyHepMC3_16(M);
	bind_pyHepMC3_17(M);
	bind_pyHepMC3_18(M);
	bind_pyHepMC3_19(M);
	bind_pyHepMC3_20(M);
	bind_pyHepMC3_21(M);
	bind_pyHepMC3_22(M);
	bind_pyHepMC3_23(M);
	bind_pyHepMC3_24(M);
	bind_pyHepMC3_25(M);
	bind_pyHepMC3_26(M);
	bind_pyHepMC3_27(M);
	bind_pyHepMC3_28(M);
	bind_pyHepMC3_29(M);
	bind_pyHepMC3_30(M);
	bind_pyHepMC3_31(M);
	bind_pyHepMC3_32(M);
	bind_pyHepMC3_33(M);
	bind_pyHepMC3_34(M);
	bind_pyHepMC3_35(M);

}
