#ifndef TERMINAL_TOOLKIT_SELECTIONLISTENER_HPP_
#define TERMINAL_TOOLKIT_SELECTIONLISTENER_HPP_

#include <terminal/toolkit/Listener.hpp>

namespace terminal {
  namespace toolkit {
  	class SelectionEvent;

    class SelectionListener : public Listener {
    public:
      virtual inline ~SelectionListener() { };

      virtual void widgetDefaultSelected(SelectionEvent *) = 0;
      virtual void widgetSelected(SelectionEvent *) = 0;
    };
  }
}

#endif
