#include <terminal/toolkit/Point.hpp>

namespace terminal {
  namespace toolkit {
    Point::Point(uint32_t x, uint32_t y) :
      x_(x), y_(y)
    {

    }

    uint32_t Point::x() const {
      return(x_);
    }

    uint32_t Point::y() const {
      return(y_);
    }
  }
}


