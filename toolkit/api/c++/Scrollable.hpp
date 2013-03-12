#ifndef TERMINAL_TOOLKIT_SCROLLABLE_H_
#define TERMINAL_TOOLKIT_SCROLLABLE_H_

#include <api/c++/Control.h>
#include <platform/platform.h>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT Scrollable : public Control {
    public:
      Scrollable(composite_ptr parent);
      virtual ~Scrollable();

      Rectangle computeTrim(uint16_t x, uint16_t y, uint16_t width, uint16_t height);
      Rectangle getClientArea();
      scrollbar_ptr getHorizontalBar() const;
      scrollbar_ptr getVerticalBar() const;

    private:
      class ScrollableImpl;
      ScrollableImpl *impl_;
    };
  }
}

#endif

