#include <terminal/toolkit/TableColumn.hpp>
#include <terminal/toolkit/Table.hpp>

namespace terminal
{
    namespace toolkit
    {
        TableColumn::TableColumn(Table *parent) :
            Item(parent),
            width_(0)
        {
        }

        TableColumn::~TableColumn()
        {
        }

        uint32_t TableColumn::getWidth() const
        {
            return width_;
        }

        void TableColumn::setText(const string &text)
        {
            Item::setText(text);
        }

        void TableColumn::setWidth(uint32_t)
        {

        }
    }
}

