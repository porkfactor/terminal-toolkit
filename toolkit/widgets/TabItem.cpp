#include <terminal/toolkit/TabItem.hpp>
#include <terminal/toolkit/TabFolder.hpp>

namespace terminal {
  namespace toolkit {
    struct TabItem::impl {

      std::wstring text_;
      std::wstring tooltip_;
    };

    TabItem::TabItem(TabFolder *parent) :
      Item(parent)
    {

    }

    TabItem::~TabItem() {

    }

    const std::wstring &TabItem::getToolTipText() const {
      return(pimpl_->tooltip_);
    }

    void TabItem::setText(const std::wstring &s) {

    }

    void TabItem::setToolTipText(const std::wstring &s) {
      pimpl_->tooltip_ = s;
    }
  }
}
