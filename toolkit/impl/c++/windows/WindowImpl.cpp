#include <impl/c++/windows/WindowImpl.h>
#include <curses.h>

namespace terminal {
  namespace toolkit {
    namespace impl {
      WindowImpl::WindowImpl(terminal::toolkit::container_ptr container) :
        ControlImpl(container)
      {
        static bool init = false;

        if(!init) {
          init = true;
          ::initscr();
        }

        window_ = newwin(0, 0, 0, 0);
      }

      WindowImpl::~WindowImpl() {
        ::delwin(window_);
      }

      void WindowImpl::setBounds(const Rectangle &bounds) {
        ControlImpl::setBounds(bounds);

        ::mvwin(window_, bounds.y(), bounds.x());
        ::resize_window(window_, bounds.height(), bounds.width());
      }

      void WindowImpl::setBounds(uint16_t x, uint16_t y, uint16_t width, uint16_t height) {
        setBounds(Rectangle(x, y, width, height));
      }

      void WindowImpl::redraw() {
      }

      void WindowImpl::update() {
        wrefresh(window_);
      }
    }
  }
}

