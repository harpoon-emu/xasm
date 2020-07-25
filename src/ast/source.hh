#ifndef XASM_AST_SOURCE_HH
#define XASM_AST_SOURCE_HH

#include "code.hh"

#include <boost/fusion/include/io.hpp>
#include <vector>

namespace xasm {
namespace ast {

using source = std::vector<code>;

using boost::fusion::operator<<;

} // namespace ast
} // namespace xasm

#endif
