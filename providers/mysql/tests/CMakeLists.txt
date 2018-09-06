add_executable(mysql-provider-tests "")

set_target_properties(mysql-provider-tests PROPERTIES FOLDER "tests")

file(GLOB_RECURSE HEADERS *.hpp)
file(GLOB_RECURSE SOURCES *.cpp)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${HEADERS} ${SOURCES})

target_include_directories(mysql-provider-tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CATCH_INCLUDE_DIR})
target_sources(mysql-provider-tests PRIVATE ${HEADERS} ${SOURCES})
target_link_libraries(mysql-provider-tests PRIVATE mysql-provider dodbm)