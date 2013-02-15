#include <impl/c++/controls/ButtonImpl.h>

namespace terminal {
  namespace toolkit {
    namespace impl {
      ButtonImpl::ButtonImpl(terminal::toolkit::container_ptr container) :
        ControlImpl(container)
      {
      }

      ButtonImpl::~ButtonImpl() {
      }

      const std::string &ButtonImpl::getText() const {
        return(text_);
      }

      void ButtonImpl::setText(const std::string &text) {
        text_ = text;
      }

      void ButtonImpl::redraw() {
      }

      void ButtonImpl::update() {
      }
    }
  }
}

