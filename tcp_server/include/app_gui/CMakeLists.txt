cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(app-gui VERSION 0.0.1)

# Find gtkmm
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

add_library(app-gui STATIC wnd.hpp wnd.cpp)

set_target_properties(app-gui PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

target_include_directories(app-gui
  PRIVATE ${CMAKE_SOURCE_DIR}/build
  PRIVATE ${GTKMM_INCLUDE_DIRS}
)

target_link_libraries(app-gui PRIVATE ${GTKMM_LIBRARIES}
)