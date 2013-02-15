#ifndef _TERMINAL_TOOLKIT_LABEL_H
#define _TERMINAL_TOOLKIT_LABEL_H

#include <api/c++/IControl.h>
#include <api/c++/Declarations.h>
#include <platform/platform.h>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT Label : public IControl {
    public:
      Label(container_ptr container);
      virtual ~Label();

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
      class  pimpl;
      pimpl *impl_;
    };
  }
}

#endif

