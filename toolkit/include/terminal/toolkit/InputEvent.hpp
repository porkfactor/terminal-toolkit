#ifndef TERMINAL_TOOLKIT_INPUTEVENT_HPP_
#define TERMINAL_TOOLKIT_INPUTEVENT_HPP_

#include <terminal/toolkit/ComponentEvent.hpp>

namespace terminal {
  namespace toolkit {
    class InputEvent : public ComponentEvent {
    public:
      InputEvent(Component *);

      void consume();
      bool isAltDown() const;
      bool isControlDown() const;
      bool isMetaDown() const;
      bool isShiftDown() const;
    };
  }
}

#endif
