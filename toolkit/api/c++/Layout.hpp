#ifndef TERMINAL_TOOLKIT_LAYOUT_H_
#define TERMINAL_TOOLKIT_LAYOUT_H_

#include <api/c++/Declarations.h>
#include <api/c++/Point.h>
#include <platform/platform.h>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT Layout {
    public:
      Layout();
      virtual ~Layout();

    protected:
      Point computeSize(composite_ptr composite, uint16_t width, uint16_t height, bool flushCache);
      bool flushCache(control_ptr control);
      void layout(composite_ptr composite, bool flushCache);

    private:
      class LayoutImpl;
      LayoutImpl *impl_;
    };
  }
}

#endif

