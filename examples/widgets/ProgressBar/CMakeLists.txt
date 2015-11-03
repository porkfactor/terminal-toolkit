project(ProgressBar)

include_directories(
  ${terminal-toolkit_SOURCE_DIR}/include
)

add_executable(ProgressBar
  main.cpp
)

target_link_libraries(ProgressBar
  terminal-toolkit
)

