#ifndef TERMINAL_TOOLKIT_FOCUSLISTENER_HPP_
#define TERMINAL_TOOLKIT_FOCUSLISTENER_HPP_

#include <terminal/toolkit/EventListener.hpp>

namespace terminal {
  namespace toolkit {
    class FocusListener : public EventListener {
    public:
      inline virtual ~FocusListener() { }

      void focusGained(const FocusEvent &) = 0;
      void focusLost(const FocusEvent &) = 0;
    };
  }
}

#endif
