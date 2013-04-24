#include <api/c++/Rectangle.hpp>

namespace terminal {
  namespace toolkit {
    Rectangle::Rectangle() :
      x_(0), y_(0), width_(0), height_(0)
    {
    }

    Rectangle::Rectangle(uint16_t x, uint16_t y, uint16_t width, uint16_t height) :
      x_(x), y_(y), width_(width), height_(height)
    {
    }

    uint16_t Rectangle::x() const {
      return(x_);
    }

    uint16_t Rectangle::y() const {
      return(y_);
    }

    uint16_t Rectangle::width() const {
      return(width_);
    }

    uint16_t Rectangle::height() const {
      return(height_);
    }
  }
}

