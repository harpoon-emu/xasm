#include "label.hh"

#include "../config.hh"
#include "token.hh"

#include <boost/spirit/home/x3.hpp>
#include <string>

namespace xasm {
namespace parser {
namespace xasm {
namespace rules {

namespace x3 = boost::spirit::x3;

static auto const label_def = +(x3::char_ - x3::blank - ':') >> x3::lit(":");
BOOST_SPIRIT_DEFINE(label);
BOOST_SPIRIT_INSTANTIATE(label_type, config::iterator_type, config::context_type);

} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm
