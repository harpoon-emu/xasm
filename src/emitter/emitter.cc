#include "emitter.hh"

#include <iomanip>
#include <iostream>
#include <string>

namespace xasm {
namespace emitter {

emitter::emitter() {}

emitter::~emitter() {}

void emitter::reset() {
	_current = 0;
	_labels.clear();
}

void emitter::emit(const ast::source &ast) {
	reset();
	for (auto i : ast) {
		emit(i);
	}
}

class instruction_visitor : public boost::static_visitor<> {
public:
	instruction_visitor(emitter &e) : _emitter{e} {}

	template<typename T>
	void operator()(const T &x) const {
		_emitter.offset(_emitter.emit(x));
	}

private:
	emitter &_emitter;
};

void emitter::emit(const ast::code &ast) {
	instruction_visitor v(*this);
	for (auto i : ast) {
		if (!i.label.empty()) {
			emit(i.label);
		}
		boost::apply_visitor(v, i.instruction);
	}
}

void emitter::emit(const ast::label &ast) {
	_labels[ast] = _current;
}

emitter::offset_t emitter::emit(const ast::instruction::empty &ast) {
	return 0;
}

} // namespace emitter
} // namespace xasm
