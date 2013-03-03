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

    void Text::paint() const {
      WINDOW *window = reinterpret_cast<WINDOW *>(getParent()->window());
    }
  }
}
