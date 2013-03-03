#include <api/c++/Control.h>
#include <api/c++/Composite.h>
#include <api/c++/Point.h>
#include <api/c++/Rectangle.h>

namespace terminal {
  namespace toolkit {
    class Control::ControlImpl {
    public:
      ControlImpl(composite_ptr parent) :
        parent_(parent)
      {
      }

      ~ControlImpl() {
      }

      inline Control::curses_window_t window() const {
        return(window_);
      }

      inline void window(Control::curses_window_t w) {
        window_ = w;
      }

      inline composite_ptr parent() const {
        return(parent_);
      }

      inline const Color &foreground() const {
        return(foreground_);
      }

      inline void foreground(const Color &color) {
        foreground_ = color;
      }
      
      inline const Color &background() const {
        return(background_);
      }

      inline void background(const Color &color) {
        background_ = color;
      }

    private:
      Color foreground_;
      Color background_;
      composite_ptr parent_;
      Control::curses_window_t window_;
    };

    Control::Control(composite_ptr parent) :
      impl_(new ControlImpl(parent))
    {
    }

    Control::~Control() {
      delete impl_;
    }

    Color Control::getForeground() const {
      return(impl_->foreground());
    }

    Color Control::getBackground() const {
      return(impl_->background());
    }

    void Control::setForeground(const Color &color) {
      impl_->foreground(color);
    }

    void Control::setBackground(const Color &color) {
      impl_->background(color);
    }

    void Control::pack(bool changed) {
    }

    void Control::redraw() {
    }

    void Control::redraw(uint16_t x, uint16_t y, uint16_t width, uint16_t height, bool all) {
    }

    void Control::update() {
    }

    bool Control::getEnabled() const {
      return(false);
    }

    void Control::setEnabled(bool enabled) {
    }

    bool Control::setFocus() {
      return(false);
    }

    bool Control::forceFocus() {
      return(false);
    }

    bool Control::isEnabled() const {
      return(false);
    }
    
    bool Control::isFocusControl() const {
      return(false);
    }

    bool Control::isVisible() const {
      return(false);
    }

    void Control::setSize(uint16_t width, uint16_t height) {
      setBounds(0, 0, width, height);
    }

    void Control::setSize(const Point &p) {
      setBounds(0, 0, p.x(), p.y());
    }

    void Control::setBounds(uint16_t x, uint16_t y, uint16_t width, uint16_t height, bool defer) {
    }

    void Control::setBounds(const Rectangle &bounds) {
      setBounds(bounds.x(), bounds.y(), bounds.width(), bounds.height());
    }

    Rectangle Control::getBounds() const {
      Rectangle r(0, 0, 0, 0);
      return(r);
    }

    Point Control::getLocation() const {
      return(Point(0, 0));
    }

    Point Control::getSize() const {
      return(Point(0, 0));
    }

    Point Control::computeSize(uint16_t width, uint16_t height, bool changed) const {
      return(Point(0, 0));
    }

    composite_ptr Control::getParent() const {
      return(impl_->parent());
    }

    shell_ptr Control::getShell() const {
      return(impl_->parent()->getShell());
    }

    Control::curses_window_t Control::window() const {
      return(impl_->window());
    }
  }
}

