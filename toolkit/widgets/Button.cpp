#include <terminal/toolkit/Button.hpp>
#include <terminal/toolkit/Composite.hpp>
#include <terminal/toolkit/Point.hpp>
#include <terminal/toolkit/Rectangle.hpp>
#include <terminal/toolkit/ttcurses.h>

namespace terminal {
  namespace toolkit {
    struct Button::ButtonImpl {
      ButtonImpl() :
        greyed_(false),
        selection_(false)
      {
      }

      std::wstring text_;
      bool greyed_;
      bool selection_;
    };

    Button::Button(Composite *parent) :
      Control(parent),
      pimpl_(new ButtonImpl())
    {

    }

    Button::~Button() {

    }

    Point Button::computeSize(uint32_t, uint32_t, bool = false) const {
      return(Point(0, 0));
    }

    bool Button::getGreyed() const {
      return(pimpl_->greyed_);
    }

    bool Button::getSelection() const {
      return(pimpl_->selection_);
    }

    void Button::setGreyed(bool greyed) {
      pimpl_->greyed_ = greyed;
    }

    void Button::setSelection(bool selection) {
      pimpl_->selection_ = selection;
    }

    bool Button::setFocus() {
      return(Control::setFocus());
    }

    std::wstring const &Button::getText() const {
      return(pimpl_->text_);
    }

    void Button::setText(const std::wstring &text) {
      pimpl_->text_ = text;
    }

    void Button::addSelectionListener(SelectionListener *listener) {

    }

    void Button::removeSelectionListener(SelectionListener *listener) {

    }

    void Button::paint() const {
      Rectangle r(getBounds());
      WINDOW *window = reinterpret_cast<WINDOW *>(getParent()->window());

      wattrset(window, color() | A_REVERSE);
      mvwaddwstr(window, r.y(), r.x(), pimpl_->text_.c_str());
    }

    bool Button::handleKeyEvent(int key, Event &event) {
      bool rv = false;

      switch(key) {
      case '\n':
      case ' ':

        rv = true;
        break;
      }

      return(rv);
    }
  }
}


