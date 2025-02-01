cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(${TARGET_NAME} VERSION ${PROJECT_VESRION})

# Find gtkmm
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

add_executable(${TARGET_NAME} main.cpp ../ui/wnd.hpp ../ui/wnd.cpp)

set_target_properties(${TARGET_NAME} PROPERTIES
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS ON
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

target_include_directories(
  ${TARGET_NAME} PRIVATE
  ${CMAKE_SOURCE_DIR}/build           # ссылка на config.h.in
  ${CMAKE_SOURCE_DIR}/include/version # ссылка на version
  ${GTKMM_INCLUDE_DIRS}
  ${CMAKE_SOURCE_DIR}/include/mvc     # ссылка на mvc
  ${CMAKE_SOURCE_DIR}/include/app_prm # ссылка на 
)

# параметры компановщика/линковщика:
# парамтеры библотек должны совпадать с названием в add_library(shared_lib SHARED, add_library(static_lib STATIC
target_link_libraries(${TARGET_NAME}
  version_lib
  ${GTKMM_LIBRARIES}
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

# Optimization level
# None (-O0)
# Moderate (-O1)
# Full (-O2)
# Maximum (-O3)
# Maximum & smallest (-Oz)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux" AND ${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
  message(STATUS "Target name: ${TARGET_NAME}, Build type: ${CMAKE_BUILD_TYPE}")  
  message(STATUS "OS: ${CMAKE_SYSTEM_NAME}")
  message(STATUS "Compiler path: ${CMAKE_CXX_COMPILER}")
  message(STATUS "Compiler ID: ${CMAKE_CXX_COMPILER_ID}")
  message(STATUS "Compiler version: ${CMAKE_CXX_COMPILER_VERSION}")    
  
  if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    target_compile_options(${TARGET_NAME} PRIVATE -g -Wall -Wextra -Werror -pedantic -O0)
  endif()

  if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
    target_compile_options(${TARGET_NAME} PRIVATE -g -Wall -Wextra -Werror -pedantic -Oz)
  endif()
   
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Windows" AND ${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
  message(STATUS "Target name: ${TARGET_NAME}, Build type: ${CMAKE_BUILD_TYPE}")  
  message(STATUS "OS: ${CMAKE_SYSTEM_NAME}")
  message(STATUS "Compiler path: ${CMAKE_CXX_COMPILER}")
  message(STATUS "Compiler ID: ${CMAKE_CXX_COMPILER_ID}")
  message(STATUS "Compiler version: ${CMAKE_CXX_COMPILER_VERSION}")  
  
  target_compile_options(${TARGET_NAME} PRIVATE /W4 /WX) 
endif()

# add_compile_options(-std=c++23 -Ofast -funroll-all-loops)
