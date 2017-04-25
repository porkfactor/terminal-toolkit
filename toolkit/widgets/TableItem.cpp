#include <terminal/toolkit/TableItem.hpp>
#include <terminal/toolkit/Table.hpp>
#include <terminal/toolkit/Rectangle.hpp>
#include <terminal/toolkit/Color.hpp>
#include <vector>

namespace terminal
{
    namespace toolkit
    {
        struct TableItem::Cell
        {
            Color foreground_;
            Color background_;
            string text_;
        };

        TableItem::TableItem(Table *parent) :
                    Item(parent),
                    parent_(nullptr)
        {
        }

        TableItem::~TableItem()
        {

        }

        Table *TableItem::getParent() const
        {
            return parent_;
        }

        Color TableItem::getBackground() const
        {
            return getBackground(0);
        }

        Color TableItem::getBackground(Control::index_t index) const
        {
            return data_[index]->background_;
        }

        Color TableItem::getForeground() const
        {
            return getForeground(0);
        }

        Color TableItem::getForeground(Control::index_t index) const
        {
            return data_[index]->foreground_;
        }

        void TableItem::setBackground(Color color)
        {
            setBackground(0, color);
        }

        void TableItem::setBackground(Control::index_t index, Color color)
        {
            data_[index]->background_ = color;
        }

        void TableItem::setForeground(Color color)
        {
            setForeground(0, color);
        }

        void TableItem::setForeground(Control::index_t index, Color color)
        {
            data_[index]->foreground_ = color;
        }

        Rectangle TableItem::getBounds() const
        {
            return Rectangle(0, 0, 0, 0);
        }

        Rectangle TableItem::getBounds(Control::index_t index)
        {
            return Rectangle(0, 0, 0, 0);
        }

        string const &TableItem::getText() const
        {
            return getText(0);
        }

        string const &TableItem::getText(Control::index_t index) const
        {
            return data_[index]->text_;
        }

        void TableItem::setText(string const &text)
        {
            setText(0, text);
        }

        void TableItem::setText(Control::index_t index, string const &text)
        {
            data_[index]->text_ = text;
        }
    }
}
