#ifndef TERMINAL_TOOLKIT_TABLE_HPP_
#define TERMINAL_TOOLKIT_TABLE_HPP_

#include <terminal/toolkit/Composite.hpp>

namespace terminal {
  namespace toolkit {
    class TableColumn;
    class TableItem;

    class Table : public Composite {
    public:
      typedef enum {
        FULL_SELECTION = 0x1,
        HIDE_SELECTION = 0x2,
        NO_SCROLL = 0x4,
        MULTI = 0x8,
        SINGLE = 0x10
      } style_t;

      typedef enum {
        UP,
        DOWN,
        NONE
      } direction_t;

      Table(Composite *, style_t);
      virtual ~Table();

      void clear(Control::index_t);
      void clear(Control::index_t, Control::index_t);
      void clearAll();
      void deselect(Control::index_t);
      void deselect(Control::index_t, Control::index_t);
      void deselectAll();
      void remove(Control::index_t);
      void remove(Control::index_t, Control::index_t);
      void removeAll();
      void select(Control::index_t);
      void select(Control::index_t, Control::index_t);
      void selectAll();
      void setSelection(Control::index_t);
      void setSelection(Control::index_t, Control::index_t);
      void setSelection(TableItem *);
      void setSortColumn(TableColumn *);
      void setSortDirection(direction_t);
      void showColumn(TableColumn *);
      void showItem(TableItem *);
      void showSelection();

      Point computeSize(uint32_t, uint32_t, bool = false);

      TableColumn *getColumn(Control::index_t) const;
      size_t getColumnCount() const;
      TableItem *getItem(Control::index_t) const;
      size_t getItemCount() const;

    private:
      struct TableImpl;
      std::unique_ptr<TableImpl> pimpl_;
    };
  }
}

#endif
