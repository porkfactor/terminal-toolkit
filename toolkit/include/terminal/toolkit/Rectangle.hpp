#ifndef TERMINAL_TOOLKIT_RECTANGLE_HPP_
#define TERMINAL_TOOLKIT_RECTANGLE_HPP_

#include <cstdlib>
#include <stdint.h>

namespace terminal {
  namespace toolkit {
    class Point;

    class Rectangle {
    public:
      Rectangle(uint32_t, uint32_t, uint32_t, uint32_t);

      uint32_t x() const;
      uint32_t y() const;
      uint32_t width() const;
      uint32_t height() const;

      bool isEmpty() const;
      bool contains(uint32_t, uint32_t) const;
      bool contains(const Point &) const;
      Rectangle intersection(const Rectangle &) const;
      bool intersects(uint32_t, uint32_t, uint32_t, uint32_t) const;
      bool intersects(const Rectangle &) const;

      void add(const Rectangle &);
      void intersect(const Rectangle &);

    private:
      uint32_t x_;
      uint32_t y_;
      uint32_t width_;
      uint32_t height_;
    };
  }
}

#endif
