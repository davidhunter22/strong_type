#
# strong_type C++14/17/20 strong typedef library
#
# Copyright (C) Björn Fahller
#
#  Use, modification and distribution is subject to the
#  Boost Software License, Version 1.0. (See accompanying
#  file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt)
#
# Project home: https://github.com/rollbear/strong_type
#

cmake_minimum_required(VERSION 3.14)
project(strong_type)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

option(STRONG_TYPE_MODULE     "Build into a module" ON)
option(STRONG_TYPE_UNIT_TEST  "Decide whether to build unit tests or not" ON)

set(STRONG_TYPE_VERSION 15)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(MASTER_PROJECT OFF)
if (${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
  set(MASTER_PROJECT ON)
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

# By default we don't want the Visual Studio default "sources" and "headers" folders, the following put's everything directly in the project
if (MSVC)
    source_group( " "  REGULAR_EXPRESSION .*)
endif()

if (${STRONG_TYPE_UNIT_TEST})
  add_subdirectory(test)
endif()

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/strong_type/strong_type-config-version.cmake"
  VERSION ${STRONG_TYPE_VERSION}
  COMPATIBILITY AnyNewerVersion
  ARCH_INDEPENDENT)

# file(GLOB STRONG_TYPE_SOURCE ${CMAKE_SOURCE_DIR}/include/strong_type/*.hpp)

set(STRONG_TYPE_SOURCE
    include/strong_type/strong_type.ixx
    include/strong_type/strong_type.cpp
    include/strong_type/affine_point.hpp
    include/strong_type/affine_point.hpp
    include/strong_type/arithmetic.hpp
    include/strong_type/bicrementable.hpp
    include/strong_type/bitarithmetic.hpp
    include/strong_type/boolean.hpp
    include/strong_type/convertible_to.hpp
    include/strong_type/decrementable.hpp
    include/strong_type/difference.hpp
    include/strong_type/equality.hpp
    include/strong_type/equality_with.hpp
    include/strong_type/formattable.hpp
    include/strong_type/hashable.hpp
    include/strong_type/implicitly_convertible_to.hpp
    include/strong_type/incrementable.hpp
    include/strong_type/indexed.hpp
    include/strong_type/invocable.hpp
    include/strong_type/iostreamable.hpp
    include/strong_type/istreamable.hpp
    include/strong_type/iterator.hpp
    include/strong_type/ordered.hpp
    include/strong_type/ordered_with.hpp
    include/strong_type/ostreamable.hpp
    include/strong_type/pointer.hpp
    include/strong_type/range.hpp
    include/strong_type/regular.hpp
    include/strong_type/scalable_with.hpp
    include/strong_type/semiregular.hpp
    include/strong_type/strong_ordering.hpp
    include/strong_type/strong_type.hpp
    include/strong_type/type.hpp
    include/strong_type/unique.hpp
)

if(${STRONG_TYPE_MODULE})
  add_library(strong_type ${STRONG_TYPE_SOURCE})
else()
  add_library(strong_type INTERFACE)
endif()

add_library(strong_type::strong_type ALIAS strong_type)

target_include_directories(
  strong_type
  INTERFACE
  $<BUILD_INTERFACE:${INCLUDE_DIR}>
)

target_include_directories(
  strong_type
  INTERFACE
  $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/include>
)

install(
  TARGETS
    strong_type
  EXPORT
    strong_type-targets
  INCLUDES DESTINATION
    include
)

install(
  EXPORT
    strong_type-targets
  NAMESPACE
    strong_type::
  DESTINATION
    lib/cmake/strong_type
)
install(
  FILES
    strong_type-config.cmake
    "${CMAKE_CURRENT_BINARY_DIR}/strong_type/strong_type-config-version.cmake"
  DESTINATION
    lib/cmake/strong_type
  COMPONENT
    Devel
)

install(
  DIRECTORY
    "include/strong_type/"
  DESTINATION
    "${CMAKE_INSTALL_INCLUDEDIR}/strong_type"
)
