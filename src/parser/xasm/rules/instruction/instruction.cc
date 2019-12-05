#include "instruction.hh"

#include "../../config.hh"
#include "../token.hh"
#include "nullary.hh"
#include "unary.hh"

#include <boost/spirit/home/x3.hpp>

namespace xasm {
namespace parser {
namespace xasm {
namespace rules {
namespace instruction {

namespace x3 = boost::spirit::x3;

static auto const instruction_def = -token_sep >> (nullary | unary_byte | unary_word) >> -token_sep;
BOOST_SPIRIT_DEFINE(instruction);
BOOST_SPIRIT_INSTANTIATE(instruction_type, config::iterator_type, config::context_type);

} // namespace instruction
} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm
