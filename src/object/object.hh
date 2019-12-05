#ifndef XASM_OBJECT_OBJECT_HH
#define XASM_OBJECT_OBJECT_HH

#include "segment.hh"

#include <vector>

namespace xasm {
namespace object {

class object {

private:
	std::vector<segment> _segments{};
};

} // namespace object
} // namespace xasm

#endif
