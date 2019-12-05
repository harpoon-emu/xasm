#include "operand.hh"

#include "../../config.hh"

#include <boost/spirit/home/x3.hpp>

namespace xasm {
namespace parser {
namespace xasm {
namespace rules {
namespace instruction {

namespace x3 = boost::spirit::x3;

auto byte_validate = [](auto &ctx) {
	if (_attr(ctx) > 0xff) {
		_pass(ctx) = false;
		return;
	}
	_val(ctx) = _attr(ctx);
};

auto word_validate = [](auto &ctx) {
	if (_attr(ctx) > 0xffff) {
		_pass(ctx) = false;
		return;
	}
	_val(ctx) = _attr(ctx);
};

auto const byte_def = (x3::uint_[byte_validate] | (x3::lit("$") >> x3::hex[byte_validate]));
BOOST_SPIRIT_DEFINE(byte);
BOOST_SPIRIT_INSTANTIATE(byte_type, config::iterator_type, config::context_type);

auto const word_def = (x3::uint_[word_validate] | (x3::lit("$") >> x3::hex[word_validate]));
BOOST_SPIRIT_DEFINE(word);
BOOST_SPIRIT_INSTANTIATE(word_type, config::iterator_type, config::context_type);

} // namespace instruction
} // namespace rules
} // namespace xasm
} // namespace parser
} // namespace xasm
