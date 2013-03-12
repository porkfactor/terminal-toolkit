#include <api/c++/Button.h>
#include <api/c++/Composite.h>
#include <api/c++/Rectangle.h>
#include <curses.h>

namespace terminal {
  namespace toolkit {
    class Button::ButtonImpl  {
    public:
      ButtonImpl() {
      }

      inline const std::string &getText() const {
        return(text_);
      }

      inline void setText(const std::string &text) {
        text_ = text;
      }

    private:
      std::string text_;
    };

    Button::Button(composite_ptr parent) :
      Control(parent),
      impl_(new ButtonImpl())
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

    void Button::paint() const {
    }

    event_ptr Button::handleKey(int key) {
      event_ptr rv(0);

      switch(key) {
      case KEY_ENTER:
      case 0x10:
      case 0x13:
      }

      return(rv);
    }
  }
}
