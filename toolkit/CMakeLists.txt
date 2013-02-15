project(terminal-toolkit)

add_definitions(-DDLL__TERMINAL_TOOLKIT)

TDUsePackage(boost)
TDUsePackage(curses)

include_directories(
  ${terminal-toolkit_SOURCE_DIR}
)

add_library(terminal-toolkit SHARED
  api/c++/Declarations.h
  api/c++/IComponent.h
  api/c++/IContainer.h
  api/c++/IControl.h
  api/c++/IDialog.h
  api/c++/IScrollable.h
  api/c++/containers/GroupBox.h
  api/c++/controls/Button.h
  api/c++/controls/Label.h
  api/c++/controls/Progress.h
  api/c++/controls/Text.h
  api/c++/dialogs/FileDialog.h
  api/c++/dialogs/MessageBox.h
  api/c++/types/Rectangle.h
  api/c++/windows/Window.h
  impl/c++/containers/ContainerImpl.h
  impl/c++/containers/ContainerImpl.cpp
  impl/c++/containers/GroupBox.cpp
  impl/c++/containers/GroupBoxImpl.h
  impl/c++/containers/GroupBoxImpl.cpp
  impl/c++/controls/Button.cpp
  impl/c++/controls/ButtonImpl.h
  impl/c++/controls/ButtonImpl.cpp
  impl/c++/controls/ControlImpl.h
  impl/c++/controls/ControlImpl.cpp
  impl/c++/controls/Label.cpp
  impl/c++/controls/LabelImpl.h
  impl/c++/controls/LabelImpl.cpp
  impl/c++/controls/Progress.cpp
  impl/c++/controls/ProgressImpl.h
  impl/c++/controls/ProgressImpl.cpp
  impl/c++/controls/Text.cpp
  impl/c++/controls/TextImpl.h
  impl/c++/controls/TextImpl.cpp
  impl/c++/dialogs/FileDialog.cpp
  impl/c++/dialogs/MessageBox.cpp
  impl/c++/types/Rectangle.cpp
  impl/c++/windows/Window.cpp
  impl/c++/windows/WindowImpl.h
  impl/c++/windows/WindowImpl.cpp
  platform/platform.h
)

source_group("api\\c++" FILES
  api/c++/Declarations.h
  api/c++/IComponent.h
  api/c++/IContainer.h
  api/c++/IControl.h
  api/c++/IDialog.h
  api/c++/IScrollable.h
)

source_group("api\\c++\\containers" FILES
  api/c++/containers/GroupBox.h
)

source_group("api\\c++\\controls" FILES
  api/c++/controls/Button.h
  api/c++/controls/Label.h
  api/c++/controls/Progress.h
  api/c++/controls/Text.h
)

source_group("api\\c++\\dialogs" FILES
  api/c++/dialogs/FileDialog.h
  api/c++/dialogs/MessageBox.h
)

source_group("api\\c++\\types" FILES
  api/c++/types/Rectangle.h
)

source_group("api\\c++\\windows" FILES
  api/c++/windows/Window.h
)

source_group("containers" FILES
  impl/c++/containers/ContainerImpl.h
  impl/c++/containers/ContainerImpl.cpp
  impl/c++/containers/GroupBox.cpp
  impl/c++/containers/GroupBoxImpl.h
  impl/c++/containers/GroupBoxImpl.cpp
)

source_group("controls" FILES
  impl/c++/controls/Button.cpp
  impl/c++/controls/ButtonImpl.h
  impl/c++/controls/ButtonImpl.cpp
  impl/c++/controls/ControlImpl.h
  impl/c++/controls/ControlImpl.cpp
  impl/c++/controls/Label.cpp
  impl/c++/controls/LabelImpl.h
  impl/c++/controls/LabelImpl.cpp
  impl/c++/controls/Progress.cpp
  impl/c++/controls/ProgressImpl.h
  impl/c++/controls/ProgressImpl.cpp
  impl/c++/controls/Text.cpp
  impl/c++/controls/TextImpl.h
  impl/c++/controls/TextImpl.cpp
)

source_group("dialogs" FILES
  impl/c++/dialogs/FileDialog.cpp
  impl/c++/dialogs/FileDialogImpl.h
  impl/c++/dialogs/FileDialogImpl.cpp
  impl/c++/dialogs/MessageBox.cpp
  impl/c++/dialogs/MessageBoxImpl.h
  impl/c++/dialogs/MessageBoxImpl.cpp
)

source_group("types" FILES
  impl/c++/types/Rectangle.cpp
)

source_group("windows" FILES
  impl/c++/windows/Window.cpp
  impl/c++/windows/WindowImpl.h
  impl/c++/windows/WindowImpl.cpp
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

