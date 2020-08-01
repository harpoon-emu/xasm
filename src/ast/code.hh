#ifndef XASM_AST_CODE_HH
#define XASM_AST_CODE_HH

#include "instruction.hh"
#include "label.hh"

#include <vector>

namespace xasm {
namespace ast {

struct code_line {
	ast::label label;
	instruction::variant instruction;
};

using code = std::vector<code_line>;

} // namespace ast
} // namespace xasm

#endif
