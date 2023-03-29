cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(enumtest)

find_package(ROOT REQUIRED COMPONENTS RIO Net Tree)

include(${ROOT_USE_FILE})
include_directories(${ROOT_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})


add_compile_options(-g -O0)

ROOT_GENERATE_DICTIONARY(G__enum_definition enum.hh LINKDEF LinkDef.h)
add_library(enum_definition SHARED G__enum_definition.cxx)
target_link_libraries(enum_definition ${ROOT_LIBRARIES})

ROOT_GENERATE_DICTIONARY(G__selector enum_tree.h enum_tree.C LINKDEF SelectorLinkDef.h)
add_library(selector SHARED G__selector.cxx)
target_link_libraries(selector ${ROOT_LIBRARIES} enum_definition)

add_executable(enumgenerate main.cpp)
# target_compile_options(selectorsim PRIVATE )
target_link_libraries(enumgenerate ${ROOT_LIBRARIES} enum_definition)

add_executable(enumselector main_selector.cpp)
# target_compile_options(selectorsim PRIVATE )
target_link_libraries(enumselector ${ROOT_LIBRARIES} enum_definition selector)
