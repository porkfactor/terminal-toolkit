#include <impl/c++/controls/ControlImpl.h>

namespace terminal {
  namespace toolkit {
    namespace impl {
      ControlImpl::ControlImpl(terminal::toolkit::container_ptr container) :
        container_(container)
      {
      }

      ControlImpl::~ControlImpl() {
      }

      void ControlImpl::setBounds(uint16_t x, uint16_t y, uint16_t width, uint16_t height) {
      }

      void ControlImpl::setBounds(const Rectangle &r) {
      }

      const terminal::toolkit::Rectangle &ControlImpl::getBounds() const {
        return(bounds_);
      }

      void ControlImpl::setEnabled(bool enabled) {
      }

      bool ControlImpl::setFocus() {
        return(false);
      }

      window_ptr ControlImpl::getWindow() const {
        return(window_ptr(0));
      }

      terminal::toolkit::IControl::handle_t ControlImpl::handle() const {
        return(0);
      }
    }
  }
}

