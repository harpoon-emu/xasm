#ifndef XASM_PARSER_XASM_CONFIG_HH
#define XASM_PARSER_XASM_CONFIG_HH

#include "../base.hh"

#include <boost/spirit/home/x3.hpp>
#include <string>

namespace xasm {
namespace parser {
namespace xasm {
namespace config {

namespace x3 = boost::spirit::x3;

using iterator_type = base::iterator_type;
using context_type = x3::unused_type;

} // namespace config
} // namespace xasm
} // namespace parser
} // namespace xasm

#endif
