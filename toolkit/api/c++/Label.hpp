#ifndef TERMINAL_TOOLKIT_LABEL_H_
#define TERMINAL_TOOLKIT_LABEL_H_

#include <api/c++/Control.h>
#include <api/c++/Declarations.h>
#include <platform/platform.h>
#include <string>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT Label : public Control {
    public:
      Label(composite_ptr parent);
      virtual ~Label();

      virtual const std::string &getText() const;
      virtual void setText(const std::string &text);

    protected:
      virtual void paint() const;

    private:
      class  LabelImpl;
      LabelImpl *impl_;
    };
  }
}

#endif

