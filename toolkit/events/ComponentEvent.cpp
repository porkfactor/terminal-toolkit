#include <terminal/toolkit/ComponentEvent.hpp>

namespace terminal {
  namespace toolkit {
    ComponentEvent::ComponentEvent(Component *component, int) :
      component_(component)
    {

    }
  }
}
