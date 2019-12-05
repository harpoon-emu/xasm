#ifndef XASM_OBJECT_SEGMENT_HH
#define XASM_OBJECT_SEGMENT_HH

#include <cstdint>

namespace xasm {
namespace object {

class segment {

public:
	segment(std::uint64_t offset = 0) : _offset{offset} {}

	std::uint64_t get_offset() const {
		return _offset;
	}

private:
	std::uint64_t _offset{};
};

} // namespace object
} // namespace xasm

#endif
