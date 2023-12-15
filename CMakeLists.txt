cmake_minimum_required(VERSION 3.2.26)
project("catch2-course")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# It's necessary to install catch before execute this commands. See
# https://github.com/catchorg/Catch2/issues/1383

# These tests need their own main
find_package(Catch2 3 REQUIRED)

add_executable(minimumExample minimumExample.cpp)
target_link_libraries(minimumExample PRIVATE Catch2::Catch2WithMain)

add_executable(example1 example1.cpp)
target_link_libraries(example1 PRIVATE Catch2::Catch2WithMain)

add_executable(example2 example2.cpp)
target_link_libraries(example2 PRIVATE Catch2::Catch2WithMain)

add_executable(example3 example3.cpp)
target_link_libraries(example3 PRIVATE Catch2::Catch2WithMain)

add_executable(example4 example4.cpp)
target_link_libraries(example4 PRIVATE Catch2::Catch2WithMain)

add_executable(example5 example5.cpp)
target_link_libraries(example5 PRIVATE Catch2::Catch2WithMain)

add_executable(example6 example6.cpp)
target_link_libraries(example6 PRIVATE Catch2::Catch2WithMain)

add_executable(example7 example7.cpp)
target_link_libraries(example7 PRIVATE Catch2::Catch2WithMain)