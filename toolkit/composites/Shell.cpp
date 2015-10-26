#include <terminal/toolkit/Shell.hpp>
#include <terminal/toolkit/Display.hpp>
#include <terminal/toolkit/Point.hpp>
#include <terminal/toolkit/Rectangle.hpp>
#include <ttcurses.h>

namespace terminal {
  namespace toolkit {
    struct Shell::ShellImpl {
      ShellImpl(Shell *parent, Display *display, Shell::style_t style) :
        display_(display),
        parent_(parent),
        style_(style),
        window_(nullptr)
      {
        if(parent_) {
          window_ = ::derwin(reinterpret_cast<WINDOW *>(parent->window()), 0, 0, 0, 0);
        } else {
          window_ = ::newwin(0, 0, 0, 0);
        }
      }

      ~ShellImpl() {
        ::delwin(window_);
      }

      Display *display_;
      Shell *parent_;
      Shell::style_t style_;
      WINDOW *window_;
    };

    Shell::Shell(Display *display, Shell::style_t style) :
      Composite(nullptr),
      pimpl_(new ShellImpl(nullptr, display, style))
    {
    }

    Shell::Shell(Shell *parent, Shell::style_t style) :
      Composite(parent),
      pimpl_(new ShellImpl(parent, Display::getDefault(), style))
    {

    }

    Shell::~Shell() {

    }

    Display *Shell::getDisplay() const {
      return(pimpl_->display_);
    }

    Shell *Shell::getShell() const {
      return(const_cast<Shell *>(this));
    }

    bool Shell::getEnabled() const {
      return(false);
    }

    bool Shell::getFullScreen() const {
      return(false);
    }

    bool Shell::getModified() const {
      return(false);
    }

    void Shell::setEnabled(bool) {

    }

    void Shell::setFullScreen(bool) {

    }

    void Shell::setVisible(bool) {

    }

    Rectangle Shell::getBounds() const {
      return(Control::getBounds());
    }

    Point Shell::getLocation() const {
      return(Point(0, 0));
    }

    Point Shell::getMinimumSize() const {
      return(Point(0, 0));
    }

    Point Shell::getSize() const {
      return(Point(0, 0));
    }

    void Shell::setMinimumSize(uint32_t, uint32_t) {

    }

    void Shell::setMinimumSize(const Point &) {

    }

    bool Shell::handleKeyEvent(int, Event &) {
      return(false);
    }

    bool Shell::post(Event *event) {
      return(false);
    }

    Control *Shell::getFocusControl() const {
      // TODO : temp bodge
      return(getChildren().front());
    }

    void Shell::open() {
      pimpl_->display_->setActiveShell(this);
      Rectangle r(getBounds());

      ::wresize(pimpl_->window_, r.height(), r.width());
      ::box(pimpl_->window_, 0, 0);
      ::wrefresh(pimpl_->window_);
    }

    uintptr_t Shell::window() const {
      return(reinterpret_cast<uintptr_t>(pimpl_->window_));
    }
  }
}


