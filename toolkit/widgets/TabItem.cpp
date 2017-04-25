#include <terminal/toolkit/TabItem.hpp>
#include <terminal/toolkit/TabFolder.hpp>

namespace terminal
{
    namespace toolkit
    {
        TabItem::TabItem(TabFolder *parent) :
            Item(parent)
        {

        }

        TabItem::~TabItem()
        {
        }

        string const &TabItem::getToolTipText() const
        {
            return (tooltip_);
        }

        void TabItem::setText(string const &s)
        {

        }

        void TabItem::setToolTipText(string const &s)
        {
            tooltip_ = s;
        }
    }
}
