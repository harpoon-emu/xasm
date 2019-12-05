#ifndef XASM_PARSER_XASM_RULES_INSTRUCTION_INSTRUCTION_HH
#define XASM_PARSER_XASM_RULES_INSTRUCTION_INSTRUCTION_HH

#include <boost/spirit/home/x3.hpp>

namespace xasm {
namespace parser {
namespace xasm {
namespace rules {
namespace instruction {

namespace x3 = boost::spirit::x3;

using byte_type = x3::rule<class byte, std::uint8_t>;
static byte_type const byte = "byte";
BOOST_SPIRIT_DECLARE(byte_type);

using word_type = x3::rule<class word, std::uint16_t>;
static word_type const word = "word";
BOOST_SPIRIT_DECLARE(word_type);

} // namespace instruction
} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm

#endif
