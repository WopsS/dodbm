add_executable(dodbm-tests "")

set_target_properties(dodbm-tests PROPERTIES FOLDER "tests")

file(GLOB_RECURSE HEADERS *.hpp)
file(GLOB_RECURSE SOURCES *.cpp)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${HEADERS} ${SOURCES})

target_include_directories(dodbm-tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CATCH_INCLUDE_DIR})
target_sources(dodbm-tests PRIVATE ${HEADERS} ${SOURCES})
target_link_libraries(dodbm-tests PRIVATE dodbm)