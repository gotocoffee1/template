cmake_minimum_required(VERSION 3.16.0)
project(template VERSION 0.1.0)

if(WIN32)
  add_definitions(-DUNICODE -D_UNICODE)
endif()

if(MSVC)
  add_compile_options(/W4)
  string(REGEX REPLACE "/W3" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
else()
  add_compile_options(-Wall -Wextra)
endif()

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

include(CTest)
enable_testing()

include(cmake/pmm.cmake)
pmm(VCPKG REVISION 941d5464544eb5812b2cbd6e687c3ebc78ed2624 REQUIRES fmt
    doctest)

add_library(template)

target_include_directories(
  template
  PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")

target_sources(template PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/lib.cpp")

target_compile_features(template PUBLIC cxx_std_17)

if(NOT VERSION_BUILD)
  set(VERSION_BUILD 0)
endif()

if(NOT BUILD_TIME)
  set(BUILD_TIME 0)
endif()

find_package(fmt CONFIG REQUIRED)

target_compile_definitions(
  template
  PUBLIC VERSION_MAJOR=${PROJECT_VERSION_MAJOR}
         VERSION_MINOR=${PROJECT_VERSION_MINOR}
         VERSION_PATCH=${PROJECT_VERSION_PATCH}
         VERSION_BUILD=${VERSION_BUILD}
         BUILD_TIME=${BUILD_TIME})

target_link_libraries(template PRIVATE fmt::fmt-header-only)

add_subdirectory(test)
add_subdirectory(app)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
