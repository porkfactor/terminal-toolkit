#include <api/c++/Text.hpp>
#include <api/c++/Composite.hpp>
#include <api/c++/Point.hpp>
#include <api/c++/Rectangle.hpp>
#include <curses.h>

namespace terminal {
  namespace toolkit {
    class Text::TextImpl {
    public:
      TextImpl() :
        cursor_location_(0, 0),
        text_limit_(10)
      {
      }

      ~TextImpl() {
      }

      std::string text_;
      Point cursor_location_;
      uint16_t text_limit_;
    };

    Text::Text(composite_ptr parent) :
      Control(parent),
      impl_(new TextImpl())
    {
    }

    Text::~Text() {
      delete impl_;
    }

    const std::string &Text::getText() const {
      return(impl_->text_);
    }

    void Text::setText(const std::string &s) {
      impl_->text_ = s;
    }

    void Text::setTextLimit(uint16_t limit) {
      impl_->text_limit_ = limit;
    }

    uint16_t Text::getTextLimit() {
      return(impl_->text_limit_);
    }

    bool Text::handleKey(int key, Event &event) {
      WINDOW *window = reinterpret_cast<WINDOW *>(getParent()->window());
      Rectangle r(getBounds());
      bool rv = false;

      switch(key) {
      case 0x8:
      case KEY_BACKSPACE:
        if(impl_->cursor_location_.x() > 0) {
          impl_->cursor_location_.x(impl_->cursor_location_.x() - 1);
          impl_->text_.erase(impl_->cursor_location_.x(), 1);
          paint();
          ::wmove(window, r.y() + impl_->cursor_location_.y(), r.x() + impl_->cursor_location_.x());
        }
        break;

      case KEY_DC:
        if(impl_->cursor_location_.x() < impl_->text_.length()) {
          impl_->text_.erase(impl_->cursor_location_.x(), 1);
          paint();
          ::wmove(window, r.y() + impl_->cursor_location_.y(), r.x() + impl_->cursor_location_.x());
        }
        break;

      case KEY_LEFT:
        if(impl_->cursor_location_.x() > 0) {
          impl_->cursor_location_.x(impl_->cursor_location_.x() - 1);
          ::wmove(window, r.y() + impl_->cursor_location_.y(), r.x() + impl_->cursor_location_.x());
        }
        break;

      case KEY_RIGHT:
        if(impl_->cursor_location_.x() < impl_->text_.length()) {
          impl_->cursor_location_.x(impl_->cursor_location_.x() + 1);
          ::wmove(window, r.y() + impl_->cursor_location_.y(), r.x() + impl_->cursor_location_.x());
        }
        break;

      case KEY_UP:
      case KEY_DOWN:
        /* navigation? */
        break;

      case 0x9:
      case 0x10:
      case 0x13:
      case KEY_ENTER:
        //
        break;

      default:
        if(impl_->text_.length() < impl_->text_limit_) {
          impl_->text_.insert(impl_->text_.begin() + impl_->cursor_location_.x(), static_cast<char>(key));
          impl_->cursor_location_.x(impl_->cursor_location_.x() + 1);
          paint();
          ::wmove(window, r.y() + impl_->cursor_location_.y(), r.x() + impl_->cursor_location_.x());
        }
        break;
      }

      return(rv);
    }

    void Text::paint() const {
      WINDOW *window = reinterpret_cast<WINDOW *>(getParent()->window());
      Rectangle r(getBounds());

      ::wattrset(window, COLOR_PAIR((COLOR_RED * COLORS) + COLOR_BLUE));

      for(uint16_t i = 0; i < r.width(); i++) {
        ::mvwaddch(window, r.y(), r.x() + i, ' ');
      }

      ::mvwaddstr(window, r.y(), r.x(), impl_->text_.c_str());
    }

    bool Text::forceFocus() {
      WINDOW *window = reinterpret_cast<WINDOW *>(getParent()->window());
      Rectangle r(getBounds());
      impl_->cursor_location_ = Point(0, 0);

      ::wmove(window, r.y() + impl_->cursor_location_.y(), r.x() + impl_->cursor_location_.x());

      return(true);
    }
  }
}
