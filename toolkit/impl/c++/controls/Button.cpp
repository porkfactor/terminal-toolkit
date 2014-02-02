#include <api/c++/Button.hpp>
#include <api/c++/Composite.hpp>
#include <api/c++/Rectangle.hpp>
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

    bool Button::handleKey(int key, Event &event) {
      bool rv = false;

      switch(key) {
      case KEY_ENTER:
      case '\r':
      case '\n':
        rv = true;
        break;
      }

      return(rv);
    }
  }
}
