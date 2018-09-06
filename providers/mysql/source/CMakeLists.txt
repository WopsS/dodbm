add_library(mysql-provider STATIC "")

set_target_properties(mysql-provider PROPERTIES FOLDER "providers")

file(GLOB_RECURSE HEADERS dodbm/*.hpp)
file(GLOB_RECURSE SOURCES dodbm/*.cpp)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/dodbm/mysql" FILES ${HEADERS} ${SOURCES})

target_include_directories(mysql-provider PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${DODBM_INCLUDE_DIR} ${MYSQL_INCLUDE_DIR})
target_sources(mysql-provider PRIVATE ${HEADERS} ${SOURCES})
target_link_libraries(mysql-provider PUBLIC ${MYSQL_LIBRARY})