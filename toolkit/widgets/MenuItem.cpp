#include <terminal/toolkit/MenuItem.hpp>
#include <terminal/toolkit/Menu.hpp>

namespace terminal {
  namespace toolkit {
    struct MenuItem::impl {
      impl(Menu *parent) :
        parent_(parent),
        menu_(nullptr),
        enabled_(true)
      {
      }

      string text_;
      Menu *parent_;
      Menu *menu_;
      bool enabled_;
    };

    MenuItem::MenuItem(Menu *parent) :
      Item(parent),
      pimpl_(new impl(parent))
    {
    }

    MenuItem::~MenuItem() {

    }

    Menu *MenuItem::getParent() const {
      return(pimpl_->parent_);
    }

    Menu *MenuItem::getMenu() const {
      return(pimpl_->menu_);
    }

    bool MenuItem::getEnabled() const {
      return(pimpl_->enabled_);
    }

    void MenuItem::setEnabled(bool enabled) {
      pimpl_->enabled_ = enabled;
    }

    void MenuItem::setMenu(Menu *menu) {
      pimpl_->menu_ = menu;
    }

    void MenuItem::setText(string const &) {

    }
  }
}

