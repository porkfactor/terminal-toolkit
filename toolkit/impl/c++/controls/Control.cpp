#include <api/c++/Control.hpp>
#include <api/c++/Composite.hpp>
#include <api/c++/Point.hpp>
#include <api/c++/Rectangle.hpp>

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

      Rectangle bounds_;
      Color foreground_;
      Color background_;
      composite_ptr parent_;
      Control::curses_window_t window_;
    };

    Control::Control(composite_ptr parent) :
      Widget(parent),
      impl_(new ControlImpl(parent))
    {
      if(parent) {
        parent->addChild(control_ptr(this));
      }
    }

    Control::~Control() {
      delete impl_;
    }

    Color Control::getForeground() const {
      return(impl_->foreground_);
    }

    Color Control::getBackground() const {
      return(impl_->background_);
    }

    void Control::setForeground(const Color &color) {
      impl_->foreground_ = color;
    }

    void Control::setBackground(const Color &color) {
      impl_->background_ = color;
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
      impl_->bounds_ = Rectangle(x, y, width, height);
    }

    void Control::setBounds(const Rectangle &bounds) {
      setBounds(bounds.x(), bounds.y(), bounds.width(), bounds.height());
    }

    Rectangle Control::getBounds() const {
      return(impl_->bounds_);
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
      return(impl_->parent_);
    }

    shell_ptr Control::getShell() const {
      return(impl_->parent_->getShell());
    }

    Control::curses_window_t Control::window() const {
      return(impl_->window_);
    }
  }
}

