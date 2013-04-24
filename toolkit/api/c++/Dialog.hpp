#ifndef TERMINAL_TOOLKIT_DIALOG_H_
#define TERMINAL_TOOLKIT_DIALOG_H_

#include <platform/platform.hpp>
#include <api/c++/Declarations.hpp>
#include <string>

namespace terminal {
  namespace toolkit {
    class Terminal;

    class DLLEXPORT Dialog {
    public:
      typedef enum {
        APPLICATION_MODAL, 
        PRIMARY_MODAL, 
        SYSTEM_MODAL, 
        SHEET
      } style_t;

      Dialog(shell_ptr parent);
      Dialog(shell_ptr parent, style_t style);
      virtual ~Dialog();

      shell_ptr getParent() const;
      const std::string &getText() const;
      style_t getStyle() const;

      void setText(const std::string &);

    private:
      class DialogImpl;
      DialogImpl *impl_;
    };
  }
}

#endif

