#ifndef TERMINAL_TOOLKIT_DISPLAY_HPP_
#define TERMINAL_TOOLKIT_DISPLAY_HPP_

#include <memory>

namespace terminal {
  namespace toolkit {
    class Control;
    class Rectangle;
    class Shell;

    class Display {
    public:
      Display();
      virtual ~Display();

      void beep() const;
      void close();
      bool readAndDispatch();
      bool sleep();
      void wake();

      Shell *getActiveShell() const;
      void setActiveShell(Shell *);

      Control *getFocusControl() const;

      Rectangle getBounds() const;
      Rectangle getClientArea() const;

      static Display *getDefault();
      static Display *getCurrent();

    protected:
      void init();
      void release();

    private:
      struct impl;
      impl *pimpl_;
    };
  }
}

#endif
