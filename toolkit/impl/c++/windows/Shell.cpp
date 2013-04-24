#include <api/c++/Shell.hpp>
#include <api/c++/Rectangle.hpp>
#include <api/c++/Terminal.hpp>
#include <curses.h>

namespace terminal {
  namespace toolkit {
    class Shell::ShellImpl {
    public:
      ShellImpl(terminal_ptr terminal, shell_ptr parent) :
        terminal_(terminal),
        parent_(parent)
      {
        if(parent) {
          window_ = ::subwin(reinterpret_cast<WINDOW *>(parent->window()), 0, 0, 0, 0);
        } else {
          window_ = ::newwin(0, 0, 0, 0);
        }
      }

      virtual ~ShellImpl() {
        delwin(window_);
      }

      shell_ptr parent_;
      terminal_ptr terminal_;
      WINDOW *window_;
    };

    Shell::Shell(terminal_ptr terminal, shell_ptr parent) :
      Composite(parent),
      impl_(new ShellImpl(terminal, parent))
    {
      if(terminal) {
        terminal->addShell(this);
      }
    }

    Shell::Shell(shell_ptr parent) :
      Composite(parent),
      impl_(new ShellImpl(0, parent))
    {

    }

    Shell::~Shell() {
      delete impl_;
    }

    void Shell::redraw() {
      Rectangle rect(getBounds());

      redraw(rect.x(), rect.y(), rect.width(), rect.height(), true);
    }

    void Shell::open() {
      ::wrefresh(impl_->window_);
    }

    void Shell::setBounds(uint16_t x, uint16_t y, uint16_t width, uint16_t height, bool defer) {
      // TODO: atomicize
      ::wmove(impl_->window_, x, y);
      ::wresize(impl_->window_, height, width);
    }

    void Shell::redraw(uint16_t x, uint16_t y, uint16_t width, uint16_t height, bool all) {
      paint();
    }

    void Shell::paint() const {
      Composite::paint();
      ::wrefresh(impl_->window_);
    }

    Control::curses_window_t Shell::window() const {
      return(reinterpret_cast<Control::curses_window_t>(impl_->window_));
    }
  }
}


