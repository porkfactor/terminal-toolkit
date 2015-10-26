#include <terminal/toolkit/TypedEvent.hpp>
#include <terminal/toolkit/Event.hpp>

namespace terminal {
  namespace toolkit {
    TypedEvent::TypedEvent(const Event &e) :
      widget(e.widget),
      display(e.display)
    {

    }
  }
}


