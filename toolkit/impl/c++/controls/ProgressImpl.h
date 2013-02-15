#ifndef TERMINAL_TOOLKIT_IMPL_PROGRESS_IMPL_H_
#define TERMINAL_TOOLKIT_IMPL_PROGRESS_IMPL_H_

#include <impl/c++/controls/ControlImpl.h>

namespace terminal {
  namespace toolkit {
    namespace impl {
      class ProgressImpl : public ControlImpl {
      public:
        ProgressImpl(terminal::toolkit::container_ptr container);
        virtual ~ProgressImpl();
        
        virtual void redraw();
        virtual void update();

      private:
      };
    }
  }
}

#endif

