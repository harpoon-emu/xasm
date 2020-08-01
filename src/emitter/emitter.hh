#ifndef XASM_EMITTER_EMITTER_HH
#define XASM_EMITTER_EMITTER_HH

#include "../ast/source.hh"

#include <map>

namespace xasm {
namespace emitter {

class emitter {
public:
	emitter();
	virtual ~emitter();

	using address_t = std::uint64_t;
	using offset_t = std::int64_t;

	void offset(offset_t o) {
		_current += o;
	}

	virtual void emit(const ast::source &ast);

	virtual void emit(const ast::code &ast);

	virtual void emit(const ast::label &ast);

	virtual offset_t emit(const ast::instruction::empty &ast);
	virtual offset_t emit(const ast::instruction::nullary &ast) = 0;
	virtual offset_t emit(const ast::instruction::unary_byte &ast) = 0;
	virtual offset_t emit(const ast::instruction::unary_word &ast) = 0;

protected:
	void reset();

private:
	address_t _current{};
	std::map<std::string, address_t> _labels{};
};


} // namespace emitter
} // namespace xasm


#endif
