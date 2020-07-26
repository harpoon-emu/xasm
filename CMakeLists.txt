cmake_minimum_required(VERSION 3.9)

set(Xasm_MAJOR_VERSION 0)
set(Xasm_MINOR_VERSION 1)
set(Xasm_PATCH_VERSION 0)
set(Xasm_VERSION
  ${Xasm_MAJOR_VERSION}.${Xasm_MINOR_VERSION}.${Xasm_PATCH_VERSION})

project(Xasm LANGUAGES CXX C VERSION ${Xasm_VERSION})

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

find_package(Boost 1.69.0 REQUIRED COMPONENTS program_options)

add_executable(xasm
	src/ast/ast.hh
	src/ast/code.hh
	src/ast/instruction.hh
	src/ast/source.hh
	src/emitter/bin/emitter.cc
	src/emitter/bin/emitter.hh
	src/emitter/emitter.cc
	src/emitter/emitter.hh
	src/main.cc
	src/parser/base.hh
	src/parser/parser.cc
	src/parser/parser.hh
	src/parser/xasm/ast_adapted/ast_adapted.hh
	src/parser/xasm/ast_adapted/instruction.hh
	src/parser/xasm/config.hh
	src/parser/xasm/parser.cc
	src/parser/xasm/parser.hh
	src/parser/xasm/rules/code.cc
	src/parser/xasm/rules/code.hh
	src/parser/xasm/rules/instruction/absolute.cc
	src/parser/xasm/rules/instruction/absolute.hh
	src/parser/xasm/rules/instruction/absolute_x.cc
	src/parser/xasm/rules/instruction/absolute_x.hh
	src/parser/xasm/rules/instruction/absolute_y.cc
	src/parser/xasm/rules/instruction/absolute_y.hh
	src/parser/xasm/rules/instruction/accumulator.cc
	src/parser/xasm/rules/instruction/accumulator.hh
	src/parser/xasm/rules/instruction/immediate.cc
	src/parser/xasm/rules/instruction/immediate.hh
	src/parser/xasm/rules/instruction/implied.cc
	src/parser/xasm/rules/instruction/implied.hh
	src/parser/xasm/rules/instruction/indirect.cc
	src/parser/xasm/rules/instruction/indirect.hh
	src/parser/xasm/rules/instruction/indirect_y.cc
	src/parser/xasm/rules/instruction/indirect_y.hh
	src/parser/xasm/rules/instruction/instruction.cc
	src/parser/xasm/rules/instruction/instruction.hh
	src/parser/xasm/rules/instruction/nullary.cc
	src/parser/xasm/rules/instruction/nullary.hh
	src/parser/xasm/rules/instruction/operand.cc
	src/parser/xasm/rules/instruction/operand.hh
	src/parser/xasm/rules/instruction/relative.cc
	src/parser/xasm/rules/instruction/relative.hh
	src/parser/xasm/rules/instruction/unary.cc
	src/parser/xasm/rules/instruction/unary.hh
	src/parser/xasm/rules/instruction/x_indirect.cc
	src/parser/xasm/rules/instruction/x_indirect.hh
	src/parser/xasm/rules/instruction/zeropage.cc
	src/parser/xasm/rules/instruction/zeropage.hh
	src/parser/xasm/rules/instruction/zeropage_x.cc
	src/parser/xasm/rules/instruction/zeropage_x.hh
	src/parser/xasm/rules/instruction/zeropage_y.cc
	src/parser/xasm/rules/instruction/zeropage_y.hh
	src/parser/xasm/rules/source.cc
	src/parser/xasm/rules/source.hh
	src/parser/xasm/rules/token.cc
	src/parser/xasm/rules/token.hh
	src/object/object.cc
	src/object/object.hh
	src/object/segment.cc
	src/object/segment.hh
)

target_compile_features(xasm
	PRIVATE
		cxx_std_20
		cxx_auto_type
		cxx_defaulted_functions
		cxx_defaulted_move_initializers
		cxx_delegating_constructors
		cxx_deleted_functions
		cxx_generalized_initializers
		cxx_inheriting_constructors
		cxx_lambdas
		cxx_lambda_init_captures
		cxx_nonstatic_member_init
		cxx_nullptr
		cxx_override
		cxx_range_for
		cxx_right_angle_brackets
		cxx_rvalue_references
		cxx_uniform_initialization
		cxx_variadic_macros
		cxx_variadic_templates
		cxx_template_template_parameters
)

target_link_libraries(xasm
	PRIVATE
		Boost::boost
		Boost::program_options
)

install(TARGETS xasm
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
