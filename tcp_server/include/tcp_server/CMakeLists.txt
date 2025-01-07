cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(app-prm VERSION 0.0.1)

find_package(Boost)

add_library(app-prm STATIC prm.cpp prm.hpp)

set_target_properties(app-prm PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

include_directories(${Boost_INCLUDE_DIRS})
link_libraries(${Boost_LIBRARIES})

target_include_directories(app-prm
  PRIVATE ${CMAKE_SOURCE_DIR}/build
)

target_link_libraries(app-prm ${Boost_LIBRARIES})

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Параметры компиляции Linux ${CMAKE_CXX_COMPILER_ID}: -g -Wall -Wextra -Werror -pedantic")
    target_compile_options(app-prm PRIVATE -g -Wall -Wextra -Werror -pedantic) 
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "Параметры компиляции Windows ${CMAKE_CXX_COMPILER_ID}: /W4 /WX")
    target_compile_options(app-prm PRIVATE /W4 /WX) 
endif()