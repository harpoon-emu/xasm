#ifndef XASM_PARSER_XASM_ASD_ADAPTED_CODE_HH
#define XASM_PARSER_XASM_ASD_ADAPTED_CODE_HH

#include "../../../ast/code.hh"

#include <boost/fusion/include/adapt_struct.hpp>

BOOST_FUSION_ADAPT_STRUCT(xasm::ast::code_line, label, instruction)

#endif
