#ifndef TERMINAL_TOOLKIT_TEXT_H_
#define TERMINAL_TOOLKIT_TEXT_H_

#include <api/c++/Declarations.h>
#include <api/c++/Control.h>
#include <platform/platform.h>
#include <string>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT Text : public Control {
    public:
      Text(composite_ptr parent);
      virtual ~Text();

      const std::string &getText() const;
      void setText(const std::string &);

      virtual event_ptr handleKey(int key);
      
    protected:
      virtual void paint() const;

    private:
      class TextImpl;
      TextImpl *impl_;
    };
  }
}

#endif

