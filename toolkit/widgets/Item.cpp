#include <terminal/toolkit/Item.hpp>
#include <string>

namespace terminal {
  namespace toolkit {
    struct Item::ItemImpl {

      std::wstring text_;
    };

    Item::Item(Widget *parent) :
      Widget(parent),
      pimpl_(new ItemImpl())
    {
    }

    Item::~Item() {

    }

    const std::wstring &Item::getText() const {
      return(pimpl_->text_);
    }

    void Item::setText(const std::wstring &text) {
      pimpl_->text_ = text;
    }
  }
}


