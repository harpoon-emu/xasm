#include "nullary.hh"

#include "../../config.hh"
#include "accumulator.hh"
#include "implied.hh"

#include <boost/spirit/home/x3.hpp>

namespace xasm {
namespace parser {
namespace xasm {
namespace rules {
namespace instruction {

namespace x3 = boost::spirit::x3;

auto const nullary_def = (accumulator::statement | implied::statement) >> &x3::space;
BOOST_SPIRIT_DEFINE(nullary);
BOOST_SPIRIT_INSTANTIATE(nullary_type, config::iterator_type, config::context_type);

} // namespace instruction
} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm
