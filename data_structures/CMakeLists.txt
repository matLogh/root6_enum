find_package(ROOT REQUIRED COMPONENTS RIO Net Tree)

include(${ROOT_USE_FILE})
include_directories(${ROOT_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})


ROOT_GENERATE_DICTIONARY(G__enum_definition enum.hh LINKDEF LinkDef.h)
add_library(enum_definition SHARED G__enum_definition.cxx)
target_link_libraries(enum_definition ${ROOT_LIBRARIES})