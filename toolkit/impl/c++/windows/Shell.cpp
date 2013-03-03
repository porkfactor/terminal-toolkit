#include <api/c++/Shell.h>
#include <api/c++/Rectangle.h>
#include <curses.h>

namespace terminal {
  namespace toolkit {
    class Shell::ShellImpl {
    public:
      ShellImpl() {
        window_ = ::newwin(0, 0, 0, 0);
      }

      ShellImpl(shell_ptr parent) {
        window_ = ::subwin(reinterpret_cast<WINDOW *>(parent->window()), 0, 0, 0, 0);
      }

      virtual ~ShellImpl() {
        delwin(window_);
      }

      inline WINDOW *window() const {
        return(window_);
      }

    private:
      WINDOW *window_;
    };

    Shell::Shell(shell_ptr parent) :
      Composite(parent),
      impl_(new ShellImpl(parent))
    {
    }

    Shell::Shell() :
      Composite(0),
      impl_(new ShellImpl())
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
      ::wrefresh(impl_->window());
    }

    void Shell::setBounds(uint16_t x, uint16_t y, uint16_t width, uint16_t height, bool defer) {
      // TODO: atomicize
      ::wmove(impl_->window(), x, y);
      ::wresize(impl_->window(), height, width);
    }

    void Shell::redraw(uint16_t x, uint16_t y, uint16_t width, uint16_t height, bool all) {
      ::wrefresh(impl_->window());
    }

    void Shell::paint() const {
    }

    Control::curses_window_t Shell::window() const {
      return(reinterpret_cast<Control::curses_window_t>(impl_->window()));
    }
  }
}


