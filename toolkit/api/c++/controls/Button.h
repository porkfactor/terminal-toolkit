#ifndef _TERMINAL_TOOKIT_BUTTON_H
#define _TERMINAL_TOOKIT_BUTTON_H

#include <api/c++/IControl.h>
#include <platform/platform.h>
#include <string>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT Button : public IControl {
    public:
      Button(container_ptr container);
      virtual ~Button();

      const std::string &getText() const;
      void setText(const std::string &text);

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
