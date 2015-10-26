#ifndef TERMINAL_TOOLKIT_COMPONENTEVENT_HPP_
#define TERMINAL_TOOLKIT_COMPONENTEVENT_HPP_

namespace terminal {
  namespace toolkit {
    class Component;

    class ComponentEvent {
    public:
      ComponentEvent(Component *, int);

      Component *getComponent() const;

    private:
      Component *component_;
    };
  }
}

#endif
