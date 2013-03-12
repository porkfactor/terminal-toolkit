#ifndef TERMINAL_TOOLKIT_DISPLAY_H_
#define TERMINAL_TOOLKIT_DISPLAY_H_

#include <platform/platform.h>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT Display {
    public:
      Display();
      ~Display();

      void beep();
      bool readAndDispatch();
      void close();

    protected:
      void init();

    private:
      class DisplayImpl;
      DisplayImpl *impl_;
    };
  }
}

#endif
