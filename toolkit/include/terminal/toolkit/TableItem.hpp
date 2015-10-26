#ifndef TERMINAL_TOOLKIT_TABLEITEM_HPP_
#define TERMINAL_TOOLKIT_TABLEITEM_HPP_

#include <terminal/toolkit/Item.hpp>
#include <string>

namespace terminal {
  namespace toolkit {
    class Table;
    class Color;
    class Rectangle;

    class TableItem : public Item {
    public:
      TableItem(Table *);
      virtual ~TableItem();

      virtual Table *getParent() const;

      virtual Color getBackground() const;
      virtual Color getBackground(uint32_t) const;
      virtual Color getForeground() const;
      virtual Color getForeground(uint32_t) const;

      virtual void setBackground(Color);
      virtual void setBackground(uint32_t, Color);
      virtual void setForeground(Color);
      virtual void setForeground(uint32_t, Color);

      virtual Rectangle getBounds() const;
      virtual Rectangle getBounds(uint32_t index);

      virtual const std::wstring &getText() const;
      virtual const std::wstring &getText(uint32_t) const;

      virtual void setText(const std::wstring &);
      virtual void setText(uint32_t, const std::wstring &);

    private:
      struct TableItemImpl;
      std::unique_ptr<TableItemImpl> pimpl_;
    };
  }
}

#endif
