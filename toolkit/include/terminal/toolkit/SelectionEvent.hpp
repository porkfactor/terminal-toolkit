#ifndef TERMINAL_TOOLKIT_SELECTIONEVENT_HPP_
#define TERMINAL_TOOLKIT_SELECTIONEVENT_HPP_

#include <terminal/toolkit/TypedEvent.hpp>

namespace terminal {
  namespace toolkit {
    class SelectionEvent : public TypedEvent {
    public:
      SelectionEvent(Event const &e);

      uint32_t x;
      uint32_t y;
      uint32_t width;
      uint32_t height;
    };
  }
}



#endif
