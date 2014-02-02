#include <api/c++/Label.hpp>
#include <api/c++/Composite.hpp>
#include <string>
#include <curses.h>

namespace terminal {
  namespace toolkit {
    class Label::LabelImpl {
    public:
      LabelImpl() {
      }

      ~LabelImpl() {
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

    Label::Label(composite_ptr parent) :
      Control(parent),
      impl_(new LabelImpl())
    {
    }

    Label::~Label() {
      delete impl_;
    }

    const std::string &Label::getText() const {
      return(impl_->getText());
    }

    void Label::setText(const std::string &text) {
      impl_->setText(text);
    }

    void Label::paint() const {
      WINDOW *window = reinterpret_cast<WINDOW *>(getParent()->window());

      ::mvwaddstr(window, 1, 1, impl_->getText().c_str());
    }
  }
}
