#ifndef XASM_PARSER_XASM_RULES_SOURCE_HH
#define XASM_PARSER_XASM_RULES_SOURCE_HH

#include "../../ast/source.hh"

#include <boost/spirit/home/x3.hpp>
#include <string>

namespace xasm {
namespace parser {
namespace xasm {
namespace rules {

namespace x3 = boost::spirit::x3;

using source_type = x3::rule<class source, ast::source>;
static source_type const source = "source";
BOOST_SPIRIT_DECLARE(source_type);

} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm

#endif
