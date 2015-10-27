cmake_minimum_required(VERSION 2.8.7)
project(terminal)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

LIST(APPEND CMAKE_MODULE_PATH 
  ${terminal_SOURCE_DIR}/cmake 
  ${terminal_SOURCE_DIR}/cmake/Config
)

include(TerminalCommon)
include(Install)

add_subdirectory(toolkit)
