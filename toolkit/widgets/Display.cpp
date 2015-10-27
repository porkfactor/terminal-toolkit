#include <terminal/toolkit/Display.hpp>
#include <terminal/toolkit/Rectangle.hpp>
#include <terminal/toolkit/Shell.hpp>
#include <terminal/toolkit/Event.hpp>
#include <terminal/toolkit/ttcurses.h>
#include <sys/select.h>

namespace terminal {
  namespace toolkit {
    static Display *current_ = 0;
    static Display *default_ = 0;

    struct Display::DisplayImpl {
      DisplayImpl() :
        active_(nullptr)
      {

      }

      Shell *active_;
    };

    Display::Display() :
      pimpl_(new DisplayImpl())
    {
      ::initscr();
      ::start_color();

      for(uint16_t f = 0; f < COLORS; f++) {
        for(uint16_t b = 0; b < COLORS; b++) {
          ::init_pair((f * COLORS) + b, f, b);
        }
      }
    }

    Display::~Display() {
      ::endwin();
    }

    bool Display::sleep() {
      bool rv = false;
      int fd = ::fileno(stdin);
      struct timeval tv = { 0, 0, };
      fd_set rfd;

      FD_ZERO(&rfd);
      FD_SET(fd, &rfd);

      switch(::select(fd + 1, &rfd, 0, 0, &tv)) {
      case -1:
        rv = false;
        break;

      default:
        if(FD_ISSET(fd, &rfd)) {
          rv = true;
        }
      }

      return(rv);
    }

    bool Display::readAndDispatch() {
      bool rv = true;

      int key;
      Shell *shell = getActiveShell();
      WINDOW *window = reinterpret_cast<WINDOW *>(shell->window());

      shell->redraw();

      ::timeout(-1);
      ::raw();
      ::noecho();
      ::keypad(window, TRUE);

      while(true) {
        Control *control = nullptr;
        shell->paint();

        if((control = shell->getFocusControl()) != nullptr) {
          Event event;

          if((key = ::wgetch(window)) != ERR) {
            event.keyCode = key;

            if(control->handleKeyEvent(key, event)) {

            }
          }

          // temporary bodge to catch control-c
          if(key == 0x3) {
            rv = false;
            break;
          }
        }
      }

      return(rv);
    }

    Rectangle Display::getBounds() const {
      return(Rectangle(0, 0, 0, 0));
    }

    Rectangle Display::getClientArea() const {
      return(Rectangle(0, 0, 0, 0));
    }

    Shell *Display::getActiveShell() const {
      return(pimpl_->active_);
    }

    void Display::setActiveShell(Shell *active) {
      pimpl_->active_ = active;
    }

    Control *Display::getFocusControl() const {
      return(getActiveShell()->getFocusControl());
    }

    void Display::beep() const {
      ::beep();
    }

    Display *Display::getCurrent() {
      return(current_);
    }

    Display *Display::getDefault() {
      return(default_ ? default_ : (default_ = new Display()));
    }
  }
}

