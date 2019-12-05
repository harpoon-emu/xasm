#include "token.hh"

#include "../config.hh"

#include <boost/spirit/home/x3.hpp>
#include <string>

namespace xasm {
namespace parser {
namespace xasm {
namespace rules {

namespace x3 = boost::spirit::x3;

auto const token_def = +(x3::char_ - x3::space);
BOOST_SPIRIT_DEFINE(token);
BOOST_SPIRIT_INSTANTIATE(token_type, config::iterator_type, config::context_type);

auto const token_sep_def = x3::omit[+x3::blank];
BOOST_SPIRIT_DEFINE(token_sep);
BOOST_SPIRIT_INSTANTIATE(token_sep_type, config::iterator_type, config::context_type);

} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm
