#ifndef TERMINAL_TOOLKIT_WIDGET_H_
#define TERMINAL_TOOLKIT_WIDGET_H_

#include <platform/platform.h>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT Widget {
    public:
      Widget();
      virtual ~Widget();

      virtual void dispose();
      virtual bool isDisposed() const;

    protected:
      virtual void checkWidget() const;

    private:
    };
  }
}

#endif

