#include "absolute_x.hh"

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
namespace absolute_x {

namespace x3 = boost::spirit::x3;

static struct mos6502_mnemonic_ : public x3::symbols<ast::instruction::opcode_t> {
	mos6502_mnemonic_() {
		add("ADC", 0x7D)("AND", 0x3D)("ASL", 0x1E)("CMP", 0xDD)("DEC", 0xDE)("EOR", 0x5D)(
		    "INC", 0xFE)("LDA", 0xBD)("LDY", 0xBC)("LSR", 0x5E)("ORA", 0x1D)("ROL", 0x3E)(
		    "ROR", 0x7E)("SBC", 0xFD)("STA", 0x9D);
	}
} mos6502_mnemonic;

static x3::rule<class mnemonic, ast::instruction::opcode_t> const mnemonic = "mnemonic";
static auto const mnemonic_def = x3::no_case[mos6502_mnemonic];
BOOST_SPIRIT_DEFINE(mnemonic);

static x3::rule<class argument, std::uint16_t> const argument = "argument";
static auto const argument_def = word >> x3::lit(",X") >> &x3::space;
BOOST_SPIRIT_DEFINE(argument);

static auto const statement_def
    = x3::attr(ast::instruction::absolute_x) >> mnemonic >> token_sep >> argument;
BOOST_SPIRIT_DEFINE(statement);
BOOST_SPIRIT_INSTANTIATE(statement_type, config::iterator_type, config::context_type);

} // namespace absolute_x
} // namespace instruction
} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm
