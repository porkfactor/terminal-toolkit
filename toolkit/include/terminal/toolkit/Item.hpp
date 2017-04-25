#ifndef TERMINAL_TOOLKIT_ITEM_HPP_
#define TERMINAL_TOOLKIT_ITEM_HPP_

#include "Widget.hpp"

namespace terminal {
  namespace toolkit {
    class Item : public Widget {
    public:
      Item(Widget *);
      virtual ~Item();

      virtual const string &getText() const;
      virtual void setText(const string &);

    private:
      string text_;
    };
  }
}

#endif
