add_library(json_lib INTERFACE)
target_include_directories(json_lib INTERFACE include/)
target_sources(json_lib INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/snx/json/json.h"
                                  "${CMAKE_CURRENT_SOURCE_DIR}/include/snx/json/details/utils.hpp"
                                  "${CMAKE_CURRENT_SOURCE_DIR}/include/snx/json/details/types.hpp"
                                  "${CMAKE_CURRENT_SOURCE_DIR}/include/snx/json/details/details.hpp")
