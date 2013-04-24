#ifndef TERMINAL_TOOLKIT_RECTANGLE_H_
#define TERMINAL_TOOLKIT_RECTANGLE_H_

#include <platform/platform.hpp>
#include <stdint.h>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT Rectangle {
    public:
      Rectangle();
      Rectangle(uint16_t x, uint16_t y, uint16_t width, uint16_t height);

      uint16_t x() const;
      uint16_t y() const;
      uint16_t width() const;
      uint16_t height() const;

    private:
      uint16_t x_;
      uint16_t y_;
      uint16_t width_;
      uint16_t height_;
    };
  }
}

#endif