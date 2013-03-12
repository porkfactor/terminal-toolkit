#include <api/c++/Widget.h>
#include <api/c++/Declarations.h>

namespace terminal {
  namespace toolkit {
    Widget::Widget() {
    }

    Widget::~Widget() {
    }

    void Widget::dispose() {
    }

    bool Widget::isDisposed() const {
      return(true);
    }

    void Widget::checkWidget() const {
    }

    event_ptr Widget::handleKey(int key) {
      event_ptr rv(0);

      return(rv);
    }
  }
}
