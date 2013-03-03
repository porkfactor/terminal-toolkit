#include <api/c++/Display.h>
#include <curses.h>

namespace terminal {
  namespace toolkit {
    Display::Display() {
      ::initscr();
      ::start_color();
    }

    Display::~Display() {
      ::endwin();
    }
  }
}
