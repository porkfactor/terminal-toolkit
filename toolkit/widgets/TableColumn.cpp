#include <terminal/toolkit/TableColumn.hpp>
#include <terminal/toolkit/Table.hpp>

namespace terminal {
  namespace toolkit {
    struct TableColumn::TableColumnImpl {
      TableColumnImpl() :
        width_(0)
      {
      }

      uint32_t width_;
    };

    TableColumn::TableColumn(Table *parent) :
      Item(parent),
      pimpl_(new TableColumnImpl())
    {
    }

    TableColumn::~TableColumn() {

    }

    uint32_t TableColumn::getWidth() const {
      return(pimpl_->width_);
    }

    void TableColumn::setText(const std::wstring &text) {
      Item::setText(text);
    }

    void TableColumn::setWidth(uint32_t) {

    }
  }
}

