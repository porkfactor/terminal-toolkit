#include <impl/c++/containers/ContainerImpl.h>

namespace terminal {
  namespace toolkit {
    namespace impl {
      ContainerImpl::ContainerImpl(terminal::toolkit::container_ptr container) :
        ControlImpl(container)
      {
      }

      ContainerImpl::~ContainerImpl() {
      }
    }
  }
}
