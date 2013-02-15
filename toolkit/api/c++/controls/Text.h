#ifndef _TERMINAL_TOOLKIT_TEXT_H
#define _TERMINAL_TOOLKIT_TEXT_H

#include <api/c++/Declarations.h>
#include <api/c++/IControl.h>
#include <platform/platform.h>
#include <string>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT Text : public IControl {
    public:
      Text(container_ptr parent);
      virtual ~Text();

      const std::string &getText() const;
      void setText(const std::string &);
      
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

