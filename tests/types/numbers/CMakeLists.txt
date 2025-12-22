function(create_test TARGET_NAME SOURCE_NAME)
  add_executable(${TARGET_NAME})
  target_sources(${TARGET_NAME} PRIVATE ${SOURCE_NAME})
  target_link_libraries(${TARGET_NAME} PRIVATE gtest gtest_main json_lib)
  gtest_discover_tests(${TARGET_NAME})
endfunction()

create_test(types_numbers_test test.cxx)
