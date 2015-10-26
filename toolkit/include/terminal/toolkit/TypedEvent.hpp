#ifndef TERMINAL_TOOLKIT_TYPEDEVENT_HPP_
#define TERMINAL_TOOLKIT_TYPEDEVENT_HPP_

namespace terminal {
  namespace toolkit {
    class Display;
    class Event;
    class Widget;

    class TypedEvent {
    public:
      TypedEvent(const Event &e);

      Display *display;
      Widget *widget;
    };
  }
}

#endif
