#include <api/c++/Display.h>
#include <api/c++/Declarations.h>
#include <api/c++/Widget.h>
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

    bool Display::readAndDispatch() {
      bool rv = false;

      {
        int key;
        ::timeout(-1);
  
        if((key = ::getch()) != ERR) {
          widget_ptr widget;
          event_ptr event;

          if(event = widget->handleKey(key)) {
          }
        }
      }

      return(rv);
    }
  }
}
