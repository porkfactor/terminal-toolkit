#ifndef TERMINAL_TOOLKIT_SELECTIONLISTENER_HPP_
#define TERMINAL_TOOLKIT_SELECTIONLISTENER_HPP_

#include <terminal/toolkit/Listener.hpp>

namespace terminal {
  namespace toolkit {
  	class SelectionEvent;

    class SelectionListener : public Listener {
    public:
      virtual inline ~SelectionListener() { };

      virtual void widgetDefaultSelected(SelectionEvent const &) = 0;
      virtual void widgetSelected(SelectionEvent const &) = 0;
    };
  }
}

#endif
