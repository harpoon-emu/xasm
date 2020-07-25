#include "parser.hh"

#include "../ast/ast.hh"
#include "xasm/parser.hh"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

namespace xasm {
namespace parser {

parser::parser(const std::string &file_name) : _file_name{file_name} {}

class print_visitor : public boost::static_visitor<> {
public:
	void operator()(const ast::instruction::nullary &x) const {
		std::cout << std::hex << x.address_mode << ": " << std::hex << std::setfill('0')
		          << std::setw(2) << x.opcode << std::endl;
	}

	template<typename T>
	void operator()(const ast::instruction::unary<T> &x) const {
		std::cout << std::hex << x.address_mode << ": " << std::hex << std::setfill('0')
		          << std::setw(2) << x.opcode << " " << std::hex << std::setfill('0')
		          << std::setw(sizeof(T) * 2) << static_cast<std::uint16_t>(x.operand) << std::endl;
	}
};

void parser::parse() {
	std::ifstream f(_file_name);
	std::string src((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
	xasm::parser parser;

	base::iterator_type s = src.cbegin();
	parser.parse(s, src.cend(), _ast);

	std::cout << *s << std::endl;

	for (auto i : _ast) {
		std::cout << "CODE BLOCK" << std::endl;
		for (auto j : i) {
			boost::apply_visitor(print_visitor(), j);
		}
	}
}

} // namespace parser
} // namespace xasm
