#include <terminal/toolkit/InputEvent.hpp>

namespace terminal {
  namespace toolkit {
    InputEvent::InputEvent(Component *component) :
      ComponentEvent(component, 0)
    {

    }

    void InputEvent::consume() {

    }

    bool InputEvent::isAltDown() const {
      return(false);
    }

    bool InputEvent::isControlDown() const {
      return(false);
    }

    bool InputEvent::isMetaDown() const {
      return(false);
    }

    bool InputEvent::isShiftDown() const {
      return(false);
    }
  }
}
