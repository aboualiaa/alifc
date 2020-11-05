file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

foreach(filename ${files})
  get_filename_component(stripped_filename ${filename} NAME)
  string(REPLACE ".cpp" "" name ${stripped_filename})

  add_executable(${name} ${stripped_filename})
  target_include_directories(${name} PUBLIC ${GTEST_INCLUDE_DIRS})
  target_link_libraries(${name} ${GTEST_LIBRARIES})

  add_test(${name} ${name})
  set_property(TEST ${name} PROPERTY LABELS Unit)
endforeach()
