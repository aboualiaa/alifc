add_library(lexer lexer.cpp)
target_include_directories(lexer PRIVATE ${Boost_INCLUDE_DIRS})
