#ifndef TERMINAL_TOOLKIT_SHELL_HPP_
#define TERMINAL_TOOLKIT_SHELL_HPP_

#include <memory>
#include <terminal/toolkit/Composite.hpp>

namespace terminal {
  namespace toolkit {
    class Display;

    class Shell : public Composite {
    public:
      typedef enum {
        NORMAL,
        BORDER
      } style_t;

      Shell(Display *, style_t = NORMAL);
      Shell(Shell *, style_t = NORMAL);
      virtual ~Shell();

      virtual Shell *getShell() const;
      virtual Display *getDisplay() const;

      virtual bool getEnabled() const;
      virtual bool getFullScreen() const;
      virtual bool getModified() const;
      virtual void setEnabled(bool = true);
      virtual void setFullScreen(bool = true);
      virtual void setVisible(bool = true);

      virtual Rectangle getBounds() const;
      virtual Point getLocation() const;
      virtual Point getMinimumSize() const;
      virtual Point getSize() const;
      virtual void setMinimumSize(uint32_t, uint32_t);
      virtual void setMinimumSize(const Point &);

      virtual Control *getFocusControl() const;

      virtual bool post(Event *event);
      virtual void open();
      virtual uintptr_t window() const;

    protected:
      virtual bool handleKeyEvent(int, Event &);

    private:
      struct ShellImpl;
      std::unique_ptr<ShellImpl> pimpl_;
    };
  }
}



#endif
