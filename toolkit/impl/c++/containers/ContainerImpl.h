#ifndef TERMINAL_TOOLKIT_IMPL_CONTAINER_IMPL_H_
#define TERMINAL_TOOLKIT_IMPL_CONTAINER_IMPL_H_

#include <impl/c++/controls/ControlImpl.h>

namespace terminal {
  namespace toolkit {
    namespace impl {
      class ContainerImpl : public ControlImpl {
      public:
        ContainerImpl(terminal::toolkit::container_ptr container);
        virtual ~ContainerImpl();
      };
    }
  }
}

#endif

