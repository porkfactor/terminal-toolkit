#include <api/c++/Point.hpp>

namespace terminal {
  namespace toolkit {
    Point::Point(uint16_t x, uint16_t y) :
      x_(x), y_(y)
    {
    }

    uint16_t Point::x() const {
      return(x_);
    }

    uint16_t Point::y() const {
      return(y_);
    }

    void Point::x(uint16_t x) {
      x_ = x;
    }

    void Point::y(uint16_t y) {
      y_ = y;
    }
  }
}

