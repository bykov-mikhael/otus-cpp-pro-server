cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(${TARGET_NAME} VERSION ${PROJECT_VESRION})

add_executable(${TARGET_NAME} main.cpp)

#find_package(FLTK REQUIRED)
#find_package(OpenGL REQUIRED)

set_target_properties(${TARGET_NAME} PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS ON
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

target_include_directories(
  ${TARGET_NAME} PRIVATE
  ${CMAKE_SOURCE_DIR}/build           # ссылка на config.h.in
  ${CMAKE_SOURCE_DIR}/include/version # ссылка на version
  ${CMAKE_SOURCE_DIR}/include/app_gui # ссылка на app_gui
  ${CMAKE_SOURCE_DIR}/include/mvc     # ссылка на mvc
)

# параметры компановщика/линковщика:
# парамтеры библотек должны совпадать с названием в add_library(shared_lib SHARED, add_library(static_lib STATIC
target_link_libraries(${TARGET_NAME}
  version_lib
  app-gui
  mvc
  #PRIVATE fltk
  #PRIVATE OpenGL::OpenGL
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_compile_options(${TARGET_NAME} PRIVATE -g -Wall -Wextra -Werror -pedantic)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(${TARGET_NAME} PRIVATE /W4 /WX)
endif()