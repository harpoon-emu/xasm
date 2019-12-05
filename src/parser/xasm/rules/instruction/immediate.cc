#include "immediate.hh"

#include "../../ast_adapted/instruction.hh"
#include "../../config.hh"
#include "../token.hh"
#include "operand.hh"

#include <boost/spirit/home/x3.hpp>

namespace xasm {
namespace parser {
namespace xasm {
namespace rules {
namespace instruction {
namespace immediate {

namespace x3 = boost::spirit::x3;

static struct mos6502_mnemonic_ : public x3::symbols<ast::instruction::opcode_t> {
	mos6502_mnemonic_() {
		add("ORA", 0x09)("AND", 0x29)("EOR", 0x49)("ADC", 0x69)("SBC", 0xE9)("CMP", 0xC9)(
		    "CPX", 0xE0)("CPY", 0xC0)("LDA", 0xA9)("LDX", 0xA2)("LDY", 0xA0)("ORA", 0x09);
	}
} mos6502_mnemonic;

static x3::rule<class mnemonic, ast::instruction::opcode_t> const mnemonic = "mnemonic";
static auto const mnemonic_def = x3::no_case[mos6502_mnemonic];
BOOST_SPIRIT_DEFINE(mnemonic);

static x3::rule<class argument, std::uint8_t> const argument = "argument";
static auto const argument_def = x3::char_('#') >> byte >> &x3::space;
BOOST_SPIRIT_DEFINE(argument);

static auto const statement_def
    = x3::attr(ast::instruction::immediate) >> mnemonic >> token_sep >> argument;
BOOST_SPIRIT_DEFINE(statement);
BOOST_SPIRIT_INSTANTIATE(statement_type, config::iterator_type, config::context_type);

} // namespace immediate
} // namespace instruction
} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm
