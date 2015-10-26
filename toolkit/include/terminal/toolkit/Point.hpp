#ifndef TERMINAL_TOOLKIT_POINT_HPP_
#define TERMINAL_TOOLKIT_POINT_HPP_

#include <cstdlib>
#include <stdint.h>

namespace terminal {
  namespace toolkit {
    class Point {
    public:
      Point(uint32_t, uint32_t);

      uint32_t x() const;
      uint32_t y() const;

    private:
      uint32_t x_;
      uint32_t y_;
    };
  }
}

#endif
