#ifndef TERMINAL_TOOLKIT_LISTENER_HPP_
#define TERMINAL_TOOLKIT_LISTENER_HPP_

namespace terminal {
  namespace toolkit {
    class Event;

    class Listener {
    public:
      inline virtual ~Listener() { };

      virtual void handleEvent(const Event &event) = 0;
    };
  }
}

#endif
