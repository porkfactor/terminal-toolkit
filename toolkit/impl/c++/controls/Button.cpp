#include <api/c++/controls/Button.h>
#include <api/c++/IContainer.h>
#include <impl/c++/controls/ButtonImpl.h>

namespace terminal {
  namespace toolkit {
    class Button::pimpl : public impl::ButtonImpl {
    public:
      pimpl(container_ptr container) :
        ButtonImpl(container)
      {
      }

    private:
      container_ptr container_;
      std::string text_;
    };

    Button::Button(container_ptr container) :
      impl_(new pimpl(container))
    {
    }

    Button::~Button() {
      delete impl_;
    }

    void Button::setText(const std::string &text) {
      impl_->setText(text);
    }

    const std::string &Button::getText() const {
      return(impl_->getText());
    }

    bool Button::setFocus() {
      return(true);
    }

    void Button::setEnabled(bool enabled) {
      impl_->setEnabled(enabled);
    }

    void Button::setBounds(const Rectangle &bounds) {
      impl_->setBounds(bounds);
    }

    void Button::setBounds(uint16_t x, uint16_t y, uint16_t width, uint16_t height) {
      impl_->setBounds(x, y, width, height);
    }

    const Rectangle &Button::getBounds() const {
      return(impl_->getBounds());
    }

    window_ptr Button::getWindow() const {
      return(impl_->getWindow());
    }

    void Button::redraw() {
      impl_->redraw();
    }

    void Button::update() {
      impl_->update();
    }
  }
}
