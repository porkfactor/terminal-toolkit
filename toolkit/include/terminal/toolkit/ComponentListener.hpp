#ifndef TERMINAL_TOOLKIT_COMPONENTLISTENER_HPP_
#define TERMINAL_TOOLKIT_COMPONENTLISTENER_HPP_

namespace terminal {
  namespace toolkit {
    class ComponentListener : public EventListener {
    public:
      inline virtual ~ComponentListener() { }

      void componentHidden(ComponentEvent *) = 0;
      void componentMoved(ComponentEvent *) = 0;
      void componentResized(ComponentEvent *) = 0;
      void componentShown(ComponentEvent *) = 0;
    };
  }
}

#endif
