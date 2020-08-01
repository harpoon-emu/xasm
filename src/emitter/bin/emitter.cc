#include "emitter.hh"

#include <ios>

namespace xasm {
namespace emitter {
namespace bin {

emitter::emitter(const std::string &file)
    : _file{file}, _stream{file, std::ios::binary | std::ios::trunc} {}

emitter::~emitter() {}

emitter::offset_t emitter::emit(const ast::instruction::nullary &ast) {
	_emit8(ast.opcode);
	return 1;
}

emitter::offset_t emitter::emit(const ast::instruction::unary_byte &ast) {
	_emit8(ast.opcode);
	_emit8(ast.operand);
	return 2;
}

emitter::offset_t emitter::emit(const ast::instruction::unary_word &ast) {
	_emit8(ast.opcode);
	_emit16(ast.operand);
	return 3;
}

void emitter::_emit8(std::uint8_t v) {
	_stream.write(reinterpret_cast<char *>(&v), sizeof(v));
}

void emitter::_emit16(std::uint16_t v) {
	_stream.write(reinterpret_cast<char *>(&v), sizeof(v));
}

} // namespace bin
} // namespace emitter
} // namespace xasm
