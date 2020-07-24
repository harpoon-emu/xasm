cmake_minimum_required(VERSION 3.9)

set(Xasm_MAJOR_VERSION 0)
set(Xasm_MINOR_VERSION 1)
set(Xasm_PATCH_VERSION 0)
set(Xasm_VERSION
  ${Xasm_MAJOR_VERSION}.${Xasm_MINOR_VERSION}.${Xasm_PATCH_VERSION})

project(Xasm LANGUAGES CXX C VERSION ${Xasm_VERSION})

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

find_package(Boost REQUIRED COMPONENTS program_options)

add_executable(xasm
	src/main.cc
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
