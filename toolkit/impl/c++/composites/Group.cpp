#include <api/c++/Group.h>
#include <api/c++/Rectangle.h>
#include <api/c++/Point.h>
#include <curses.h>

namespace terminal {
  namespace toolkit {
    class Group::GroupImpl {
    public:
      GroupImpl(composite_ptr parent) :
        window_(0)
      {
        if(parent) {
          window_ = ::derwin(reinterpret_cast<WINDOW *>(parent->window()), 0, 0, 0, 0);
        } else {
        }
      }

      ~GroupImpl() {
        if(window_)
          ::delwin(window_);
      }

      inline const std::string &getText() const {
        return(text_);
      }

      inline void setText(const std::string &text) {
        text_ = text;
      }

      inline WINDOW *window() const {
        return(window_);
      }

    private:
      std::string text_;
      WINDOW *window_;
    };

    Group::Group(composite_ptr parent) :
      Composite(parent),
      impl_(new GroupImpl(parent))
    {
    }

    Group::~Group() {
      delete impl_;
    }

    const std::string &Group::getText() const {
      return(impl_->getText());
    }

    void Group::setText(const std::string &text) {
      impl_->setText(text);
    }

    Rectangle Group::computeTrim(uint16_t x, uint16_t y, uint16_t width, uint16_t height) const {
      Rectangle r(x - 1, y - 1, width + 2, height + 2);

      return(r);
    }

    Point Group::computeSize(uint16_t width, uint16_t height, bool changed) const {
      Point p(Composite::computeSize(width, height, changed));

      p.x(p.x() + 2);
      p.y(p.y() + 2);

      return(Point(0, 0));
    }

    Rectangle Group::getClientArea() const {
      uint16_t x = impl_->window()->_begx;
      uint16_t y = impl_->window()->_begy;
      uint16_t width = impl_->window()->_maxx - impl_->window()->_begx;
      uint16_t height = impl_->window()->_maxy - impl_->window()->_begy;

      return(Rectangle(x, y, width, height));
    }

    void Group::setBounds(uint16_t x, uint16_t y, uint16_t width, uint16_t height, bool defer) {
      ::wresize(impl_->window(), height, width);
      ::mvderwin(impl_->window(), y, x);
    }

    void Group::paint() const {
      ::box(impl_->window(), 0, 0);
      ::mvwaddstr(impl_->window(), 0, 2, impl_->getText().c_str());
      ::touchwin(reinterpret_cast<WINDOW *>(getParent()->window()));
      ::wrefresh(impl_->window());
    }

    Control::curses_window_t Group::window() const {
      return(reinterpret_cast<Control::curses_window_t>(impl_->window()));
    }
  }
}
