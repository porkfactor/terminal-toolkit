#include <api/c++/windows/Window.h>
#include <impl/c++/windows/WindowImpl.h>

namespace terminal {
  namespace toolkit {
    class Window::pimpl : public impl::WindowImpl {
    public:
      pimpl(container_ptr container) : WindowImpl(container) {
      }

      virtual ~pimpl() {
      }
    };

    Window::Window(window_ptr parent, uint16_t x, uint16_t y, uint16_t width, uint16_t height) :
      impl_(new pimpl(0))
    {
    }

    Window::Window(uint16_t x, uint16_t y, uint16_t width, uint16_t height) :
      impl_(new pimpl(0))
    {
    }

    Window::~Window() {
      delete impl_;
    }

    void Window::setEnabled(bool enabled) {
      impl_->setEnabled(enabled);
    }

    bool Window::setFocus() {
      return(impl_->setFocus());
    }

    void Window::setBounds(const Rectangle &bounds) {
      impl_->setBounds(bounds);
    }

    void Window::setBounds(uint16_t x, uint16_t y, uint16_t width, uint16_t height) {
      impl_->setBounds(x, y, width, height);
    }

    const Rectangle &Window::getBounds() const {
      return(impl_->getBounds());
    }

    terminal::toolkit::window_ptr Window::getWindow() const {
      return(0);
    }

    void Window::redraw() {
      impl_->redraw();
    }

    void Window::update() {
      impl_->update();
    }
  }
}


