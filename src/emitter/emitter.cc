#include "emitter.hh"

#include <iomanip>
#include <iostream>
#include <string>

namespace xasm {
namespace emitter {

emitter::emitter() {}

emitter::~emitter() {}

void emitter::emit(const ast::source &ast) {
	for (auto i : ast) {
		emit(i);
	}
}

class code_visitor : public boost::static_visitor<> {
public:
	code_visitor(emitter &e) : _emitter{e} {}

	template<typename T>
	void operator()(const T &x) const {
		_emitter.emit(x);
	}

private:
	emitter &_emitter;
};

void emitter::emit(const ast::code &ast) {
	code_visitor v(*this);
	for (auto i : ast) {
		boost::apply_visitor(v, i);
	}
}

} // namespace emitter
} // namespace xasm
