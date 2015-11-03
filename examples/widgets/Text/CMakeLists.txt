project(Text)

include_directories(
  ${terminal-toolkit_SOURCE_DIR}/include
)

add_executable(Text
  main.cpp
)

target_link_libraries(Text
  terminal-toolkit
)

