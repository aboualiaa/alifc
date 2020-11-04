add_library(generator generator.cpp pc_console.cpp pc_gui.cpp phone_android.cpp)
target_include_directories(generator PRIVATE ${Boost_INCLUDE_DIRS})
