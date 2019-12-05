#ifndef XASM_PARSER_AST_CODE_HH
#define XASM_PARSER_AST_CODE_HH

#include "instruction.hh"

#include <vector>

namespace xasm {
namespace parser {
namespace ast {

using code = std::vector<ast::instruction::variant>;

} // namespace ast
} // namespace parser
} // namespace xasm

#endif
