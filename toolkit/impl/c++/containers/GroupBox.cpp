#include <api/c++/containers/GroupBox.h>
#include <impl/c++/containers/GroupBoxImpl.h>

namespace terminal {
  namespace toolkit {
    class GroupBox::pimpl : public impl::GroupBoxImpl {
    public:
      pimpl(container_ptr container) :
        GroupBoxImpl(container)
      {
      }
    };

    GroupBox::GroupBox(container_ptr container) :
      impl_(new pimpl(container))
    {
    }

    GroupBox::~GroupBox() {
      delete impl_;
    }

    const std::string &GroupBox::getText() const {
      return(impl_->getText());
    }

    void GroupBox::setText(const std::string &text) {
      impl_->setText(text);
    }

    void GroupBox::setBounds(const Rectangle &bounds) {
      impl_->setBounds(bounds);
    }

    void GroupBox::setBounds(uint16_t x, uint16_t y, uint16_t width, uint16_t height) {
      impl_->setBounds(x, y, width, height);
    }

    const Rectangle &GroupBox::getBounds() const {
      return(impl_->getBounds());
    }

    void GroupBox::setEnabled(bool enabled) {
      impl_->setEnabled(enabled);
    }

    bool GroupBox::setFocus() {
      return(impl_->setFocus());
    }

    terminal::toolkit::window_ptr GroupBox::getWindow() const {
      return(impl_->getWindow());
    }

    void GroupBox::redraw() {
      impl_->redraw();
    }

    void GroupBox::update() {
      impl_->update();
    }
  }
}
