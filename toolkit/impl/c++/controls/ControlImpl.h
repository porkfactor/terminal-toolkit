#ifndef TERMINAL_TOOLKIT_IMPL_CONTROL_IMPL_H
#define TERMINAL_TOOLKIT_IMPL_CONTROL_IMPL_H

#include <api/c++/Declarations.h>
#include <api/c++/IControl.h>
#include <api/c++/types/Rectangle.h>
#include <stdint.h>

namespace terminal {
  namespace toolkit {
    namespace impl {
      class ControlImpl {
      public:
        ControlImpl(terminal::toolkit::container_ptr container);
        virtual ~ControlImpl();

        virtual void redraw() = 0;
        virtual void update() = 0;

        virtual void setEnabled(bool enabled);
        virtual bool setFocus();
        virtual void setBounds(const terminal::toolkit::Rectangle &bounds);
        virtual void setBounds(uint16_t x, uint16_t y, uint16_t width, uint16_t height);
        virtual const terminal::toolkit::Rectangle &getBounds() const;
        virtual window_ptr getWindow() const;
        terminal::toolkit::IControl::handle_t handle() const;

      private:
        terminal::toolkit::container_ptr container_;
        terminal::toolkit::Rectangle bounds_;
      };
    }
  }
}

#endif
