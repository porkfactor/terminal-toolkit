#include <terminal/toolkit/Widget.hpp>
#include <terminal/toolkit/Listener.hpp>
#include <map>
#include <vector>

namespace terminal {
  namespace toolkit {
    struct Widget::WidgetImpl {
      WidgetImpl() {

      }

      std::unique_ptr<std::map<int, std::vector<Listener *> > > listeners_;
    };

    Widget::Widget(Widget *parent) :
      pimpl_(new WidgetImpl())
    {
    }

    Widget::~Widget() {
    }

    Display *Widget::getDisplay() const {
      return(nullptr);
    }

    bool Widget::isDisposed() const {
      return(false);
    }

    bool Widget::isListening(int event) const {
      return(false);
    }

    void Widget::addListener(int event, Listener *l) {
      if(!pimpl_->listeners_) {
        pimpl_->listeners_.reset(new std::map<int, std::vector<Listener *> >());
      }

      (*pimpl_->listeners_)[event].push_back(l);
    }

    void Widget::notifyListeners(int event, const Event &e) const {
      std::map<int, std::vector<Listener *> >::const_iterator i;

      if((i = pimpl_->listeners_->find(event)) != pimpl_->listeners_->end()) {
        const std::vector<Listener *> &listeners(i->second);

        for(auto j = listeners.begin(); j != listeners.end(); j++) {
          (*j)->handleEvent(e);
        }
      }
    }

    void Widget::removeListener(int event, Listener *l) {
      std::map<int, std::vector<Listener *> >::iterator i;

      if((i = pimpl_->listeners_->find(event)) != pimpl_->listeners_->end()) {
        std::vector<Listener *> &listeners(i->second);

        for(auto j = listeners.begin(); j != listeners.end(); j++) {
          if((*j) == l) {
            j = listeners.erase(j);
          }
        }
      }
    }
  }
}



