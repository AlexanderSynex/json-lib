cmake_minimum_required(VERSION 3.16)
project(json-lib)

if(NOT CMAKE_BUILD_TYPE)
  set(default_build_type "Debug")
  message(STATUS "Set the build type to `${default_build_type}` as none was specified.")
  set(CMAKE_BUILD_TYPE ${default_build_type} CACHE STRING "Chooce the build type." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
  "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()
message(STATUS "json-lib Build Type: ${CMAKE_BUILD_TYPE}")

# Set the version for json-lib
set(json-lib_Version_Major 0)
set(json-lib_Version_Minor 1)
set(json-lib_Version_Patch 0)
set(json-lib_Version_Status "-dev")
set(PROJECT_VERSION
  "${json-lib_Version_Major}.${json-lib_Version_Minor}.${json-lib_Version_Patch}${json-lib_Version_Status}"
)
message(STATUS "${PROJECT_NAME} version: ${PROJECT_VERSION}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(json_lib INTERFACE)
target_include_directories(json_lib INTERFACE include)
target_sources(json_lib INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/json.h")

add_subdirectory(tests)