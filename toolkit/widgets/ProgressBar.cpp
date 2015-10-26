#include <terminal/toolkit/ProgressBar.hpp>
#include <terminal/toolkit/Point.hpp>
#include <terminal/toolkit/Rectangle.hpp>
#include <ttcurses.h>

namespace terminal {
  namespace toolkit {
    struct ProgressBar::ProgressBarImpl {
      ProgressBarImpl() :
        minimum_(0),
        maximum_(0),
        position_(0)
      {

      }

      uint32_t minimum_;
      uint32_t maximum_;
      uint32_t position_;
    };

    Point ProgressBar::computeSize(uint32_t, uint32_t, bool) const {
      return(Point(0, 0));
    }

    uint32_t ProgressBar::getMaximum() const {
      return(pimpl_->maximum_);
    }

    uint32_t ProgressBar::getMinimum() const {
      return(pimpl_->minimum_);
    }

    uint32_t ProgressBar::getSelection() const {
      return(pimpl_->position_);
    }

    void ProgressBar::setMinimum(uint32_t minimum) {
      pimpl_->minimum_ = minimum;
    }

    void ProgressBar::setMaximum(uint32_t maximum) {
      pimpl_->maximum_ = maximum;
    }

    void ProgressBar::setSelection(uint32_t selection) {
      pimpl_->position_ = selection;
    }

    void ProgressBar::paint() const {
      WINDOW *w = reinterpret_cast<WINDOW *>(window());
      Rectangle r(getBounds());

      uint32_t index = (pimpl_->maximum_ - pimpl_->minimum_) / pimpl_->position_;

      // TODO: how to reverse?
      wattrset(w, color());

      for(uint32_t i = 0; i < index; i++) {
        mvwaddch(w, r.y(), r.x() + i, ' ');
      }

      wattrset(w, color());

      for(uint32_t i = index; i < r.width(); i++) {
        mvwaddch(w, r.y(), r.x() + i, ' ');
      }
    }
  }
}

