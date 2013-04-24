#ifndef TERMINAL_TOOLKIT_TEXT_H_
#define TERMINAL_TOOLKIT_TEXT_H_

#include <api/c++/Declarations.hpp>
#include <api/c++/Control.hpp>
#include <platform/platform.hpp>
#include <string>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT Text : public Control {
    public:
      Text(composite_ptr parent);
      virtual ~Text();

      const std::string &getText() const;
      void setText(const std::string &);
      void setTextLimit(uint16_t limit);
      uint16_t getTextLimit();

      virtual bool forceFocus();
      
    protected:
      virtual void paint() const;
      virtual bool handleKey(int key, Event &event);

    private:
      class TextImpl;
      TextImpl *impl_;
    };
  }
}

#endif

