cmake_minimum_required(VERSION 3.2)

set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)
if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(SEND_ERROR "In-source builds are not allowed.")
endif ()

set(CMAKE_COLOR_MAKEFILE   ON)

project(xasm)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	set(CMAKE_COMMON_CXX_FLAGS
		-std=c++17
		-Werror
		-Weverything
		-Wno-c++98-compat
		-Wno-c++98-compat-pedantic
		-Wno-padded
		-Wno-redundant-parens
		-Wno-extra-semi-stmt
		-Wno-unknown-warning-option
		)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
	set(CMAKE_COMMON_CXX_FLAGS
		-std=c++17
		-Wall
		-Werror
		)
endif()

string(REGEX REPLACE ";" " " CMAKE_COMMON_CXX_FLAGS "${CMAKE_COMMON_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_COMMON_CXX_FLAGS}")

file(GLOB_RECURSE CC_FILES src/*.cc)

add_executable(xasm ${CC_FILES})
