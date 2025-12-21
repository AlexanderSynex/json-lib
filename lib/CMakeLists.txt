add_library(json_lib INTERFACE)
target_include_directories(json_lib INTERFACE include)
target_sources(json_lib INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/json.h")
