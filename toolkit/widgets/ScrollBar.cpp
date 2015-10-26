#include <terminal/toolkit/ScrollBar.hpp>
#include <terminal/toolkit/Scrollable.hpp>
#include <terminal/toolkit/Rectangle.hpp>
#include <ttcurses.h>

namespace terminal {
  namespace toolkit {
    struct ScrollBar::ScrollBarImpl {
      ScrollBarImpl(Scrollable *parent) :
        parent_(parent),
        increment_(1),
        maximum_(0),
        minimum_(0),
        page_increment_(0),
        selection_(0)
      {

      }

      Scrollable *parent_;
      uint32_t increment_;
      uint32_t maximum_;
      uint32_t minimum_;
      uint32_t page_increment_;
      uint32_t selection_;
    };

    ScrollBar::ScrollBar(Scrollable *parent) :
      Widget(parent),
      pimpl_(new ScrollBarImpl(parent))
    {

    }

    ScrollBar::~ScrollBar() {

    }

    Scrollable *ScrollBar::getParent() const {
      return(pimpl_->parent_);
    }

    uint32_t ScrollBar::getMaximum() const {
      return(pimpl_->maximum_);
    }

    uint32_t ScrollBar::getMinimum() const {
      return(pimpl_->minimum_);
    }

    uint32_t ScrollBar::getIncrement() const {
      return(pimpl_->increment_);
    }

    uint32_t ScrollBar::getPageIncrement() const {
      return(pimpl_->page_increment_);
    }

    uint32_t ScrollBar::getSelection() const {
      return(pimpl_->selection_);
    }

    void ScrollBar::setMaximum(uint32_t maximum) {
      pimpl_->maximum_ = maximum;
    }

    void ScrollBar::setMinimum(uint32_t minimum) {
      pimpl_->minimum_ = minimum;
    }

    void ScrollBar::setIncrement(uint32_t increment) {
      pimpl_->increment_ = increment;
    }

    void ScrollBar::setPageIncrement(uint32_t increment) {
      pimpl_->page_increment_ = increment;
    }

    void ScrollBar::setSelection(uint32_t selection) {
      pimpl_->selection_ = selection;
    }

    void ScrollBar::paint() const {
      WINDOW *window = reinterpret_cast<WINDOW *>(getParent()->window());
      const Rectangle &r(getParent()->getBounds());
    }
  }
}
