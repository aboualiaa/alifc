add_library(compile macos.cpp global.cpp log.cpp core.cpp setup.cpp)
target_include_directories(compile PRIVATE ${Boost_INCLUDE_DIRS})