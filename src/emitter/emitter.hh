#ifndef XASM_EMITTER_EMITTER_HH
#define XASM_EMITTER_EMITTER_HH

#include "../ast/source.hh"

namespace xasm {
namespace emitter {

class emitter {
public:
	emitter();
	virtual ~emitter();

	virtual void emit(const ast::source &ast);

	virtual void emit(const ast::code &ast);

	virtual void emit(const ast::instruction::nullary &ast) = 0;
	virtual void emit(const ast::instruction::unary_byte &ast) = 0;
	virtual void emit(const ast::instruction::unary_word &ast) = 0;
};


} // namespace emitter
} // namespace xasm


#endif
