#ifndef XASM_AST_INSTRUCTION_HH
#define XASM_AST_INSTRUCTION_HH

#include <boost/fusion/include/io.hpp>
#include <boost/variant.hpp>
#include <cstdint>

namespace xasm {
namespace ast {
namespace instruction {

using opcode_t = std::uint16_t;

enum address_mode_t {
	accumulator,
	absolute,
	absolute_x,
	absolute_y,
	immediate,
	implied,
	indirect,
	x_indirect,
	indirect_y,
	relative,
	zeropage,
	zeropage_x,
	zeropage_y
};

struct base {
	address_mode_t address_mode;
	opcode_t opcode;
};

struct nullary : public base {};

template<typename OPERAND_TYPE>
struct unary : public base {
	OPERAND_TYPE operand;
};

struct unary_byte : public unary<std::uint8_t> {};
struct unary_word : public unary<std::uint16_t> {};

using variant = boost::variant<nullary, unary_byte, unary_word>;

using boost::fusion::operator<<;

} // namespace instruction
} // namespace ast
} // namespace xasm

#endif
