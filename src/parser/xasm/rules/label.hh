#ifndef XASM_PARSER_XASM_RULES_LABEL_HH
#define XASM_PARSER_XASM_RULES_LABEL_HH

#include "../../../ast/label.hh"

#include <boost/spirit/home/x3.hpp>
#include <string>

namespace xasm {
namespace parser {
namespace xasm {
namespace rules {

namespace x3 = boost::spirit::x3;

using label_type = x3::rule<class label, ast::label>;
static label_type const label = "label";
BOOST_SPIRIT_DECLARE(label_type);

} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm

#endif
