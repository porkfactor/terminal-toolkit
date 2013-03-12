#include <api/c++/Text.h>
#include <api/c++/Composite.h>
#include <curses.h>

namespace terminal {
  namespace toolkit {
    class Text::TextImpl {
    public:
      TextImpl() {
      }

      ~TextImpl() {
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

    Text::Text(composite_ptr parent) :
      Control(parent),
      impl_(new TextImpl())
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

    event_ptr Text::handleKey(int key) {
      switch(key) {
      case KEY_BACKSPACE:
      case KEY_LEFT:
      case KEY_RIGHT:
        /* local edit event */
        break;

      case KEY_UP:
      case KEY_DOWN:
        /* navigation? */
        break;

      case 0x9:
      case 0x10:
      case 0x13:
      case KEY_ENTER:
        /* navigation */
        break;
      }
    }

    void Text::paint() const {
      WINDOW *window = reinterpret_cast<WINDOW *>(getParent()->window());
    }
  }
}
