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