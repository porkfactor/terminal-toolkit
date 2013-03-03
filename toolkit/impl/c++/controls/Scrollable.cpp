#include <api/c++/Scrollable.h>
#include <api/c++/Rectangle.h>

namespace terminal {
  namespace toolkit {
    class Scrollable::ScrollableImpl {
    public:
      inline scrollbar_ptr vertical() const {
        return(vertical_);
      }

      inline scrollbar_ptr horizontal() const {
        return(horizontal_);
      }

    private:
      scrollbar_ptr vertical_;
      scrollbar_ptr horizontal_;
    };

    Scrollable::Scrollable(composite_ptr parent) :
      Control(parent),
      impl_(new ScrollableImpl())
    {
    }

    Scrollable::~Scrollable() {
      delete impl_;
    }

    Rectangle Scrollable::computeTrim(uint16_t x, uint16_t y, uint16_t width, uint16_t height) {
      return(Rectangle(x, y, width, height));
    }

    Rectangle Scrollable::getClientArea() {
      return(Rectangle(0, 0, 0, 0));
    }

    scrollbar_ptr Scrollable::getHorizontalBar() const {
      return(impl_->horizontal());
    }

    scrollbar_ptr Scrollable::getVerticalBar() const {
      return(impl_->vertical());
    }
  }
}
