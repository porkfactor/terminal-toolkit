#include <terminal/toolkit/TabFolder.hpp>
#include <terminal/toolkit/Point.hpp>
#include <terminal/toolkit/Rectangle.hpp>
#include <terminal/toolkit/SelectionListener.hpp>

namespace terminal
{
    namespace toolkit
    {
        TabFolder::TabFolder(Composite *parent) :
                    Composite(parent)
        {
        }

        TabFolder::~TabFolder()
        {

        }

        TabItem *TabFolder::getItem(const Point &p) const
        {
            return (0);
        }

        TabItem *TabFolder::getItem(Control::index_t index) const
        {
            TabItem *rv = 0;

            if(index < items_.size())
            {
                rv = items_[index];
            }

            return (rv);
        }

        uint32_t TabFolder::getItemCount() const
        {
            return (items_.size());
        }

        void TabFolder::addSelectionListener(SelectionListener *listener)
        {

        }

        Point TabFolder::computeSize(int wHint, int hHint, bool changed) const
        {
            Point rv(0, 0);

            return (rv);
        }

        Rectangle TabFolder::computeTrim(int x, int y, int width, int height) const
        {
            Rectangle rv(0, 0, 0, 0);

            return (rv);
        }

        Rectangle TabFolder::getClientArea() const
        {
            Rectangle rv(0, 0, 0, 0);

            return (rv);
        }

        std::vector<TabItem *> TabFolder::getItems() const
        {
            std::vector<TabItem *> rv;

            return (rv);
        }

        std::vector<TabItem *> TabFolder::getSelection() const
        {
            std::vector<TabItem *> rv;

            return (rv);
        }

        Control::index_t TabFolder::getSelectionIndex() const
        {
            Control::index_t rv(Control::npos);

            return (rv);
        }

        Control::index_t TabFolder::indexOf(const TabItem *item) const
        {
            Control::index_t rv(Control::npos);

            return (rv);
        }

        void TabFolder::removeSelectionListener(SelectionListener *listener)
        {

        }

        void TabFolder::setSelection(Control::index_t index)
        {

        }

        void TabFolder::setSelection(TabItem *item)
        {

        }

        void TabFolder::setSelection(std::vector<TabItem *> items)
        {

        }

        void TabFolder::paint() const
        {

        }
    }
}

