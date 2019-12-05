#ifndef XASM_PARSER_XASM_RULES_INSTRUCTION_INDIRECT_HH
#define XASM_PARSER_XASM_RULES_INSTRUCTION_INDIRECT_HH

#include "../../../ast/instruction.hh"

#include <boost/spirit/home/x3.hpp>

namespace xasm {
namespace parser {
namespace xasm {
namespace rules {
namespace instruction {
namespace indirect {

namespace x3 = boost::spirit::x3;

using statement_type = x3::rule<class statement, ast::instruction::unary_word>;
static statement_type const statement = "statement";
BOOST_SPIRIT_DECLARE(statement_type);

} // namespace indirect
} // namespace instruction
} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm

#endif
