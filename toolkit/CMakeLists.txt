project(terminal-toolkit)

add_definitions(-DDLL__TERMINAL_TOOLKIT)

TDUsePackage(boost)
TDUsePackage(curses)

include_directories(
  ${terminal-toolkit_SOURCE_DIR}
)

add_library(terminal-toolkit SHARED
  api/c++/Button.hpp
  api/c++/Composite.hpp
  api/c++/Color.hpp
  api/c++/ColumnLayout.hpp
  api/c++/Control.hpp
  api/c++/Declarations.hpp
  api/c++/Dialog.hpp
  api/c++/Event.hpp
  api/c++/FileDialog.hpp
  api/c++/FormLayout.hpp
  api/c++/GridLayout.hpp
  api/c++/Group.hpp
  api/c++/Item.hpp
  api/c++/Label.hpp
  api/c++/Layout.hpp
  api/c++/Listener.hpp
  api/c++/MessageBox.hpp
  api/c++/Point.hpp
  api/c++/Progress.hpp
  api/c++/Rectangle.hpp
  api/c++/RowLayout.hpp
  api/c++/Scrollable.hpp
  api/c++/ScrollBar.hpp
  api/c++/Shell.hpp
  api/c++/StackLayout.hpp
  api/c++/Table.hpp
  api/c++/TableColumn.hpp
  api/c++/TableItem.hpp
  api/c++/TableLayout.hpp
  api/c++/Terminal.hpp
  api/c++/Text.hpp
  api/c++/Widget.hpp
  impl/c++/composites/Composite.cpp
  impl/c++/composites/Group.cpp
  impl/c++/composites/Item.cpp
  impl/c++/composites/Scrollable.cpp
  impl/c++/composites/Table.cpp
  impl/c++/composites/TableColumn.cpp
  impl/c++/composites/TableItem.cpp
  impl/c++/controls/Button.cpp
  impl/c++/controls/Control.cpp
  impl/c++/controls/Event.cpp
  impl/c++/controls/Label.cpp
  impl/c++/controls/Listener.cpp
  impl/c++/controls/Progress.cpp
  impl/c++/controls/Scrollable.cpp
  impl/c++/controls/ScrollBar.cpp
  impl/c++/controls/Text.cpp
  impl/c++/controls/Widget.cpp
  impl/c++/dialogs/Dialog.cpp
  impl/c++/dialogs/FileDialog.cpp
  impl/c++/dialogs/MessageBox.cpp
  impl/c++/layouts/ColumnLayout.cpp
  impl/c++/layouts/FormLayout.cpp
  impl/c++/layouts/GridLayout.cpp
  impl/c++/layouts/Layout.cpp
  impl/c++/layouts/RowLayout.cpp
  impl/c++/layouts/StackLayout.cpp
  impl/c++/layouts/TableLayout.cpp
  impl/c++/system/Terminal.cpp
  impl/c++/types/Color.cpp
  impl/c++/types/Point.cpp
  impl/c++/types/Rectangle.cpp
  impl/c++/windows/Shell.cpp
  platform/platform.hpp
)

source_group("api\\c++" FILES
  api/c++/Button.hpp
  api/c++/Composite.hpp
  api/c++/Color.hpp
  api/c++/ColumnLayout.hpp
  api/c++/Control.hpp
  api/c++/Declarations.hpp
  api/c++/Dialog.hpp
  api/c++/Event.hpp
  api/c++/FileDialog.hpp
  api/c++/FormLayout.hpp
  api/c++/GridLayout.hpp
  api/c++/Group.hpp
  api/c++/Item.hpp
  api/c++/Label.hpp
  api/c++/Layout.hpp
  api/c++/Listener.hpp
  api/c++/MessageBox.hpp
  api/c++/Point.hpp
  api/c++/Progress.hpp
  api/c++/Rectangle.hpp
  api/c++/RowLayout.hpp
  api/c++/Scrollable.hpp
  api/c++/ScrollBar.hpp
  api/c++/Shell.hpp
  api/c++/StackLayout.hpp
  api/c++/Table.hpp
  api/c++/TableColumn.hpp
  api/c++/TableItem.hpp
  api/c++/TableLayout.hpp
  api/c++/Terminal.hpp
  api/c++/Text.hpp
  api/c++/Widget.hpp
)

source_group("composites" FILES
  impl/c++/composites/Composite.cpp
  impl/c++/composites/Group.cpp
  impl/c++/composites/Item.cpp
  impl/c++/composites/Table.cpp
  impl/c++/composites/TableColumn.cpp
  impl/c++/composites/TableItem.cpp
)

source_group("controls" FILES
  impl/c++/controls/Button.cpp
  impl/c++/controls/Control.cpp
  impl/c++/controls/Event.cpp
  impl/c++/controls/Label.cpp
  impl/c++/controls/Listener.cpp
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
  impl/c++/layouts/ColumnLayout.cpp
  impl/c++/layouts/FormLayout.cpp
  impl/c++/layouts/GridLayout.cpp
  impl/c++/layouts/Layout.cpp
  impl/c++/layouts/RowLayout.cpp
  impl/c++/layouts/StackLayout.cpp
  impl/c++/layouts/TableLayout.cpp
)

source_group("system" FILES
  impl/c++/system/Terminal.cpp
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
  api/c/window.hpp
)

source_group("platform" FILES
  platform/platform.hpp
)

target_link_libraries(terminal-toolkit
  pdcurses
  panel
)

