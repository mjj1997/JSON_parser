cmake_minimum_required(VERSION 3.20)

project(JsonParser VERSION 0.1 LANGUAGES CXX)

option(BUILD_SHARED_LIBS "build JSON parser shared library" ON)
option(BUILD_STATIC_LIBS "build JSON parser static library" ON)

option(BUILD_EXAMPLES "build examples" OFF)
option(BUILD_TESTS "build unit tests" OFF)

message(STATUS "CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}")
message(STATUS "CMAKE_SYSTEM_NAME=${CMAKE_SYSTEM_NAME}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(src)

if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()

