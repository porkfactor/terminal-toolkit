#include <terminal/toolkit/Menu.hpp>
#include <terminal/toolkit/MenuItem.hpp>
#include <terminal/toolkit/Control.hpp>
#include <algorithm>

namespace terminal {
  namespace toolkit {
    struct Menu::impl {
      impl() {

      }

      std::vector<MenuItem *> items_;
    };

    Menu::Menu(Control *parent) :
      Widget(parent),
      pimpl_(new impl())
    {
    }

    Menu::Menu(Menu *parent) :
      Widget(parent),
      pimpl_(new impl())
    {
    }

    Menu::Menu(MenuItem *item) :
      Widget(item->getParent()),
      pimpl_(new impl())
    {
    }

    Menu::~Menu() {

    }

    MenuItem *Menu::getDefaultItem() const {
      return(0);
    }

    uint32_t Menu::getItemCount() const {
      return(pimpl_->items_.size());
    }

    std::vector<MenuItem *> Menu::getItems() const {
      return(pimpl_->items_);
    }

    MenuItem *Menu::getItem(Control::index_t index) const {
      MenuItem *rv = 0;

      if(index < pimpl_->items_.size()) {
        rv = pimpl_->items_[index];
      }

      return(rv);
    }

    int32_t Menu::indexOf(const MenuItem *item) const {
      int32_t rv = -1;
      auto it = std::find(pimpl_->items_.begin(), pimpl_->items_.end(), item);

      if(it != pimpl_->items_.end()) {
        rv = std::distance(pimpl_->items_.begin(), it);
      }

      return(rv);
    }

    void Menu::paint() const {

    }
  }
}

