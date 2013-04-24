#ifndef TERMINAL_TOOLKIT_FILE_DIALOG_H_
#define TERMINAL_TOOLKIT_FILE_DIALOG_H_

#include <api/c++/Declarations.hpp>
#include <api/c++/Dialog.hpp>
#include <platform/platform.hpp>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT FileDialog : public Dialog {
    public:
      FileDialog(shell_ptr parent);
      FileDialog(shell_ptr parent, Dialog::style_t style);
      ~FileDialog();

      void open();

      void getSelectedFile();

      void setInitialDirectory(const std::string &directory);

    private:
      class FileDialogImpl;
      FileDialogImpl *impl_;
    };
  }
}

#endif

