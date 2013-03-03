#ifndef TERMINAL_TOOLKIT_SHELL_H_
#define TERMINAL_TOOLKIT_SHELL_H_

#include <api/c++/Declarations.h>
#include <api/c++/Composite.h>
#include <platform/platform.h>
#include <stdint.h>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT Shell : public Composite {
    public:
      Shell();
      Shell(shell_ptr parent);
      virtual ~Shell();

      virtual void setBounds(uint16_t x, uint16_t y, uint16_t width, uint16_t height, bool defer = true);
      virtual void redraw();
      virtual void redraw(uint16_t x, uint16_t y, uint16_t width, uint16_t height, bool all);
      virtual void open();

      virtual Control::curses_window_t window() const;

    protected:
      virtual void paint() const;

    private:
      class ShellImpl;
      ShellImpl *impl_;
    };
  }
}

#endif

