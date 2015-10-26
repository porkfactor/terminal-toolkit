#ifndef TERMINAL_TOOLKIT_MESSAGEBOX_HPP_
#define TERMINAL_TOOLKIT_MESSAGEBOX_HPP_

#include <terminal/toolkit/Dialog.hpp>

namespace terminal {
  namespace toolkit {
    class MessageBox : public Dialog {
    public:
      MessageBox(Shell *, button_t = MSG_OK, icon_t = ICON_INFORMATION);
      virtual ~MessageBox();

      virtual int open();
      virtual const std::wstring &getMessage() const;
      virtual void setMessage(const std::wstring &);

    private:
      struct MessageBoxImpl;
      std::unique_ptr<struct MessageBoxImpl> pimpl_;
    };
  }
}

#endif
