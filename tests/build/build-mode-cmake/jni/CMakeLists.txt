cmake_minimum_required(VERSION 3.6)

configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
)

include_directories("${PROJECT_BINARY_DIR}")

add_executable(main "main.c")
