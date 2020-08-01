#include "code.hh"

#include "../ast_adapted/code.hh"
#include "../config.hh"
#include "instruction/instruction.hh"
#include "label.hh"

#include <boost/spirit/home/x3.hpp>
#include <string>

namespace xasm {
namespace parser {
namespace xasm {
namespace rules {

namespace x3 = boost::spirit::x3;

static auto const code_line_def
    = (label >> ((x3::omit[*x3::blank] >> &x3::eol >> x3::attr(ast::instruction::empty()))
                 | (x3::omit[+x3::blank] >> instruction::instruction)))
      | (x3::attr("") >> x3::omit[*x3::blank] >> instruction::instruction);
BOOST_SPIRIT_DEFINE(code_line);
BOOST_SPIRIT_INSTANTIATE(code_line_type, config::iterator_type, config::context_type);

static auto const code_def = (code_line >> x3::omit[*x3::blank]) % (x3::eol % *x3::blank);
BOOST_SPIRIT_DEFINE(code);
BOOST_SPIRIT_INSTANTIATE(code_type, config::iterator_type, config::context_type);

} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm
