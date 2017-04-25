#include <terminal/toolkit/Composite.hpp>
#include <terminal/toolkit/Point.hpp>
#include <terminal/toolkit/Keys.hpp>
#include <terminal/toolkit/ttcurses.h>
#include <vector>
#include <algorithm>

namespace terminal {
  namespace toolkit {
    Composite::Composite(Composite *parent) :
      Scrollable(parent)
    {

    }

    Composite::~Composite() {

    }

    void Composite::addChild(Control *child) {
      children_.push_back(child);
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
      std::for_each(children_.begin(), children_.end(),
          [](Control *c) { c->setFocus(); }
      );

      return(Control::setFocus());
    }

    void Composite::setLayout(Layout *) {

    }

    void Composite::setLayoutDeferred(bool) {

    }

    void Composite::paint() const {
      std::for_each(children_.begin(), children_.end(),
          [](Control *c) { c->paint(); }
      );

      window().refresh();
    }

    const std::vector<Control *> &Composite::getChildren() const {
      return(children_);
    }

    const std::vector<Control *> &Composite::getTabList() const {
      return(tab_list_);
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
