project(example_module)

source_group( " "  REGULAR_EXPRESSION .*)

add_executable(
        module
        Main.cpp
        ${CMAKE_SOURCE_DIR}/include/strong_type/strong_type.ixx)

set_target_properties(module PROPERTIES FOLDER "example")