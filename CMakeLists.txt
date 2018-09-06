cmake_minimum_required(VERSION 3.1)

project(dodbm VERSION 1.0.0)

# Properties.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Variables.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/libs")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

foreach(configuration ${CMAKE_CONFIGURATION_TYPES})
    string(TOLOWER ${configuration} configuration_lower)
    string(TOUPPER ${configuration} configuration_upper)

    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${configuration_upper} "${CMAKE_BINARY_DIR}/${configuration_lower}/libs")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${configuration_upper} "${CMAKE_BINARY_DIR}/${configuration_lower}/bin")
endforeach()

set(CATCH_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/catch2/single_include")

math(EXPR PROJECT_VERSION_INT "${PROJECT_VERSION_MAJOR} * 10000 + ${PROJECT_VERSION_MINOR} * 100 + ${PROJECT_VERSION_PATCH}")

# Projects.
add_subdirectory(source)
add_subdirectory(tests)

add_subdirectory(providers)