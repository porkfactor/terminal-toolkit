#ifndef TERMINAL_TOOLKIT_POINT_H_
#define TERMINAL_TOOLKIT_POINT_H_

#include <stdint.h>
#include <platform/platform.hpp>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT Point {
    public:
      Point(uint16_t x, uint16_t y);

      uint16_t x() const;
      uint16_t y() const;
      void x(uint16_t);
      void y(uint16_t);

    private:
      uint16_t x_;
      uint16_t y_;
    };
  }
}

#endif

