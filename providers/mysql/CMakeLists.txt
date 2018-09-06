option(MYSQL_PROVIDER "Generate the provider for MySQL" ON)

if(MYSQL_PROVIDER)
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
    find_package(MySQL REQUIRED)

    add_subdirectory(source)
    add_subdirectory(tests)
endif()