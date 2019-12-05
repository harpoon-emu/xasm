#ifndef XASM_PARSER_XASM_RULES_INSTRUCTION_NULLARY_HH
#define XASM_PARSER_XASM_RULES_INSTRUCTION_NULLARY_HH

#include "../../../ast/instruction.hh"

#include <boost/spirit/home/x3.hpp>

namespace xasm {
namespace parser {
namespace xasm {
namespace rules {
namespace instruction {

namespace x3 = boost::spirit::x3;

using nullary_type = x3::rule<class nullary, ast::instruction::nullary>;
static nullary_type const nullary = "nullary";
BOOST_SPIRIT_DECLARE(nullary_type);

} // namespace instruction
} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm

#endif
