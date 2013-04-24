#ifndef TERMINAL_TOOLKIT_TERMINAL_H_
#define TERMINAL_TOOLKIT_TERMINAL_H_

#include <api/c++/Declarations.hpp>
#include <platform/platform.hpp>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT Terminal {
      friend class Shell;
    public:
      Terminal();
      ~Terminal();

      void beep();
      bool readAndDispatch();
      void close();

    protected:
      void init();
      void addShell(shell_ptr child);

    private:
      class TerminalImpl;
      TerminalImpl *impl_;
    };
  }
}

#endif
