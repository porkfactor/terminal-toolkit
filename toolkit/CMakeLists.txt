project(terminal-toolkit)

add_definitions(-DDLL__TERMINAL_TOOLKIT)

TDUsePackage(boost)
TDUsePackage(curses)

include_directories(
  ${terminal-toolkit_SOURCE_DIR}
)

add_library(terminal-toolkit SHARED
  api/c++/Button.h
  api/c++/Composite.h
  api/c++/Color.h
  api/c++/Control.h
  api/c++/Declarations.h
  api/c++/Dialog.h
  api/c++/Display.h
  api/c++/FileDialog.h
  api/c++/Group.h
  api/c++/Label.h
  api/c++/Layout.h
  api/c++/MessageBox.h
  api/c++/Point.h
  api/c++/Progress.h
  api/c++/Rectangle.h
  api/c++/Scrollable.h
  api/c++/ScrollBar.h
  api/c++/Shell.h
  api/c++/Text.h
  api/c++/Widget.h
  impl/c++/composites/Composite.cpp
  impl/c++/composites/Group.cpp
  impl/c++/controls/Button.cpp
  impl/c++/controls/Control.cpp
  impl/c++/controls/Label.cpp
  impl/c++/controls/Progress.cpp
  impl/c++/controls/Scrollable.cpp
  impl/c++/controls/ScrollBar.cpp
  impl/c++/controls/Text.cpp
  impl/c++/controls/Widget.cpp
  impl/c++/dialogs/Dialog.cpp
  impl/c++/dialogs/FileDialog.cpp
  impl/c++/dialogs/MessageBox.cpp
  impl/c++/layouts/Layout.cpp
  impl/c++/system/Display.cpp
  impl/c++/types/Color.cpp
  impl/c++/types/Point.cpp
  impl/c++/types/Rectangle.cpp
  impl/c++/windows/Shell.cpp
  platform/platform.h
)

source_group("api\\c++" FILES
  api/c++/Button.h
  api/c++/Composite.h
  api/c++/Color.h
  api/c++/Control.h
  api/c++/Declarations.h
  api/c++/Dialog.h
  api/c++/Display.h
  api/c++/FileDialog.h
  api/c++/Group.h
  api/c++/Label.h
  api/c++/Layout.h
  api/c++/MessageBox.h
  api/c++/Point.h
  api/c++/Progress.h
  api/c++/Rectangle.h
  api/c++/Scrollable.h
  api/c++/ScrollBar.h
  api/c++/Shell.h
  api/c++/Text.h
  api/c++/Widget.h
)

source_group("composites" FILES
  impl/c++/composites/Composite.cpp
  impl/c++/composites/Group.cpp
  impl/c++/composites/Scrollable.cpp
)

source_group("controls" FILES
  impl/c++/controls/Button.cpp
  impl/c++/controls/Control.cpp
  impl/c++/controls/Label.cpp
  impl/c++/controls/Progress.cpp
  impl/c++/controls/Scrollable.cpp
  impl/c++/controls/ScrollBar.cpp
  impl/c++/controls/Text.cpp
  impl/c++/controls/Widget.cpp
)

source_group("dialogs" FILES
  impl/c++/dialogs/Dialog.cpp
  impl/c++/dialogs/FileDialog.cpp
  impl/c++/dialogs/MessageBox.cpp
)

source_group("layouts" FILES
  impl/c++/layouts/Layout.cpp
)

source_group("system" FILES
  impl/c++/system/Display.cpp
)

source_group("types" FILES
  impl/c++/types/Color.cpp
  impl/c++/types/Point.cpp
  impl/c++/types/Rectangle.cpp
)

source_group("windows" FILES
  impl/c++/windows/Shell.cpp
)

source_group("c\\controls" FILES
)

source_group("c\\containers" FILES
)

source_group("c\\dialogs" FILES
)

source_group("c\\windows" FILES
  api/c/window.h
)

source_group("platform" FILES
  platform/platform.h
)

target_link_libraries(terminal-toolkit
  pdcurses
  panel
)

