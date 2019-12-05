#ifndef XASM_PARSER_XASM_RULES_INSTRUCTION_INSTRUCTION_HH
#define XASM_PARSER_XASM_RULES_INSTRUCTION_INSTRUCTION_HH

#include "../../../ast/instruction.hh"

#include <boost/spirit/home/x3.hpp>

namespace xasm {
namespace parser {
namespace xasm {
namespace rules {
namespace instruction {

namespace x3 = boost::spirit::x3;

using instruction_type = x3::rule<class instruction, ast::instruction::variant>;
static instruction_type const instruction = "instruction";
BOOST_SPIRIT_DECLARE(instruction_type);

} // namespace instruction
} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm

#endif
