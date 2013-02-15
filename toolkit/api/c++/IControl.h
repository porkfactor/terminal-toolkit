#ifndef _TERMINAL_TOOLKIT_CONTROL_H
#define _TERMINAL_TOOLKIT_CONTROL_H

#include <api/c++/IComponent.h>
#include <api/c++/Declarations.h>
#include <platform/platform.h>
#include <stdint.h>
#include <stdlib.h>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT Rectangle;

    class DLLEXPORT IControl : public IComponent {
    public:
      typedef intptr_t handle_t;

      inline virtual ~IControl() { }

      virtual void redraw() = 0;
      virtual void update() = 0;

      /* State */
      virtual void setEnabled(bool enabled) = 0;
      virtual bool setFocus() = 0;

      /* Sizing and Positioning */
      virtual void setBounds(const Rectangle &bounds) = 0;
      virtual void setBounds(uint16_t x, uint16_t y, uint16_t width, uint16_t height) = 0;
      virtual const Rectangle &getBounds() const = 0;

      /* Housekeeping */
      virtual window_ptr getWindow() const = 0;
    };
  }
}

#endif

