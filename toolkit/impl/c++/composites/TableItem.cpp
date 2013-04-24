#include <api/c++/TableItem.hpp>
#include <api/c++/Table.hpp>

namespace terminal {
  namespace toolkit {
    class TableItem::TableItemImpl {
    public:
      TableItemImpl(table_ptr parent) :
        parent_(parent)
      {
      }

      table_ptr parent_;
    };

    TableItem::TableItem(table_ptr parent) :
      Item(parent),
      impl_(new TableItemImpl(parent))
    {
    }

    TableItem::~TableItem() {
      delete impl_;
    }

    void TableItem::setText(const std::string &) {
    }

    void TableItem::setText(uint32_t index, const std::string &) {
    }

    void TableItem::paint() const {
    }
  }
}