#ifndef TERMINAL_TOOLKIT_COLOR_H_
#define TERMINAL_TOOLKIT_COLOR_H_

#include <stdint.h>

namespace terminal {
  namespace toolkit {
    class Color {
    public:
      typedef uint32_t color_t;

    private:
      color_t color_;
    };
  }
}

#endif

