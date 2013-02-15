#include <impl/c++/controls/TextImpl.h>

namespace terminal {
  namespace toolkit {
    namespace impl {
      TextImpl::TextImpl(terminal::toolkit::container_ptr container) :
        ControlImpl(container)
      {
      }

      TextImpl::~TextImpl() {
      }

      const std::string &TextImpl::getText() const {
        return(text_);
      }

      void TextImpl::setText(const std::string &text) {
        text_ = text;
      }

      void TextImpl::redraw() {
      }

      void TextImpl::update() {
      }
    }
  }
}
