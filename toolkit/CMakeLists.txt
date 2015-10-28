project(terminal-toolkit)

add_definitions(-DDLL__TERMINAL_TOOLKIT)

TTUsePackage(curses)
TTUsePackage(boost)

include_directories(
  ${terminal-toolkit_SOURCE_DIR}/include
)

add_library(terminal-toolkit SHARED
  composites/Composite.cpp
  composites/Shell.cpp
  composites/TabFolder.cpp
  composites/Table.cpp
  dialogs/Dialog.cpp
  dialogs/FileDialog.cpp
  dialogs/MessageBox.cpp
  events/ArmEvent.cpp
  events/ComponentEvent.cpp
  events/Event.cpp
  events/InputEvent.cpp
  events/KeyEvent.cpp
  events/FocusEvent.cpp
  events/HelpEvent.cpp
  events/MenuEvent.cpp
  events/PaintEvent.cpp
  events/SelectionEvent.cpp
  events/TypedEvent.cpp
  listeners/EventListener.cpp
  widgets/Button.cpp
  widgets/Color.cpp
  widgets/Combo.cpp
  widgets/Control.cpp
  widgets/Display.cpp
  widgets/Item.cpp
  widgets/Label.cpp
  widgets/List.cpp
  widgets/Menu.cpp
  widgets/MenuItem.cpp
  widgets/Point.cpp
  widgets/Rectangle.cpp
  widgets/Scrollable.cpp
  widgets/ScrollBar.cpp
  widgets/TabItem.cpp
  widgets/TableColumn.cpp
  widgets/TableItem.cpp
  widgets/Text.cpp
  widgets/Widget.cpp
)

source_group("api\\c++" FILES
)

source_group("composites" FILES
)

source_group("controls" FILES
)

source_group("dialogs" FILES
)

source_group("layouts" FILES
)

source_group("system" FILES
)

source_group("types" FILES
)

source_group("windows" FILES
)

source_group("c\\controls" FILES
)

source_group("c\\containers" FILES
)

source_group("c\\dialogs" FILES
)

source_group("c\\windows" FILES
)

source_group("platform" FILES
)

target_link_libraries(terminal-toolkit
  ${curses_LIBS}
)

