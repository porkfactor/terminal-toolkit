#ifndef TERMINAL_TOOLKIT_SCROLL_BAR_H_
#define TERMINAL_TOOLKIT_SCROLL_BAR_H_

#include <api/c++/Control.h>
#include <platform/platform.h>
#include <stdint.h>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT ScrollBar : public Control {
    public:
      ScrollBar(composite_ptr parent);
      virtual ~ScrollBar();

      uint16_t getIncrement() const;
      uint16_t getPageIncrement() const;
      uint16_t getMinimum() const;
      uint16_t getMaximum() const;
      uint16_t getSelection() const;
      uint16_t getThumb() const;

      void setIncrement(uint16_t increment);
      void setPageIncrement(uint16_t increment);
      void setMinimum(uint16_t minimum);
      void setMaximum(uint16_t maximum);
      void setSelection(uint16_t selection);
      void setThumb(uint16_t thumb);
      void setValues(uint16_t selection, uint16_t minimum, uint16_t maximum, uint16_t thumb, uint16_t increment, uint16_t pageIncrement);

    private:
      class ScrollBarImpl;
      ScrollBarImpl *impl_;
    };
  }
}

#endif

