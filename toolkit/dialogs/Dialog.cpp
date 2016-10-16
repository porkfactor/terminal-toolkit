#include <terminal/toolkit/Dialog.hpp>

namespace terminal {
  namespace toolkit {
    struct Dialog::impl {
      impl(Shell *parent) :
        parent_(parent)
      {
      }

      string text_;
      Shell *parent_;
    };

    Dialog::Dialog(Shell *parent) :
      pimpl_(new impl(parent))
    {

    }

    Dialog::~Dialog() {

    }

    Shell *Dialog::getParent() const {
      return(pimpl_->parent_);
    }

    string const &Dialog::getText() const {
      return(pimpl_->text_);
    }

    void Dialog::setText(string const &text) {
      pimpl_->text_ = text;
    }
  }
}
