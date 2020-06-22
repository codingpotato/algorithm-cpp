cmake_minimum_required(VERSION 3.13)

project(algorithm-cpp VERSION 0.1 DESCRIPTION "Algorithm cpp" LANGUAGES CXX)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
include(update_submodules)

include(CTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS_RELEASE
    "${CMAKE_CXX_FLAGS_RELEASE} -DDOCTEST_CONFIG_DISABLE")

set(DOCTEST_DIR ${PROJECT_SOURCE_DIR}/tools/doctest)
add_subdirectory(tools)

add_executable(algorithm-cpp main.cpp ${TESTS_SOURCES})
add_dependencies(algorithm-cpp doctest)
target_include_directories(algorithm-cpp PUBLIC ${DOCTEST_DIR})

include(${DOCTEST_DIR}/scripts/cmake/doctest.cmake)
doctest_discover_tests(algorithm-cpp)
