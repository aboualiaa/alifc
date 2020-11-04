cmake_minimum_required(VERSION 3.17)
project(alifc)
set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED)

include_directories(include)

add_subdirectory(lib)

add_executable(alifc alif.cpp)
target_include_directories(alifc PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(alifc compile generator lexer parser)
