#ifndef TERMINAL_TOOLKIT_MENULISTENER_HPP_
#define TERMINAL_TOOLKIT_MENULISTENER_HPP_

#include <terminal/toolkit/EventListener.hpp>

namespace terminal {
  namespace toolkit {
    class MenuEvent;

    class MenuListener : public EventListener {
      void menuCanceled(const MenuEvent &e);
      void menuDeselected(const MenuEvent &e);
      void menuSelected(const MenuEvent &e);
    };
  }
}

#endif
