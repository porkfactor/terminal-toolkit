#include <api/c++/Widget.hpp>
#include <api/c++/Declarations.hpp>

namespace terminal {
  namespace toolkit {
    Widget::Widget(widget_ptr parent) {
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

    bool Widget::handleKey(int key, Event &event) {
      return(false);
    }
  }
}
