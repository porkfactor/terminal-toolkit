#include <terminal/toolkit/TableItem.hpp>
#include <terminal/toolkit/Table.hpp>
#include <terminal/toolkit/Rectangle.hpp>
#include <terminal/toolkit/Color.hpp>
#include <vector>

namespace terminal {
  namespace toolkit {
    struct Cell {
      Color foreground_;
      Color background_;
      string text_;
    };

    struct TableItem::impl {
        impl() :
        parent_(nullptr)
      {

      }

      Table *parent_;
      std::vector<Cell *> data_;
    };

    TableItem::TableItem(Table *parent) :
      Item(parent),
      pimpl_(new impl())
    {
    }

    TableItem::~TableItem() {

    }

    Table *TableItem::getParent() const {
      return(pimpl_->parent_);
    }

    Color TableItem::getBackground() const {
      return(getBackground(0));
    }

    Color TableItem::getBackground(Control::index_t index) const {
      return(pimpl_->data_[index]->background_);
    }

    Color TableItem::getForeground() const {
      return(getForeground(0));
    }

    Color TableItem::getForeground(Control::index_t index) const {
      return(pimpl_->data_[index]->foreground_);
    }

    void TableItem::setBackground(Color color) {
      setBackground(0, color);
    }

    void TableItem::setBackground(Control::index_t index, Color color) {
      pimpl_->data_[index]->background_ = color;
    }

    void TableItem::setForeground(Color color) {
      setForeground(0, color);
    }

    void TableItem::setForeground(Control::index_t index, Color color) {
      pimpl_->data_[index]->foreground_ = color;
    }

    Rectangle TableItem::getBounds() const {
      return(Rectangle(0, 0, 0, 0));
    }

    Rectangle TableItem::getBounds(Control::index_t index) {
      return(Rectangle(0, 0, 0, 0));
    }

    string const &TableItem::getText() const {
      return(getText(0));
    }

    string const &TableItem::getText(Control::index_t index) const {
      return(pimpl_->data_[index]->text_);
    }

    void TableItem::setText(string const &text) {
      setText(0, text);
    }

    void TableItem::setText(Control::index_t index, string const &text) {
      pimpl_->data_[index]->text_= text;
    }
  }
}
