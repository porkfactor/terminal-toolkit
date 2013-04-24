#ifndef TERMINAL_TOOLKIT_TABLE_HPP_
#define TERMINAL_TOOLKIT_TABLE_HPP_

#include <platform/platform.hpp>
#include <api/c++/Composite.hpp>

namespace terminal {
  namespace toolkit {
    class TableColumn;
    class TableItem;

    class DLLEXPORT Table : public Composite {
    public:
      Table(composite_ptr parent);
      virtual ~Table();

      TableItem *createItem();
      TableColumn *createColumn();

      void clear(uint32_t index);
      void clear(uint32_t start, uint32_t end);
      void clearAll();

      void deselect(uint32_t index);
      void deselect(uint32_t start, uint32_t end);
      void deselectAll();

      void setSelection(uint32_t index);
      void setSelection(uint32_t start, uint32_t end);
      void setSelection(const TableItem &item);

      uint32_t indexOf(const TableItem &item) const;
      uint32_t indexOf(const TableColumn &column) const;

      TableItem getItem(uint32_t index) const;
      TableColumn getColumn(uint32_t index) const;

      uint32_t getColumnCount() const;
      uint32_t getItemCount() const;

    protected:
      virtual void paint() const;

    private:
      class TableImpl;
      TableImpl *impl_;
    };
  }
}

#endif

