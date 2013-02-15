#ifndef _TERMINAL_TOOLKIT_DECLARATIONS_H
#define _TERMINAL_TOOLKIT_DECLARATIONS_H

#ifdef USE_SMART_POINTERS
#include <memory>
#define POINTER(x) std::tr1::shared_ptr<x>
#else
#define POINTER(x) x *
#endif

namespace terminal {
  namespace toolkit {
    class IComponent;
    class IControl;
    class IContainer;
    class Rectangle;
    class Window;

    typedef POINTER(IComponent) component_ptr;
    typedef POINTER(IControl) control_ptr;
    typedef POINTER(IContainer) container_ptr;
    typedef POINTER(Window) window_ptr;
  }
}

#endif

