#ifndef _TERMINAL_TOOLKIT_ISCOLLABLE_H
#define _TERMINAL_TOOLKIT_ISCOLLABLE_H

#include <api/c++/IControl.h>
#include <platform/platform.h>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT IScrollable : public IControl {
    public:
      inline virtual ~IScrollable() { }
    };
  }
}

#endif

