#ifndef TERMINAL_TOOLKIT_ITEM_HPP_
#define TERMINAL_TOOLKIT_ITEM_HPP_

#include <terminal/toolkit/Widget.hpp>

namespace terminal {
  namespace toolkit {
    class Item : public Widget {
    public:
      Item(Widget *);
      virtual ~Item();

      virtual const std::wstring &getText() const;
      virtual void setText(const std::wstring &);

    private:
      struct ItemImpl;
      std::unique_ptr<struct ItemImpl> pimpl_;
    };
  }
}

#endif
