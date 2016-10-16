#include <terminal/toolkit/TabItem.hpp>
#include <terminal/toolkit/TabFolder.hpp>

namespace terminal
{
    namespace toolkit
    {
        struct TabItem::impl
        {

            string text_;
            string tooltip_;
        };

        TabItem::TabItem(TabFolder *parent) :
                    Item(parent),
                    pimpl_(new impl())
        {

        }

        TabItem::~TabItem()
        {
            delete pimpl_;
        }

        string const &TabItem::getToolTipText() const
        {
            return (pimpl_->tooltip_);
        }

        void TabItem::setText(string const &s)
        {

        }

        void TabItem::setToolTipText(string const &s)
        {
            pimpl_->tooltip_ = s;
        }
    }
}
