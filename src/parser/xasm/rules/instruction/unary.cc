#include "unary.hh"

#include "../../config.hh"
#include "absolute.hh"
#include "absolute_x.hh"
#include "absolute_y.hh"
#include "immediate.hh"
#include "indirect.hh"
#include "indirect_y.hh"
#include "relative.hh"
#include "x_indirect.hh"
#include "zeropage.hh"
#include "zeropage_x.hh"
#include "zeropage_y.hh"

#include <boost/spirit/home/x3.hpp>

namespace xasm {
namespace parser {
namespace xasm {
namespace rules {
namespace instruction {

namespace x3 = boost::spirit::x3;

auto const unary_byte_def
    = (immediate::statement | indirect_y::statement | relative::statement | x_indirect::statement
       | zeropage::statement | zeropage_x::statement | zeropage_y::statement)
      >> &x3::space;
BOOST_SPIRIT_DEFINE(unary_byte);
BOOST_SPIRIT_INSTANTIATE(unary_byte_type, config::iterator_type, config::context_type);

auto const unary_word_def
    = (absolute::statement | absolute_x::statement | absolute_y::statement | indirect::statement)
      >> &x3::space;
BOOST_SPIRIT_DEFINE(unary_word);
BOOST_SPIRIT_INSTANTIATE(unary_word_type, config::iterator_type, config::context_type);

} // namespace instruction
} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm
