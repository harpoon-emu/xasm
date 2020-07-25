#ifndef XASM_AST_CODE_HH
#define XASM_AST_CODE_HH

#include "instruction.hh"

#include <vector>

namespace xasm {
namespace ast {

using code = std::vector<ast::instruction::variant>;

} // namespace ast
} // namespace xasm

#endif
