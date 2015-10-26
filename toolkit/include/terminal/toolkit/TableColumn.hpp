#ifndef TERMINAL_TOOLKIT_TABLECOLUMN_HPP_
#define TERMINAL_TOOLKIT_TABLECOLUMN_HPP_

#include <terminal/toolkit/Item.hpp>

namespace terminal {
  namespace toolkit {
    class Table;

    class TableColumn : public Item {
    public:
      TableColumn(Table *);
      virtual ~TableColumn();

      Table *getParent() const;

      virtual uint32_t getWidth() const;

      virtual void setText(const std::wstring &);
      virtual void setWidth(uint32_t);

    private:
      struct TableColumnImpl;
      std::unique_ptr<TableColumnImpl> pimpl_;
    };
  }
}

#endif
