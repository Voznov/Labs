cmake_minimum_required(VERSION 3.14)
project(5)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-D_DEBUG)

add_executable(A A.cpp)
add_executable(B B.cpp)
add_executable(C C.cpp)
add_executable(E E.cpp)
add_executable(F F.cpp)
add_executable(gen gen.cpp)
