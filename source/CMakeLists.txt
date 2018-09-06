add_library(dodbm STATIC "")

configure_file("dodbm/version.hpp.in" "${CMAKE_CURRENT_SOURCE_DIR}/dodbm/version.hpp" @ONLY)


file(GLOB_RECURSE HEADERS dodbm/*.hpp)
file(GLOB_RECURSE SOURCES dodbm/*.cpp)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/dodbm" FILES ${HEADERS} ${SOURCES})

target_include_directories(dodbm PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_sources(dodbm PRIVATE ${HEADERS} ${SOURCES})

set(DODBM_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE INTERNAL "")