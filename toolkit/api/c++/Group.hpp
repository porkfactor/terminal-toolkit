#ifndef TERMINAL_TOOKIT_GROUP_H_
#define TERMINAL_TOOKIT_GROUP_H_

#include <api/c++/Declarations.h>
#include <api/c++/Composite.h>
#include <platform/platform.h>
#include <string>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT Group : public Composite {
    public:
      Group(composite_ptr parent);
      virtual ~Group();

      const std::string &getText() const;
      void setText(const std::string &text);

      virtual void setBounds(uint16_t x, uint16_t y, uint16_t width, uint16_t height, bool defer = true);

      virtual Rectangle computeTrim(uint16_t x, uint16_t y, uint16_t width, uint16_t height) const;
      virtual Point computeSize(uint16_t width, uint16_t height, bool changed) const;
      virtual Rectangle getClientArea() const;

      virtual Control::curses_window_t window() const;

    protected:
      virtual void paint() const;

    private:
      class GroupImpl;
      GroupImpl *impl_;
    };
  }
}

#endif

