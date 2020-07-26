#include "ast/ast.hh"
#include "emitter/bin/emitter.hh"
#include "parser/parser.hh"

#include <boost/program_options.hpp>
#include <iostream>
#include <string>

static void parse_command_line(boost::program_options::variables_map &vm, int argc, char **argv) {
	boost::program_options::options_description desc("Allowed options");
	boost::program_options::positional_options_description p_desc;

	p_desc.add("input-file", 1);

	desc.add_options()("help,h", "produce help message");
	desc.add_options()("input,f", boost::program_options::value<std::string>(), "input file");
	desc.add_options()("output,o",
	                   boost::program_options::value<std::string>()->default_value("a.out"),
	                   "output file");

	boost::program_options::store(boost::program_options::command_line_parser(argc, argv)
	                                  .options(desc)
	                                  .positional(p_desc)
	                                  .run(),
	                              vm);
	boost::program_options::notify(vm);

	if (vm.count("help")) {
		std::cout << desc << std::endl;
		exit(0);
	}
}

int main(int argc, char **argv) {
	try {
		boost::program_options::variables_map vm;
		parse_command_line(vm, argc, argv);

		xasm::ast::source ast;
		xasm::parser::parser parser(vm["input"].as<std::string>());
		xasm::emitter::bin::emitter emitter(vm["output"].as<std::string>());

		parser.parse(ast);
		emitter.emit(ast);
	} catch (std::exception &e) {
		std::cerr << "error: " << e.what() << std::endl;
	} catch (...) {
		std::cerr << "unknown exception" << std::endl;
	}
}
