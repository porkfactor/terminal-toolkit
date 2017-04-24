#include <terminal/toolkit/Label.hpp>
#include <terminal/toolkit/Composite.hpp>
#include <terminal/toolkit/Point.hpp>
#include <terminal/toolkit/Rectangle.hpp>
#include <terminal/toolkit/ttcurses.h>

namespace terminal {
  namespace toolkit {
    struct Label::impl {
      impl() :
        alignment_(Control::CENTER),
        image_(nullptr)
      {
      }

      Control::alignment_t alignment_;
      string text_;
      const Image *image_;
    };

    Label::Label(Composite *parent) :
      Control(parent),
      pimpl_(new impl())
    {

    }

    Label::~Label() {

    }

    Control::alignment_t Label::getAlignment() const {
      return(pimpl_->alignment_);
    }

    const Image *Label::getImage() const {
      return(pimpl_->image_);
    }

    string const &Label::getText() const {
      return(pimpl_->text_);
    }

    void Label::setAlignment(Control::alignment_t alignment) {
      pimpl_->alignment_ = alignment;
    }

    void Label::setImage(const Image *image) {
      pimpl_->image_ = image;
    }

    void Label::setText(string const &text) {
      pimpl_->text_ = text;
    }

    Point Label::computeSize(uint32_t width, uint32_t height, bool) const {
      return(Point(0, 0));
    }

    void Label::paint() const {
#if 0
      WINDOW *window = reinterpret_cast<WINDOW *>(getParent()->window());
      const Rectangle &r(getBounds());

      mvwaddwstr(window, r.y(), r.x(), pimpl_->text_.c_str());
#endif
    }
  }
}
