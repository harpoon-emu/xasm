#ifndef XASM_PARSER_XASM_AST_ADAPTED_INSTRUCTION_HH
#define XASM_PARSER_XASM_AST_ADAPTED_INSTRUCTION_HH

#include "../../../ast/instruction.hh"

#include <boost/fusion/include/adapt_struct.hpp>

BOOST_FUSION_ADAPT_STRUCT(xasm::ast::instruction::nullary, address_mode, opcode)
BOOST_FUSION_ADAPT_STRUCT(xasm::ast::instruction::unary_byte, address_mode, opcode, operand)
BOOST_FUSION_ADAPT_STRUCT(xasm::ast::instruction::unary_word, address_mode, opcode, operand)

#endif
