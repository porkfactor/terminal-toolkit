#include <api/c++/Table.hpp>
#include <api/c++/TableItem.hpp>
#include <api/c++/TableColumn.hpp>
#include <api/c++/Rectangle.hpp>
#include <memory>
#include <curses.h>

namespace terminal {
  namespace toolkit {
    class Table::TableImpl {
    public:

      std::vector<std::unique_ptr<TableColumn> > columns_;
      std::vector<std::unique_ptr<TableItem> > rows_;
    };

    Table::Table(composite_ptr parent) :
      Composite(parent),
      impl_(new TableImpl())
    {
      
    }

    Table::~Table() {
      delete impl_;
    }

    TableItem *Table::createItem() {
      TableItem *rv = new TableItem(this);

      if(rv) {
        impl_->rows_.push_back(std::unique_ptr<TableItem>(rv));
      }

      return(rv);
    }

    TableColumn *Table::createColumn() {
      TableColumn *rv = new TableColumn(this);

      if(rv) {
        impl_->columns_.push_back(std::unique_ptr<TableColumn>(rv));
      }

      return(rv);
    }

    void Table::clear(uint32_t start, uint32_t end) {
    }

    void Table::clearAll() {
      impl_->rows_.clear();
    }

    void Table::deselect(uint32_t index) {
    }

    void Table::deselect(uint32_t start, uint32_t end) {
    }

    void Table::deselectAll() {
    }

    void Table::setSelection(uint32_t index) {
    }

    void Table::setSelection(uint32_t start, uint32_t end) {
    }

    void Table::setSelection(const TableItem &item) {
    }

    uint32_t Table::indexOf(const TableItem &item) const {
      uint32_t rv = 0;

      for(uint32_t i = 0; i < impl_->rows_.size(); i++) {
        if(impl_->rows_[i].get() == &item) {
          rv = i;
          break;
        }
      }

      return(rv);
    }

    uint32_t Table::indexOf(const TableColumn &column) const {
      uint32_t rv = 0;

      for(uint32_t i = 0; i < impl_->columns_.size(); i++) {
        if(impl_->columns_[i].get() == &column) {
          rv = i;
          break;
        }
      }

      return(rv);
    }

    uint32_t Table::getColumnCount() const {
      return(static_cast<uint32_t>(impl_->columns_.size()));
    }

    uint32_t Table::getItemCount() const {
      return(static_cast<uint32_t>(impl_->rows_.size()));
    }

    void Table::paint() const {
      WINDOW *window = reinterpret_cast<WINDOW *>(this->window());
      Rectangle r(getBounds());

      std::vector<std::unique_ptr<TableColumn> >::const_iterator ci;

      for(ci = impl_->columns_.begin(); ci != impl_->columns_.end(); ci++) {
        ::mvwaddstr(window, r.y(), r.x() + (*ci)->getWidth(), (*ci)->getText().c_str());

        ::wmove(window, r.y(), r.x() + (*ci)->getWidth());
        ::wvline(window, 0, r.height());
      }
    }
  }
}