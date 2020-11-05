cmake_minimum_required(VERSION 3.17)
project(alifc)
set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED COMPONENTS program_options unit_test_framework
        filesystem log atomic)
find_package(spdlog REQUIRED)
find_package(fmt REQUIRED)

include(CTest)
find_package(GTest REQUIRED)

include_directories(include ${Boost_INCLUDE_DIRS} ${SPDLOG_INCLUDE_DIRS} ${FMT_INCLUDE_DIRS})

add_subdirectory(lib)

add_executable(alifc alif.cpp)

target_link_libraries(alifc compile generator lexer parser support fmt::fmt Boost::program_options)

if(BUILD_TESTING)
  add_subdirectory(unittests)
endif()
