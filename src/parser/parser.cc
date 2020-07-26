#include "parser.hh"

#include "../ast/ast.hh"
#include "xasm/parser.hh"

#include <fstream>

namespace xasm {
namespace parser {

parser::parser(const std::string &file_name) : _file_name{file_name} {}

void parser::parse(ast::source &ast) {
	std::ifstream f(_file_name);
	std::string src((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
	xasm::parser parser;

	base::iterator_type s = src.cbegin();
	parser.parse(s, src.cend(), ast);
}

} // namespace parser
} // namespace xasm
