#ifndef TERMINAL_TOOLKIT_SHELL_H_
#define TERMINAL_TOOLKIT_SHELL_H_

#include <api/c++/Declarations.hpp>
#include <api/c++/Composite.hpp>
#include <platform/platform.hpp>
#include <stdint.h>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT Shell : public Composite {
    public:
      Shell(shell_ptr parent);
      Shell(terminal_ptr terminal, shell_ptr parent = 0);
      virtual ~Shell();

      virtual void setBounds(uint16_t x, uint16_t y, uint16_t width, uint16_t height, bool defer = true);
      virtual void redraw();
      virtual void redraw(uint16_t x, uint16_t y, uint16_t width, uint16_t height, bool all);
      virtual void open();

      virtual Control::curses_window_t window() const;

      virtual void paint() const;

    private:
      class ShellImpl;
      ShellImpl *impl_;
    };
  }
}

#endif

