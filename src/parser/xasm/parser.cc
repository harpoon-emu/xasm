#include "parser.hh"

#include "rules/source.hh"

#include <boost/spirit/home/x3.hpp>

namespace xasm {
namespace parser {
namespace xasm {

namespace x3 = boost::spirit::x3;

void parser::parse(iterator_type &start, const iterator_type &end, ast::source &ast) {
	x3::parse(start, end, rules::source, ast);
}


} // namespace xasm
} // namespace parser
} // namespace xasm
