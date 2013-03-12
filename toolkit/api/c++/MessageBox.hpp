#ifndef TERMINAL_TOOLKIT_MESSAGE_BOX_H_
#define TERMINAL_TOOLKIT_MESSAGE_BOX_H_

#include <platform/platform.h>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT MessageBox {
    public:
      virtual ~MessageBox();

    private:
      struct pimpl;
      pimpl *impl_;
    };
  }
}

#endif

