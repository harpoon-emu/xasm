#include "absolute.hh"

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
namespace absolute {

namespace x3 = boost::spirit::x3;

static struct mos6502_mnemonic_ : public x3::symbols<ast::instruction::opcode_t> {
	mos6502_mnemonic_() {
		add("ADC", 0x6D)("AND", 0x2D)("ASL", 0x0E)("BIT", 0x2C)("CMP", 0xCD)("CPX", 0xEC)(
		    "CPY", 0xCC)("DEC", 0xCE)("EOR", 0x4D)("INC", 0xEE)("JMP", 0x4C)("JSR", 0x20)(
		    "LDA", 0xAD)("LDX", 0xAE)("LDY", 0xAC)("LSR", 0x4E)("ORA", 0x0D)("ROL", 0x2E)(
		    "ROR", 0x6E)("SBC", 0xED)("STA", 0x8D)("STX", 0x8E)("STY", 0x8C);
	}
} mos6502_mnemonic;


static x3::rule<class mnemonic, ast::instruction::opcode_t> const mnemonic = "mnemonic";
static auto const mnemonic_def = x3::no_case[mos6502_mnemonic];
BOOST_SPIRIT_DEFINE(mnemonic);

static x3::rule<class argument, std::uint16_t> const argument = "argument";
static auto const argument_def = word >> &x3::space;
BOOST_SPIRIT_DEFINE(argument);

static auto const statement_def
    = x3::attr(ast::instruction::absolute) >> mnemonic >> token_sep >> argument;
BOOST_SPIRIT_DEFINE(statement);
BOOST_SPIRIT_INSTANTIATE(statement_type, config::iterator_type, config::context_type);

} // namespace absolute
} // namespace instruction
} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm
