#ifndef XASM_PARSER_PARSER_HH
#define XASM_PARSER_PARSER_HH

#include "../ast/source.hh"

#include <string>

namespace xasm {
namespace parser {

class parser {
public:
	parser(const std::string &file_name);

	void parse(ast::source &ast);

private:
	std::string _file_name{};
};

} // namespace parser
} // namespace xasm

#endif
