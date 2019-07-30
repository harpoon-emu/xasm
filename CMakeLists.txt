cmake_minimum_required(VERSION 3.9)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(Xasm_MAJOR_VERSION 0)
set(Xasm_MINOR_VERSION 1)
set(Xasm_PATCH_VERSION 0)
set(Xasm_VERSION
  ${Xasm_MAJOR_VERSION}.${Xasm_MINOR_VERSION}.${Xasm_PATCH_VERSION})

project(Xasm LANGUAGES CXX C VERSION ${Xasm_VERSION})

find_package(Boost REQUIRED)

add_executable(xasm
	src/main.cc
)

target_compile_features(xasm
	PRIVATE
		cxx_lambdas
		cxx_range_for
)

install(TARGETS xasm
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
