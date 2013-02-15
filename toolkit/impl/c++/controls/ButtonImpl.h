#ifndef TERMINAL_TOOLKIT_IMPL_BUTTON_IMPL_H
#define TERMINAL_TOOLKIT_IMPL_BUTTON_IMPL_H

#include <impl/c++/controls/ControlImpl.h>
#include <string>

namespace terminal {
  namespace toolkit {
    namespace impl {
      class ButtonImpl : public ControlImpl {
      public:
        ButtonImpl(terminal::toolkit::container_ptr container);
        virtual ~ButtonImpl();

        const std::string &getText() const;
        void setText(const std::string &text);

        virtual void redraw();
        virtual void update();

      private:
        std::string text_;
      };
    }
  }
}

#endif

