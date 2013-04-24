#ifndef TERMINAL_TOOLKIT_CONTROL_H_
#define TERMINAL_TOOLKIT_CONTROL_H_

#include <api/c++/Declarations.hpp>
#include <api/c++/Widget.hpp>
#include <api/c++/Point.hpp>
#include <api/c++/Color.hpp>
#include <platform/platform.hpp>
#include <stdint.h>
#include <stdlib.h>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT Control : public Widget {
      friend class Composite;
    public:
      typedef uintptr_t curses_window_t;

      Control(composite_ptr parent);
      virtual ~Control();

      virtual void pack(bool changed);
      virtual void redraw();
      virtual void redraw(uint16_t x, uint16_t y, uint16_t width, uint16_t height, bool all);
      virtual void update();

      /* State */
      virtual bool getEnabled() const;
      virtual void setEnabled(bool enabled);
      virtual bool setFocus();
      virtual bool forceFocus();
      virtual bool isEnabled() const;
      virtual bool isFocusControl() const;
      virtual bool isVisible() const;

      /* Appearance */
      virtual Color getForeground() const;
      virtual Color getBackground() const;
      virtual void setForeground(const Color &color);
      virtual void setBackground(const Color &color);

      /* Sizing and Positioning */
      virtual Rectangle getBounds() const;
      virtual Point getLocation() const;
      virtual Point getSize() const;
      virtual Point computeSize(uint16_t width, uint16_t height, bool changed = true) const;

      virtual void setSize(uint16_t x, uint16_t y);
      virtual void setSize(const Point &p);
      virtual void setBounds(const Rectangle &bounds);
      virtual void setBounds(uint16_t x, uint16_t y, uint16_t width, uint16_t height, bool defer = true);

      /* Housekeeping */
      virtual composite_ptr getParent() const;
      virtual shell_ptr getShell() const;
      virtual curses_window_t window() const;

    private:
      class ControlImpl;
      ControlImpl *impl_;
    };
  }
}

#endif

