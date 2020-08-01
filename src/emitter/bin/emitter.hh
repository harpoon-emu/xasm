#ifndef XASM_EMITTER_BIN_EMITTER_HH
#define XASM_EMITTER_BIN_EMITTER_HH

#include "../emitter.hh"

#include <fstream>
#include <string>

namespace xasm {
namespace emitter {
namespace bin {

class emitter : public xasm::emitter::emitter {

public:
	emitter(const std::string &file);
	virtual ~emitter();

	using xasm::emitter::emitter::emit;

	virtual offset_t emit(const ast::instruction::nullary &ast) override;
	virtual offset_t emit(const ast::instruction::unary_byte &ast) override;
	virtual offset_t emit(const ast::instruction::unary_word &ast) override;


private:
	void _emit8(std::uint8_t v);
	void _emit16(std::uint16_t v);

	std::string _file{};
	std::ofstream _stream{};
};

} // namespace bin
} // namespace emitter
} // namespace xasm

#endif
