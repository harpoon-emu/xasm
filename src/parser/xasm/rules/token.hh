#ifndef XASM_PARSER_XASM_RULES_TOKEN_HH
#define XASM_PARSER_XASM_RULES_TOKEN_HH

#include <boost/spirit/home/x3.hpp>
#include <string>

namespace xasm {
namespace parser {
namespace xasm {
namespace rules {

namespace x3 = boost::spirit::x3;

using token_type = x3::rule<class token, std::string>;
static token_type const token = "token";
BOOST_SPIRIT_DECLARE(token_type);

using token_sep_type = x3::rule<class token_sep>;
static token_sep_type const token_sep = "token_sep";
BOOST_SPIRIT_DECLARE(token_sep_type);

} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm

#endif
