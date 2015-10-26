#include <terminal/toolkit/Composite.hpp>
#include <terminal/toolkit/Point.hpp>
#include <ttcurses.h>
#include <vector>
#include <algorithm>

namespace terminal {
  namespace toolkit {
    struct Composite::CompositeImpl {
      CompositeImpl() {

      }

      std::vector<Control *> children_;
      std::vector<Control *> tab_list_;
    };

    Composite::Composite(Composite *parent) :
      Scrollable(parent),
      pimpl_(new CompositeImpl())
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

      wrefresh(reinterpret_cast<WINDOW *>(window()));
    }

    const std::vector<Control *> &Composite::getChildren() const {
      return(pimpl_->children_);
    }

    const std::vector<Control *> &Composite::getTabList() const {
      return(pimpl_->tab_list_);
    }

    bool Composite::handleKeyEvent(int key, Event &event) {
      bool rv = false;

      switch(key) {
      case 0x9:
        /* TODO: determine next tab control and set focus */
        break;

      case KEY_STAB:
        /* TODO: determine previous tab control and set focus */
        break;
      }

      return(rv);
    }
  }
}
