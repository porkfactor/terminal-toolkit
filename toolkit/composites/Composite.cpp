#include <terminal/toolkit/Composite.hpp>
#include <terminal/toolkit/Point.hpp>
#include <terminal/toolkit/Keys.hpp>
#include <terminal/toolkit/ttcurses.h>
#include <vector>
#include <algorithm>

namespace terminal {
  namespace toolkit {
    struct Composite::impl {
      std::vector<Control *> children_;
      std::vector<Control *> tab_list_;
    };

    Composite::Composite(Composite *parent) :
      Scrollable(parent),
      pimpl_(new impl())
    {

    }

    Composite::~Composite() {

    }

    void Composite::addChild(Control *child) {
      pimpl_->children_.push_back(child);
    }

    Point Composite::computeSize(uint32_t, uint32_t, bool) const {
      return(Point(0, 0));
    }

    void Composite::layout(bool, bool) {

    }

    Layout *Composite::getLayout() const {
      return(nullptr);
    }

    bool Composite::setFocus() {
      std::for_each(pimpl_->children_.begin(), pimpl_->children_.end(),
          [](Control *c) { c->setFocus(); }
      );

      return(Control::setFocus());
    }

    void Composite::setLayout(Layout *) {

    }

    void Composite::setLayoutDeferred(bool) {

    }

    void Composite::paint() const {
      std::for_each(pimpl_->children_.begin(), pimpl_->children_.end(),
          [](Control *c) { c->paint(); }
      );

      window().refresh();
    }

    const std::vector<Control *> &Composite::getChildren() const {
      return(pimpl_->children_);
    }

    const std::vector<Control *> &Composite::getTabList() const {
      return(pimpl_->tab_list_);
    }

    bool Composite::handleKeyEvent(Key const &key) {
      bool rv = false;

      switch(key.vk()) {
      case Key::TAB:
        /* TODO: determine next tab control and set focus */
        break;
      }

      return(rv);
    }
  }
}
