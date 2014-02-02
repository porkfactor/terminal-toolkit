#ifndef _TERMINAL_TOOLKIT_DECLARATIONS_H
#define _TERMINAL_TOOLKIT_DECLARATIONS_H

#ifdef USE_SMART_POINTERS
#include <memory>
#define POINTER(x) std::tr1::shared_ptr<x>
#else
#define POINTER(x) x *
#endif

namespace terminal {
  namespace toolkit {
    class Control;
    class Composite;
    class Event;
    class Layout;
    class Rectangle;
    class Scrollable;
    class ScrollBar;
    class Shell;
    class Table;
    class TableColumn;
    class TableItem;
    class Terminal;
    class Widget;

    typedef POINTER(Control) control_ptr;
    typedef POINTER(Composite) composite_ptr;
    typedef POINTER(Terminal) terminal_ptr;
    typedef POINTER(Event) event_ptr;
    typedef POINTER(Layout) layout_ptr;
    typedef POINTER(ScrollBar) scrollbar_ptr;
    typedef POINTER(Shell) shell_ptr;
    typedef POINTER(Table) table_ptr;
    typedef POINTER(TableColumn) table_column_ptr;
    typedef POINTER(TableItem) table_item_ptr;
    typedef POINTER(Terminal) terminal_ptr;
    typedef POINTER(Widget) widget_ptr;
  }
}

#endif

