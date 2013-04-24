#include <api/c++/TableColumn.hpp>
#include <api/c++/Table.hpp>
#include <curses.h>

namespace terminal {
  namespace toolkit {
    class TableColumn::TableColumnImpl {
    public:
      TableColumnImpl(table_ptr parent) :
        parent_(parent)
      {
      }

      uint16_t width_;
      table_ptr parent_;
      std::string text_;
    };

    TableColumn::TableColumn(table_ptr parent) :
      Item(parent),
      impl_(new TableColumnImpl(parent))
    {
    }

    TableColumn::~TableColumn() {
      delete impl_;
    }

    const std::string &TableColumn::getText() const {
      return(impl_->text_);
    }

    void TableColumn::setText(const std::string &text) {
      impl_->text_ = text;
    }

    table_ptr TableColumn::getParent() const {
      return(impl_->parent_);
    }

    uint16_t TableColumn::getWidth() const {
      return(impl_->width_);
    }

    void TableColumn::setWidth(uint16_t width) {
      impl_->width_ = width;
    }

    void TableColumn::paint() const {
      WINDOW *window = reinterpret_cast<WINDOW *>(getParent()->window());

      mvwaddstr(window, 1, impl_->width_, getText().c_str());
    }
  }
}
