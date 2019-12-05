#include "source.hh"

#include "../config.hh"
#include "code.hh"
#include "instruction/instruction.hh"

#include <boost/spirit/home/x3.hpp>
#include <string>

namespace xasm {
namespace parser {
namespace xasm {
namespace rules {

namespace x3 = boost::spirit::x3;

static auto const source_def = code % (x3::eol % *x3::blank);
BOOST_SPIRIT_DEFINE(source);
BOOST_SPIRIT_INSTANTIATE(source_type, config::iterator_type, config::context_type);

} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm
