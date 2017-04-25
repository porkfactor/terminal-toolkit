#include <terminal/toolkit/Table.hpp>
#include <terminal/toolkit/TableColumn.hpp>
#include <terminal/toolkit/TableItem.hpp>

namespace terminal {
  namespace toolkit {
    Table::Table(Composite *parent, Table::style_t style) :
      Composite(parent)
    {
    }

    Table::~Table() {

    }

    void Table::clear(Control::index_t index) {

    }

    void Table::clear(Control::index_t start, Control::index_t end) {

    }

    void Table::clearAll() {

    }

    void Table::deselect(Control::index_t) {

    }

    void Table::deselect(Control::index_t start, Control::index_t end) {

    }

    void Table::deselectAll() {

    }

    TableColumn *Table::getColumn(Control::index_t index) const {
      return(0);
    }

    size_t Table::getColumnCount() const {
      return(0);
    }

    TableItem *Table::getItem(Control::index_t index) const {
      return(0);
    }

    size_t Table::getItemCount() const {
      return(0);
    }

    void Table::remove(Control::index_t index) {

    }

    void Table::remove(Control::index_t start, Control::index_t end) {

    }

    void Table::removeAll() {

    }

    void Table::select(Control::index_t index) {

    }

    void Table::select(Control::index_t start, Control::index_t end) {

    }

    void Table::selectAll() {

    }

    void Table::setSelection(TableItem *item) {

    }

    void Table::setSelection(Control::index_t index) {

    }

    void Table::setSelection(Control::index_t start, Control::index_t end) {

    }

    void Table::setSortColumn(TableColumn *column) {
      if(column != 0) {

      }
    }

    void Table::setSortDirection(direction_t direction) {
      switch(direction) {
      case UP:
        break;

      case DOWN:
        break;

      case NONE:
        break;
      }
    }

    void Table::showColumn(TableColumn *) {

    }

    void Table::showItem(TableItem *) {

    }

    void Table::showSelection() {

    }
  }
}
