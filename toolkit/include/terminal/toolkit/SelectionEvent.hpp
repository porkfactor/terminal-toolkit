#ifndef TERMINAL_TOOLKIT_SELECTIONEVENT_HPP_
#define TERMINAL_TOOLKIT_SELECTIONEVENT_HPP_

#include <terminal/toolkit/TypedEvent.hpp>
#include <cstdint>

namespace terminal {
  namespace toolkit {
    class SelectionEvent : public TypedEvent {
    public:
      SelectionEvent(Event const &e);
      SelectionEvent(uint32_t x, uint32_t y, uint32_t width, uint32_t height);

      uint32_t x;
      uint32_t y;
      uint32_t width;
      uint32_t height;
    };
  }
}



#endif
