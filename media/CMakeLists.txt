project(terminal-media)

TDUsePackage(curses)
TDUsePackage(boost)

include_directories(
  ${terminal-media_SOURCE_DIR}
  ${terminal-toolkit_SOURCE_DIR}
)

add_executable(terminal-media
  main.cpp
)

target_link_libraries(terminal-media
  terminal-toolkit
)


  
