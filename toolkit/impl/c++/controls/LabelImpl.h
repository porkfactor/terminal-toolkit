#ifndef TERMINAL_TOOLKIT_IMPL_LABEL_IMPL_H_
#define TERMINAL_TOOLKIT_IMPL_LABEL_IMPL_H_

#include <impl/c++/controls/ControlImpl.h>
#include <string>

namespace terminal {
  namespace toolkit {
    namespace impl {
      class LabelImpl : public ControlImpl {
      public:
        LabelImpl(terminal::toolkit::container_ptr container);
        ~LabelImpl();

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

