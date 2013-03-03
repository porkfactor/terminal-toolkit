#ifndef TERMINAL_TOOLKIT_FILE_DIALOG_H_
#define TERMINAL_TOOLKIT_FILE_DIALOG_H_

#include <api/c++/Declarations.h>
#include <api/c++/Dialog.h>
#include <platform/platform.h>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT FileDialog : public Dialog {
    public:
      FileDialog();
      ~FileDialog();

    private:
      struct pimpl;
      pimpl *impl_;
    };
  }
}

#endif

