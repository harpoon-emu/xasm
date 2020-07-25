#ifndef XASM_PARSER_XASM_RULES_INSTRUCTION_UNARY_HH
#define XASM_PARSER_XASM_RULES_INSTRUCTION_UNARY_HH

#include "../../../../ast/instruction.hh"

#include <boost/spirit/home/x3.hpp>

namespace xasm {
namespace parser {
namespace xasm {
namespace rules {
namespace instruction {

namespace x3 = boost::spirit::x3;

using unary_byte_type = x3::rule<class unary_byte, ast::instruction::unary_byte>;
static unary_byte_type const unary_byte = "unary_byte";
BOOST_SPIRIT_DECLARE(unary_byte_type);

using unary_word_type = x3::rule<class unary_word, ast::instruction::unary_word>;
static unary_word_type const unary_word = "unary_word";
BOOST_SPIRIT_DECLARE(unary_word_type);

} // namespace instruction
} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm

#endif
