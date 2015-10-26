#ifndef TERMINAL_TOOLKIT_TABITEM_HPP_
#define TERMINAL_TOOLKIT_TABITEM_HPP_

#include <terminal/toolkit/Item.hpp>
#include <string>

namespace terminal {
  namespace toolkit {
    class Control;
    class Image;
    class Item;
    class Rectangle;
    class TabFolder;

    class TabItem : public Item {
    public:
      TabItem(TabFolder *);
      virtual ~TabItem();

      Rectangle getBounds() const;
      Control *getControl() const;
      TabFolder *getParent() const;
      const std::wstring &getToolTipText() const;
      void setControl(Control *control);
      void setImage(Image *image);
      void setText(const std::wstring &string);
      void setToolTipText(const std::wstring &string);

    private:
      struct impl;
      std::unique_ptr<impl> pimpl_;
    };
  }
}

#endif
