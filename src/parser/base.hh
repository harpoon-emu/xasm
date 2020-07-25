#ifndef XASM_PARSER_BASE_HH
#define XASM_PARSER_BASE_HH

#include "../ast/source.hh"

#include <string>

namespace xasm {
namespace parser {

class base {
public:
	using iterator_type = std::string::const_iterator;

	virtual void parse(iterator_type &start, const iterator_type &end, ast::source &ast) = 0;
};

} // namespace parser
} // namespace xasm

#endif
