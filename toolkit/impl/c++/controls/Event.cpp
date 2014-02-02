#include <api/c++/Event.hpp>

namespace terminal {
  namespace toolkit {
    Event::~Event() {
    }

    uint16_t Event::x() const {
      return(x_);
    }

    uint16_t Event::y() const {
      return(y_);
    }

    uint16_t Event::width() const {
      return(width_);
    }

    uint16_t Event::height() const {
      return(height_);
    }

    uint32_t Event::keycode() const {
      return(keycode_);
    }
  }
}
