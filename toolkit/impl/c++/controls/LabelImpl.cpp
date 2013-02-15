#include <impl/c++/controls/LabelImpl.h>

namespace terminal {
  namespace toolkit {
    namespace impl {
      LabelImpl::LabelImpl(terminal::toolkit::container_ptr container) :
        ControlImpl(container)
      {
      }

      LabelImpl::~LabelImpl() {
      }

      const std::string &LabelImpl::getText() const {
        return(text_);
      }

      void LabelImpl::setText(const std::string &text) {
        text_ = text;
      }

      void LabelImpl::redraw() {
      }

      void LabelImpl::update() {
      }
    }
  }
}
