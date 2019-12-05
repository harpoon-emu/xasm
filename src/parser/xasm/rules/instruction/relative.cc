#include "relative.hh"

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
namespace relative {

namespace x3 = boost::spirit::x3;

static struct mos6502_mnemonic_ : public x3::symbols<ast::instruction::opcode_t> {
	mos6502_mnemonic_() {
		add("BPL", 0x10)("BMI", 0x30)("BVC", 0x50)("BVS", 0x70)("BCC", 0x90)("BCS", 0xB0)(
		    "BNE", 0xD0)("BEQ", 0xF0);
	}
} mos6502_mnemonic;

static x3::rule<class mnemonic, ast::instruction::opcode_t> const mnemonic = "mnemonic";
static auto const mnemonic_def = x3::no_case[mos6502_mnemonic];
BOOST_SPIRIT_DEFINE(mnemonic);

static x3::rule<class argument, std::uint8_t> const argument = "argument";
static auto const argument_def = byte >> &x3::space;
BOOST_SPIRIT_DEFINE(argument);

static auto const statement_def
    = x3::attr(ast::instruction::relative) >> mnemonic >> token_sep >> argument;
BOOST_SPIRIT_DEFINE(statement);
BOOST_SPIRIT_INSTANTIATE(statement_type, config::iterator_type, config::context_type);

} // namespace relative
} // namespace instruction
} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm
