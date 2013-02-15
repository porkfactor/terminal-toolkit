#include <api/c++/controls/Text.h>
#include <impl/c++/controls/TextImpl.h>

namespace terminal {
  namespace toolkit {
    class Text::pimpl : public impl::TextImpl {
    public:
      pimpl(container_ptr container) :
        impl::TextImpl(container)
      {
      }

      ~pimpl() {
      }

    private:
    };

    Text::Text(container_ptr parent) :
      impl_(new pimpl(parent))
    {
    }

    Text::~Text() {
      delete impl_;
    }

    const std::string &Text::getText() const {
      return(impl_->getText());
    }

    void Text::setText(const std::string &s) {
      impl_->setText(s);
    }

    void Text::setEnabled(bool enabled) {
      impl_->setEnabled(enabled);
    }

    bool Text::setFocus() {
      return(impl_->setFocus());
    }

    void Text::setBounds(const Rectangle &bounds) {
      impl_->setBounds(bounds);
    }
     
    void Text::setBounds(uint16_t x, uint16_t y, uint16_t width, uint16_t height) {
      impl_->setBounds(x, y, width, height);
    }
     
    const Rectangle &Text::getBounds() const {
      return(impl_->getBounds());
    }

    window_ptr Text::getWindow() const {
      return(impl_->getWindow());
    }

    void Text::redraw() {
      impl_->redraw();
    }

    void Text::update() {
      impl_->update();
    }
  }
}
