#ifndef _TERMINAL_TOOLKIT_FILE_DIALOG_H
#define _TERMINAL_TOOLKIT_FILE_DIALOG_H

#include <api/c++/Declarations.h>
#include <api/c++/IDialog.h>

namespace terminal {
  namespace toolkit {
    class FileDialog : public IDialog {
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

