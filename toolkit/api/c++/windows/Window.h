#ifndef _TERMINAL_TOOLKIT_WINDOW_H
#define _TERMINAL_TOOLKIT_WINDOW_H

#include <api/c++/Declarations.h>
#include <api/c++/IContainer.h>
#include <platform/platform.h>
#include <stdint.h>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT Window : public IContainer {
    public:
      Window(window_ptr parent, uint16_t x, uint16_t y, uint16_t width, uint16_t height);
      Window(uint16_t x, uint16_t y, uint16_t width, uint16_t height);
      virtual ~Window();

      /* IControl Members */
      virtual void redraw();
      virtual void update();
      virtual void setEnabled(bool enabled);
      virtual bool setFocus();
      virtual void setBounds(const Rectangle &bounds);
      virtual void setBounds(uint16_t x, uint16_t y, uint16_t width, uint16_t height);
      virtual const Rectangle &getBounds() const;
      virtual window_ptr getWindow() const;

    protected:

    private:
      class pimpl;
      pimpl *impl_;
    };
  }
}

#endif

