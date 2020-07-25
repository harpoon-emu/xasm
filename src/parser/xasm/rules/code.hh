#ifndef XASM_PARSER_XASM_RULES_CODE_HH
#define XASM_PARSER_XASM_RULES_CODE_HH

#include "../../../ast/code.hh"

#include <boost/spirit/home/x3.hpp>
#include <string>

namespace xasm {
namespace parser {
namespace xasm {
namespace rules {

namespace x3 = boost::spirit::x3;

using code_type = x3::rule<class code, ast::code>;
static code_type const code = "code";
BOOST_SPIRIT_DECLARE(code_type);

} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm

#endif
