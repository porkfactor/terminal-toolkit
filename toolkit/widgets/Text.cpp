#include <terminal/toolkit/Text.hpp>
#include <terminal/toolkit/Point.hpp>
#include <terminal/toolkit/Rectangle.hpp>
#include <terminal/toolkit/ttcurses.h>

namespace terminal {
  namespace toolkit {
    struct Text::TextImpl {
      TextImpl() :
        caret_position_(0, 0),
        text_limit_(10)
      {
      }

      Point caret_position_;
      uint32_t text_limit_;
      std::wstring text_;
    };

    Text::Text(Composite *parent) :
      Scrollable(parent),
      pimpl_(new TextImpl())
    {
    }

    Text::~Text() {
    }

    /* Clipboard */
    void Text::cut() {

    }

    void Text::copy() {

    }

    void Text::paste() {

    }

    /* Control-specific behaviour */
    void Text::clearSelection() {

    }

    uint32_t Text::getCaretLineNumber() const {
      return(pimpl_->caret_position_.y());
    }

    Point Text::getCaretLocation() const {
      return(pimpl_->caret_position_);
    }

    uint32_t Text::getCaretPosition() const {
      return(pimpl_->caret_position_.x());
    }

    uint32_t Text::getLineCount() const {
      return(0);
    }

    Point Text::getSelection() const {
      return(Point(0, 0));
    }

    uint32_t Text::getSelectionCount() const {
      return(0);
    }

    std::wstring Text::getSelectionText() const {
      return(L"");
    }

    const std::wstring &Text::getText() const {
      return(pimpl_->text_);
    }

    size_t Text::getTextLimit() const {
      return(pimpl_->text_limit_);
    }

    void Text::setSelection(uint32_t, uint32_t) {

    }

    void Text::setSelection(const Point &) {

    }

    void Text::setText(const std::wstring &text) {
      pimpl_->text_ = text;
    }

    void Text::setTextLimit(size_t limit) {
      pimpl_->text_limit_ = limit;
    }

    void Text::paint() const {
      WINDOW *w = reinterpret_cast<WINDOW *>(window());
      Rectangle r(getBounds());

      wattrset(w, color());

      mvwaddnwstr(w, r.y(), r.x(), pimpl_->text_.c_str(), pimpl_->text_.length());

      for(uint32_t i = pimpl_->text_.length(); i < r.width(); i++) {
        mvwaddch(w, r.y(), r.x() + i, ' ');
      }
    }

    bool Text::handleKeyEvent(int key, Event &event) {
      switch(key) {
      case 0x8:
      case KEY_BACKSPACE:
        if(pimpl_->caret_position_.x() > 0) {
          pimpl_->caret_position_ = Point(pimpl_->caret_position_.x() - 1, pimpl_->caret_position_.y());
          pimpl_->text_.erase(pimpl_->caret_position_.x(), 1);
          // paint();
        }
        break;

      case KEY_DC:
        if(pimpl_->caret_position_.x() < pimpl_->text_.length()) {
          pimpl_->text_.erase(pimpl_->caret_position_.x(), 1);
          // paint();
        }
        break;

      case KEY_LEFT:
        if(pimpl_->caret_position_.x() > 0) {
          pimpl_->caret_position_ = Point(pimpl_->caret_position_.x() - 1, pimpl_->caret_position_.y());
          // paint();
        }
        break;

      case KEY_RIGHT:
        break;

      case 0x9:
      case 0xa:
      case 0xd:
      case KEY_ENTER:
        break;

      default:
        if(pimpl_->text_.length() < pimpl_->text_limit_) {
           pimpl_->text_.insert(pimpl_->text_.begin() + pimpl_->caret_position_.x(), static_cast<char>(key));
           pimpl_->caret_position_ = Point(pimpl_->caret_position_.x() + 1, pimpl_->caret_position_.y());
           // paint();
        }
        break;
      }

      return(false);
    }
  }
}
