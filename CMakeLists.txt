cmake_minimum_required(VERSION 3.10)
project(lib-algo-ds LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory(test)
add_subdirectory(lib)
add_subdirectory(leetcode-august)
add_subdirectory(leetcode-september)
