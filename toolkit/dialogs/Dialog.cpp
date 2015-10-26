#include <terminal/toolkit/Dialog.hpp>

namespace terminal {
  namespace toolkit {
    struct Dialog::DialogImpl {
      DialogImpl(Shell *parent) :
        parent_(parent)
      {
      }

      std::wstring text_;
      Shell *parent_;
    };

    Dialog::Dialog(Shell *parent) :
      pimpl_(new DialogImpl(parent))
    {

    }

    Dialog::~Dialog() {

    }

    Shell *Dialog::getParent() const {
      return(pimpl_->parent_);
    }

    const std::wstring &Dialog::getText() const {
      return(pimpl_->text_);
    }

    void Dialog::setText(const std::wstring &text) {
      pimpl_->text_ = text;
    }
  }
}
