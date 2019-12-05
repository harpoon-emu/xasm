#include "zeropage.hh"

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
namespace zeropage {

namespace x3 = boost::spirit::x3;

static struct mos6502_mnemonic_ : public x3::symbols<ast::instruction::opcode_t> {
	mos6502_mnemonic_() {
		add("ORA", 0x05)("AND", 0x25)("EOR", 0x45)("ADC", 0x65)("SBC", 0xE5)("CMP", 0xC5)(
		    "CPX", 0xE4)("CPY", 0xC4)("DEC", 0xC6)("INC", 0xE6)("ASL", 0x06)("ROL", 0x26)(
		    "LSR", 0x46)("ROR", 0x66)("LDA", 0xA5)("STA", 0x85)("LDX", 0xA6)("STX", 0x86)(
		    "LDY", 0xA4)("STY", 0x84)("BIT", 0x24);
	}
} mos6502_mnemonic;

static x3::rule<class mnemonic, ast::instruction::opcode_t> const mnemonic = "mnemonic";
static auto const mnemonic_def = x3::no_case[mos6502_mnemonic];
BOOST_SPIRIT_DEFINE(mnemonic);

static x3::rule<class argument, std::uint8_t> const argument = "argument";
static auto const argument_def = byte >> x3::no_case[x3::lit(",X")] >> &x3::space;
BOOST_SPIRIT_DEFINE(argument);

static auto const statement_def
    = x3::attr(ast::instruction::zeropage) >> mnemonic >> token_sep >> argument;
BOOST_SPIRIT_DEFINE(statement);
BOOST_SPIRIT_INSTANTIATE(statement_type, config::iterator_type, config::context_type);

} // namespace zeropage
} // namespace instruction
} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm
