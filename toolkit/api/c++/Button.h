#ifndef TERMINAL_TOOKIT_BUTTON_H_
#define TERMINAL_TOOKIT_BUTTON_H_

#include <api/c++/Control.h>
#include <platform/platform.h>
#include <string>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT Button : public Control {
    public:
      Button(composite_ptr parent);
      virtual ~Button();

      const std::string &getText() const;
      void setText(const std::string &text);

    protected:
      virtual void paint() const;

    private:
      class ButtonImpl;
      ButtonImpl *impl_;
    };
  }
}

#endif
