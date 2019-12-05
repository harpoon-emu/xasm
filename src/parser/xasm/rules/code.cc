#include "code.hh"

#include "../config.hh"
#include "instruction/instruction.hh"

#include <boost/spirit/home/x3.hpp>
#include <string>

namespace xasm {
namespace parser {
namespace xasm {
namespace rules {

namespace x3 = boost::spirit::x3;

static auto const code_def = instruction::instruction % (x3::eol % *x3::blank);
BOOST_SPIRIT_DEFINE(code);
BOOST_SPIRIT_INSTANTIATE(code_type, config::iterator_type, config::context_type);

} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm
