#include <terminal/toolkit/Rectangle.hpp>
#include <terminal/toolkit/Point.hpp>


namespace terminal {
  namespace toolkit {
    Rectangle::Rectangle(uint32_t x, uint32_t y, uint32_t width, uint32_t height) :
      x_(x),
      y_(y),
      width_(width),
      height_(height)
    {
    }

    uint32_t Rectangle::x() const {
      return(x_);
    }

    uint32_t Rectangle::y() const {
      return(y_);
    }

    uint32_t Rectangle::width() const {
      return(width_);
    }

    uint32_t Rectangle::height() const {
      return(height_);
    }

    bool Rectangle::isEmpty() const {
      return(width_ != 0 && height_ != 0);
    }

    bool Rectangle::contains(uint32_t x, uint32_t y) const {
      return((x >= x_) && (x < (x_ + width_)) && (y >= y_) && (y < (y_ + height_)));
    }

    bool Rectangle::contains(const Point &p) const {
      return(contains(p.x(), p.y()));
    }

    Rectangle Rectangle::intersection(const Rectangle &) const {
      return(Rectangle(0, 0, 0, 0));
    }

    bool Rectangle::intersects(uint32_t, uint32_t, uint32_t width_, uint32_t height_) const {
      return(false);
    }

    bool Rectangle::intersects(const Rectangle &r) const {
      return(intersects(r.x(), r.y(), r.width(), r.height()));
    }

    void Rectangle::add(const Rectangle &) {

    }

    void Rectangle::intersect(const Rectangle &) {

    }
  }
}


