#ifndef TERMINAL_TOOLKIT_IMPL_TEXT_IMPL_H
#define TERMINAL_TOOLKIT_IMPL_TEXT_IMPL_H

#include <impl/c++/controls/ControlImpl.h>
#include <string>

namespace terminal {
  namespace toolkit {
    namespace impl {
      class TextImpl : public ControlImpl {
      public:
        TextImpl(terminal::toolkit::container_ptr container);
        virtual ~TextImpl();

        const std::string &getText() const;
        void setText(const std::string &);

        virtual void redraw();
        virtual void update();

      private:
        std::string text_;
      };
    }
  }
}

#endif

