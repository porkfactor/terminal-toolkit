#ifndef TERMINAL_TOOLKIT_LAYOUT_H_
#define TERMINAL_TOOLKIT_LAYOUT_H_

#include <api/c++/Declarations.hpp>
#include <api/c++/Point.hpp>
#include <platform/platform.hpp>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT Layout {
    public:
      Layout();
      virtual ~Layout();

    protected:
      virtual Point computeSize(composite_ptr composite, uint16_t width, uint16_t height, bool flushCache) = 0;
      virtual bool flushCache(control_ptr control);
      virtual void layout(composite_ptr composite, bool flushCache) = 0;

    private:
      class LayoutImpl;
      LayoutImpl *impl_;
    };
  }
}

#endif

