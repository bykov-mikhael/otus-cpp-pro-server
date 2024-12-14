cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(mvc VERSION 0.0.1)

add_library(mvc STATIC  IController.hpp Controller.hpp Controller.cpp
                        IView.hpp View.hpp View.cpp
                        IModel.hpp Model.hpp Model.cpp)

set_target_properties(mvc PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

find_package(FLTK REQUIRED)
find_package(OpenGL REQUIRED)

target_include_directories(mvc
  PRIVATE ${CMAKE_SOURCE_DIR}/build
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_compile_options(mvc PRIVATE -g -Wall -Wextra -Werror -pedantic)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(mvc PRIVATE /W4 /WX)
endif()