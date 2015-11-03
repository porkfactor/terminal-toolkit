project(Button)

include_directories(
  ${terminal-toolkit_SOURCE_DIR}/include
)

add_executable(Button
  main.cpp
)

target_link_libraries(Button
  terminal-toolkit
)

