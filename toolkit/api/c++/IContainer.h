#ifndef _TERMINAL_TOOLKIT_ICONTAINER_H
#define _TERMINAL_TOOLKIT_ICONTAINER_H

#include <api/c++/IScrollable.h>
#include <platform/platform.h>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT IContainer : public IScrollable {
    public:
      inline virtual ~IContainer() { }

      virtual window_ptr getWindow() const = 0;
    };
  }
}

#endif

