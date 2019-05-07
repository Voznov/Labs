cmake_minimum_required(VERSION 3.14)
project(5)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-D_DEBUG)

add_executable(A a.cpp)
add_executable(B b.cpp)
add_executable(F f.cpp)
add_executable(G g.cpp)
add_executable(H h.cpp)
