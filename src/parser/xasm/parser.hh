#ifndef XASM_PARSER_XASM_PARSER_HH
#define XASM_PARSER_XASM_PARSER_HH

#include "../base.hh"

#include <string>

namespace xasm {
namespace parser {
namespace xasm {

class parser : public base {
public:
	virtual void parse(iterator_type &start, const iterator_type &end, ast::source &ast) override;
};

} // namespace xasm
} // namespace parser
} // namespace xasm

#endif
