#include "accumulator.hh"

#include "../../ast_adapted/instruction.hh"
#include "../../config.hh"
#include "../token.hh"
#include "operand.hh"

#include <boost/spirit/home/x3.hpp>
#include <iostream>

namespace xasm {
namespace parser {
namespace xasm {
namespace rules {
namespace instruction {
namespace accumulator {

namespace x3 = boost::spirit::x3;

static struct mos6502_mnemonic_ : public x3::symbols<ast::instruction::opcode_t> {
	mos6502_mnemonic_() {
		add("ASL", 0x0A)("LSR", 0x4A)("ROL", 0x2A)("ROR", 0x6A);
	}
} mos6502_mnemonic;

static x3::rule<class mnemonic, ast::instruction::opcode_t> const mnemonic = "mnemonic";
static auto const mnemonic_def = x3::no_case[mos6502_mnemonic];
BOOST_SPIRIT_DEFINE(mnemonic);

static x3::rule<class argument> const argument = "argument";
static auto const argument_def = x3::no_case[x3::lit("A")] >> &x3::space;
BOOST_SPIRIT_DEFINE(argument);

static auto const statement_def
    = x3::attr(ast::instruction::accumulator) >> mnemonic >> token_sep >> argument;
BOOST_SPIRIT_DEFINE(statement);
BOOST_SPIRIT_INSTANTIATE(statement_type, config::iterator_type, config::context_type);

} // namespace accumulator
} // namespace instruction
} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm
