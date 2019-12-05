#ifndef XASM_PARSER_AST_SOURCE_HH
#define XASM_PARSER_AST_SOURCE_HH

#include "code.hh"

#include <boost/fusion/include/io.hpp>
#include <vector>

namespace xasm {
namespace parser {
namespace ast {

using source = std::vector<code>;

using boost::fusion::operator<<;

} // namespace ast
} // namespace parser
} // namespace xasm

#endif
