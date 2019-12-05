#include "zeropage_x.hh"

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
namespace zeropage_x {

namespace x3 = boost::spirit::x3;

static struct mos6502_mnemonic_ : public x3::symbols<ast::instruction::opcode_t> {
	mos6502_mnemonic_() {
		add("ORA", 0x15)("AND", 0x35)("EOR", 0x55)("ADC", 0x75)("SBC", 0xF5)("CMP", 0xD5)(
		    "DEC", 0xD6)("INC", 0xF6)("ASL", 0x16)("ROL", 0x36)("LSR", 0x56)("ROR", 0x76)(
		    "LDA", 0xB5)("STA", 0x95)("LDY", 0xB4)("STY", 0x94);
	}
} mos6502_mnemonic;

static x3::rule<class mnemonic, ast::instruction::opcode_t> const mnemonic = "mnemonic";
static auto const mnemonic_def = x3::no_case[mos6502_mnemonic];
BOOST_SPIRIT_DEFINE(mnemonic);

static x3::rule<class argument, std::uint8_t> const argument = "argument";
static auto const argument_def = byte >> x3::no_case[x3::lit(",X")] >> &x3::space;
BOOST_SPIRIT_DEFINE(argument);

static auto const statement_def
    = x3::attr(ast::instruction::zeropage_x) >> mnemonic >> token_sep >> argument;
BOOST_SPIRIT_DEFINE(statement);
BOOST_SPIRIT_INSTANTIATE(statement_type, config::iterator_type, config::context_type);

} // namespace zeropage_x
} // namespace instruction
} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm
