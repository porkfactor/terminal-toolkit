#ifndef TERMINAL_TOOLKIT_WIDGET_H_
#define TERMINAL_TOOLKIT_WIDGET_H_

#include <platform/platform.hpp>
#include <api/c++/Declarations.hpp>

namespace terminal {
  namespace toolkit {
    class Event;

    class DLLEXPORT Widget {
      friend class Terminal;
      friend class Dialog;
    public:
      Widget(widget_ptr parent);
      virtual ~Widget();

      virtual void dispose();
      virtual bool isDisposed() const;

    protected:
      virtual void paint() const = 0;
      virtual void checkWidget() const;
      virtual bool handleKey(int key, Event &event);

    private:
    };
  }
}

#endif

