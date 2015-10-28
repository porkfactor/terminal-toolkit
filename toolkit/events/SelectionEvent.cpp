#include <terminal/toolkit/SelectionEvent.hpp>

namespace terminal {
  namespace toolkit {
    SelectionEvent::SelectionEvent(Event const &e) :
      TypedEvent(e),
      height(0),
      width(0),
      y(0),
      x(0)
    {

    }
  }
}

