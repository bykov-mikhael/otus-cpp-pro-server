message(STATUS "Проект ${TARGET_NAME}, тип сборки ${CMAKE_BUILD_TYPE}")
message(STATUS "ОС ${CMAKE_SYSTEM_NAME}, компилятор ${CMAKE_CXX_COMPILER_ID}")

cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(${TARGET_NAME} VERSION ${PROJECT_VESRION})

add_executable(${TARGET_NAME} main.cpp)

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
  ${CMAKE_SOURCE_DIR}/include/app_prm # ссылка на 
)

# параметры компановщика/линковщика:
# парамтеры библотек должны совпадать с названием в add_library(shared_lib SHARED, add_library(static_lib STATIC
target_link_libraries(${TARGET_NAME}
  version_lib
  app-gui
  mvc
  app-prm
)

# CMAKE_SYSTEM_NAME (https://cmake.org/cmake/help/latest/variable/CMAKE_SYSTEM_NAME.html#variable:CMAKE_SYSTEM_NAME)
# Linux
# Windows

# CMAKE_CXX_COMPILER_ID (https://cmake.org/cmake/help/latest/variable/CMAKE_LANG_COMPILER_ID.html)
# GNU
# Clang
# MSVC

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Параметры компиляции Linux ${CMAKE_CXX_COMPILER_ID}: -g -Wall -Wextra -Werror -pedantic")
    target_compile_options(${TARGET_NAME} PRIVATE -g -Wall -Wextra -Werror -pedantic) 
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "Параметры компиляции Windows ${CMAKE_CXX_COMPILER_ID}: /W4 /WX")
    target_compile_options(${TARGET_NAME} PRIVATE /W4 /WX) 
endif()