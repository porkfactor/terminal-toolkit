#ifndef TERMINAL_TOOKIT_BUTTON_H_
#define TERMINAL_TOOKIT_BUTTON_H_

#include <api/c++/Control.hpp>
#include <api/c++/Declarations.hpp>
#include <platform/platform.hpp>
#include <string>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT Button : public Control {
    public:
      Button(composite_ptr parent);
      virtual ~Button();

      const std::string &getText() const;
      void setText(const std::string &text);

      virtual bool handleKey(int key, Event &event);

    protected:
      virtual void paint() const;

    private:
      class ButtonImpl;
      ButtonImpl *impl_;
    };
  }
}

#endif
