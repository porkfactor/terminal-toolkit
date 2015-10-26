#include <terminal/toolkit/KeyEvent.hpp>
#include <terminal/toolkit/Event.hpp>

namespace terminal {
  namespace toolkit {
    KeyEvent::KeyEvent(const Event &e) :
      TypedEvent(e),
      character(e.character),
      keyCode(e.keyCode),
      keyLocation(e.keyLocation),
      stateMask(e.stateMask),
      doit(e.doit)
    {
    }
  }
}

