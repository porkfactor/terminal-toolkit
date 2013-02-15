#ifndef TERMINAL_TOOLKIT_IMPL_WINDOW_IMPL_H
#define TERMINAL_TOOLKIT_IMPL_WINDOW_IMPL_H

#include <impl/c++/controls/ControlImpl.h>

struct _win;

namespace terminal {
  namespace toolkit {
    namespace impl {
      class WindowImpl : public ControlImpl {
      public:
        WindowImpl(container_ptr container);
        virtual ~WindowImpl();

        virtual void redraw();
        virtual void update();

        virtual void setBounds(const terminal::toolkit::Rectangle &bounds);
        virtual void setBounds(uint16_t x, uint16_t y, uint16_t width, uint16_t height);

      private:
        struct ::_win *window_;
      };
    }
  }
}

#endif

