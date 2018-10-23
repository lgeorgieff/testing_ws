cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(testing_ws CXX)
set(${CMAKE_PROJECT_NAME}_VERSION 0.0.1)

message("-- Project: ${PROJECT_NAME}@${testing_ws_VERSION}")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(CXX_WARNINGS "-Wall -Wextra")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CXX_WARNINGS "-Wpedantic")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(CXX_WARNINGS "/W4 /WX /EHsc")
endif()

message("-- Warnings: ${CXX_WARNINGS}")

if (NOT CONFIGURED_ONCE)
    set(CMAKE_CXX_FLAGS "${CXX_WARNINGS}"
            CACHE STRING "Flags used by the compiler during all build types." FORCE)
    set(CMAKE_C_FLAGS   "${CXX_WARNINGS}"
            CACHE STRING "Flags used by the compiler during all build types." FORCE)
endif()

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(DOCUMENTATION_DIR ${CMAKE_SOURCE_DIR}/doc/)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(GENERATE_TESTS "Build tests wth googletest")

if(GENERATE_TESTS)
    enable_testing()

    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})

    add_executable(testing_ws_unit_tests
            test/utils/car_mock.hpp
            test/utils/engine_mock.hpp
            test/utils/car_base_fixture.hpp
            test/engine.cpp
            test/car.cpp
            test/bmw.cpp
            test/four_series.cpp
            src/engine.cpp src/engine.hpp
            src/car.cpp src/car.hpp
            src/bmw.cpp src/bmw.hpp
            src/four_series.cpp test/four_series.cpp)

    add_test(NAME sample_test_suite COMMAND testing_ws_unit_tests)
    message(STATUS ${GTEST_BOTH_LIBRARIES})

    target_link_libraries(testing_ws_unit_tests ${GTEST_BOTH_LIBRARIES} gmock pthread)
endif()

add_executable(testing_ws
        src/main.cpp
        src/car.cpp src/car.hpp
        src/engine.cpp src/engine.hpp
        src/bmw.cpp src/bmw.hpp
        src/eight_series.cpp src/eight_series.hpp
        src/four_series.cpp src/four_series.hpp
        src/car_manufacturer.cpp src/car_manufacturer.hpp
        src/bmw_manufacturer.cpp src/bmw_manufacturer.hpp)
