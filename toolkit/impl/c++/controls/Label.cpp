#include <api/c++/controls/Label.h>
#include <impl/c++/controls/LabelImpl.h>

namespace terminal {
  namespace toolkit {
    class Label::pimpl : public impl::LabelImpl {
    public:
      pimpl(container_ptr container) :
        LabelImpl(container)
      {
      }

      ~pimpl() {
      }
    };

    Label::Label(container_ptr container) :
      impl_(new pimpl(container))
    {
    }

    Label::~Label() {
      delete impl_;
    }

    void Label::setEnabled(bool enabled) {
      impl_->setEnabled(enabled);
    }

    bool Label::setFocus() {
      return(impl_->setFocus());
    }

    void Label::setBounds(const Rectangle &bounds) {
      impl_->setBounds(bounds);
    }

    void Label::setBounds(uint16_t x, uint16_t y, uint16_t width, uint16_t height) {
      impl_->setBounds(x, y, width, height);
    }

    const Rectangle &Label::getBounds() const {
      return(impl_->getBounds());
    }

    window_ptr Label::getWindow() const {
      return(impl_->getWindow());
    }

    void Label::redraw() {
    }

    void Label::update() {
    }
  }
}
