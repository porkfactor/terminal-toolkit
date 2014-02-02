#include <api/c++/Dialog.hpp>

namespace terminal {
  namespace toolkit {
    class Dialog::DialogImpl {
    public:
      DialogImpl(shell_ptr parent, Dialog::style_t style) :
        parent_(parent),
        style_(style)
      {
      }

      Dialog::style_t style_;
      shell_ptr parent_;
      std::string text_;
    };

    Dialog::Dialog(shell_ptr parent, Dialog::style_t style) :
      impl_(new DialogImpl(parent, style))
    {
    }

    Dialog::Dialog(shell_ptr parent) :
      impl_(new DialogImpl(parent, Dialog::APPLICATION_MODAL))
    {
    }

    Dialog::~Dialog() {
      delete impl_;
    }

    shell_ptr Dialog::getParent() const {
      return(impl_->parent_);
    }

    void Dialog::setText(const std::string &text) {
      impl_->text_ = text;
    }

    const std::string &Dialog::getText() const {
      return(impl_->text_);
    }

    Dialog::style_t Dialog::getStyle() const {
      return(impl_->style_);
    }
  }
}