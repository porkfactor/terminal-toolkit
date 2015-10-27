project(MessageBox)

include_directories(
  ${terminal-toolkit_SOURCE_DIR}/include
)

add_executable(MessageBox 
  main.cpp
)

target_link_libraries(MessageBox
  terminal-toolkit
)

