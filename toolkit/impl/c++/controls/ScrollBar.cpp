#include <api/c++/ScrollBar.h>

namespace terminal {
  namespace toolkit {
    class ScrollBar::ScrollBarImpl {
    public:
      ScrollBarImpl(composite_ptr) {
      }

      ~ScrollBarImpl() {
      }

      uint16_t increment_;
      uint16_t page_increment_;
      uint16_t minimum_;
      uint16_t maximum_;
      uint16_t selection_;
      uint16_t thumb_;
    };

    ScrollBar::ScrollBar(composite_ptr parent) :
      Control(parent),
      impl_(new ScrollBarImpl(parent))
    {

    }

    ScrollBar::~ScrollBar() {
      delete impl_;
    }

    uint16_t ScrollBar::getIncrement() const {
      return(impl_->increment_);
    }

    uint16_t ScrollBar::getPageIncrement() const {
      return(impl_->page_increment_);
    }

    uint16_t ScrollBar::getMinimum() const {
      return(impl_->minimum_);
    }

    uint16_t ScrollBar::getMaximum() const {
      return(impl_->maximum_);
    }

    uint16_t ScrollBar::getSelection() const {
      return(impl_->selection_);
    }

    uint16_t ScrollBar::getThumb() const {
      return(impl_->thumb_);
    }

    void ScrollBar::setMinimum(uint16_t minimum) {
      impl_->minimum_ = minimum;
    }

    void ScrollBar::setMaximum(uint16_t maximum) {
      impl_->maximum_ = maximum;
    }

    void ScrollBar::setIncrement(uint16_t increment) {
      impl_->increment_ = increment;
    }

    void ScrollBar::setPageIncrement(uint16_t pageIncrement) {
      impl_->page_increment_ = pageIncrement;
    }

    void ScrollBar::setValues(uint16_t selection, uint16_t minimum, uint16_t maximum, uint16_t thumb, uint16_t increment, uint16_t pageIncrement) {
      impl_->selection_ = selection;
      impl_->minimum_ = minimum;
      impl_->maximum_ = maximum;
      impl_->increment_ = increment;
      impl_->page_increment_ = pageIncrement;
      impl_->thumb_ = thumb;
    }
  }
}
