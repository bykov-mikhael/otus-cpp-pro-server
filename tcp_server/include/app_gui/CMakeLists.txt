cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(app-gui VERSION 0.0.1)

add_library(app-gui STATIC  wnd.hpp wnd.cpp)

set_target_properties(app-gui PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

find_package(FLTK REQUIRED)
find_package(OpenGL REQUIRED)

target_include_directories(app-gui
  PRIVATE ${CMAKE_SOURCE_DIR}/build
)

target_link_libraries(app-gui PRIVATE fltk
                              PRIVATE OpenGL::OpenGL
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_compile_options(app-gui PRIVATE -g -Wall -Wextra -Werror -pedantic)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(app-gui PRIVATE /W4 /WX)
endif()