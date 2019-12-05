#include "implied.hh"

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
namespace implied {

namespace x3 = boost::spirit::x3;

static struct mos6502_mnemonic_ : public x3::symbols<ast::instruction::opcode_t> {
	mos6502_mnemonic_() {
		add("DEX", 0xCA)("DEY", 0x88)("INX", 0xE8)("INY", 0xC8)("TAX", 0xAA)("TXA", 0x8A)(
		    "TAY", 0xA8)("TYA", 0x98)("TSX", 0xBA)("TXS", 0x9A)("PLA", 0x68)("PHA", 0x48)(
		    "PLP", 0x28)("PHP", 0x08)("BRK", 0x00)("RTI", 0x40)("RTS", 0x60)("CLC", 0x18)(
		    "SEC", 0x38)("CLD", 0xD8)("SED", 0xF8)("CLI", 0x58)("SEI", 0x78)("CLV", 0xB8)("NOP",
		                                                                                  0xEA);
	}
} mos6502_mnemonic;

static x3::rule<class mnemonic, ast::instruction::opcode_t> const mnemonic = "mnemonic";
static auto const mnemonic_def = x3::no_case[mos6502_mnemonic];
BOOST_SPIRIT_DEFINE(mnemonic);

static auto const statement_def = x3::attr(ast::instruction::implied) >> mnemonic;
BOOST_SPIRIT_DEFINE(statement);
BOOST_SPIRIT_INSTANTIATE(statement_type, config::iterator_type, config::context_type);

} // namespace implied
} // namespace instruction
} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm
