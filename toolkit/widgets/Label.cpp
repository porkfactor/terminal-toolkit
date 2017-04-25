#include <terminal/toolkit/Label.hpp>
#include <terminal/toolkit/Composite.hpp>
#include <terminal/toolkit/Point.hpp>
#include <terminal/toolkit/Rectangle.hpp>
#include <terminal/toolkit/ttcurses.h>

namespace terminal {
  namespace toolkit {
    Label::Label(Composite *parent) :
      Control(parent),
      alignment_(Control::CENTER),
      image_(nullptr)
    {

    }

    Label::~Label() {

    }

    Control::alignment_t Label::getAlignment() const {
      return alignment_;
    }

    const Image *Label::getImage() const {
      return image_;
    }

    string const &Label::getText() const {
      return text_;
    }

    void Label::setAlignment(Control::alignment_t alignment) {
      alignment_ = alignment;
    }

    void Label::setImage(const Image *image) {
      image_ = image;
    }

    void Label::setText(string const &text) {
      text_ = text;
    }

    Point Label::computeSize(uint32_t width, uint32_t height, bool) const {
      return(Point(0, 0));
    }

    void Label::paint() const {
#if 0
      WINDOW *window = reinterpret_cast<WINDOW *>(getParent()->window());
      const Rectangle &r(getBounds());

      mvwaddwstr(window, r.y(), r.x(), text_.c_str());
#endif
    }
  }
}
