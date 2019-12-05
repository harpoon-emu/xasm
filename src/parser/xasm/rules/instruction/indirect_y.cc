#include "indirect_y.hh"

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
namespace indirect_y {

namespace x3 = boost::spirit::x3;

static struct mos6502_mnemonic_ : public x3::symbols<ast::instruction::opcode_t> {
	mos6502_mnemonic_() {
		add("ORA", 0x11)("AND", 0x31)("EOR", 0x51)("ADC", 0x71)("SBC", 0xF1)("CMP", 0xD1)(
		    "LDA", 0xB1)("STA", 0x91);
	}
} mos6502_mnemonic;

static x3::rule<class mnemonic, ast::instruction::opcode_t> const mnemonic = "mnemonic";
static auto const mnemonic_def = x3::no_case[mos6502_mnemonic];
BOOST_SPIRIT_DEFINE(mnemonic);

static x3::rule<class argument, std::uint8_t> const argument = "argument";
static auto const argument_def = x3::lit("(") >> byte >> x3::no_case[x3::lit("),Y")] >> &x3::space;
BOOST_SPIRIT_DEFINE(argument);

static auto const statement_def
    = x3::attr(ast::instruction::indirect_y) >> mnemonic >> token_sep >> argument;
BOOST_SPIRIT_DEFINE(statement);
BOOST_SPIRIT_INSTANTIATE(statement_type, config::iterator_type, config::context_type);

} // namespace indirect_y
} // namespace instruction
} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm
