#include <api/c++/Terminal.hpp>
#include <api/c++/Declarations.hpp>
#include <api/c++/Widget.hpp>
#include <api/c++/Event.hpp>
#include <api/c++/Shell.hpp>
#include <api/c++/Rectangle.hpp>
#include <curses.h>
#include <vector>

namespace terminal {
  namespace toolkit {
    class Terminal::TerminalImpl {
    public:

      shell_ptr focus_;
      std::vector<shell_ptr> children_;
    };

    Terminal::Terminal() :
      impl_(new TerminalImpl())
    {
      ::initscr();
      ::start_color();

      for(uint16_t f = 0; f < COLORS; f++) {
        for(uint16_t b = 0; b < COLORS; b++) {
          init_pair(f * COLORS + b, f, b);
        }
      }
    }

    Terminal::~Terminal() {
      ::endwin();
      delete impl_;
    }

    bool Terminal::readAndDispatch() {
      bool rv = false;

      {
        int key;
        ::timeout(-1);
        shell_ptr shell = impl_->focus_;
        WINDOW *window = reinterpret_cast<WINDOW *>(shell->window());
        std::vector<control_ptr> v;
        shell->getTabList(v);
        control_ptr control = v.front();

        control->forceFocus();

        ::raw();
        ::noecho();
        ::keypad(window, TRUE);

        while(true) {
          if((key = ::wgetch(window)) != ERR) {
            Event event;

            if(key == 3)
              exit(0);
          
            if(control->handleKey(key, event)) {
            }
          }
        }
      }

      return(rv);
    }

    void Terminal::addShell(shell_ptr child) {
      if(child) {
        impl_->children_.push_back(child);
        impl_->focus_ = child;
      }
    }
  }
}
