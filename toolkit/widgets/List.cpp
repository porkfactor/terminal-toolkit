#include <terminal/toolkit/List.hpp>
#include <terminal/toolkit/Point.hpp>
#include <terminal/toolkit/SelectionListener.hpp>
#include <algorithm>

namespace terminal
{
    namespace toolkit
    {
        struct List::impl
        {

            std::vector<string> items_;
        };

        List::List(Composite *parent) :
            Scrollable(parent),
            pimpl_(new impl())
        {

        }

        void List::add(string const &item)
        {
            pimpl_->items_.push_back(item);
        }

        void List::add(string const &item, Control::index_t index)
        {

        }

        void List::addSelectionListener(SelectionListener *listener)
        {

        }

        Point List::computeSize(int wHint, int hHint, bool changed) const
        {
            return Point { 0, 0 };
        }

        void List::deselect(Control::index_t index)
        {

        }

        void List::deselect(std::vector<Control::index_t> const &indices)
        {

        }

        void List::deselect(Control::index_t start, Control::index_t end)
        {

        }

        void List::deselectAll()
        {

        }

        Control::index_t List::getFocusIndex() const
        {
            Control::index_t rv(Control::npos);

            return (rv);
        }

        string List::getItem(Control::index_t index) const
        {
            string rv;

            return (rv);
        }

        uint32_t List::getItemCount() const
        {
            uint32_t rv(0);

            rv = pimpl_->items_.size();

            return (rv);
        }

        uint32_t List::getItemHeight() const
        {
            uint32_t rv(0);

            return (rv);
        }

        std::vector<string> List::getItems() const
        {
            return (pimpl_->items_);
        }

        std::vector<string> List::getSelection() const
        {
            std::vector<string> rv;

            return (rv);
        }

        Control::index_t List::getSelectionCount() const
        {
            Control::index_t rv(Control::npos);

            return (rv);
        }

        Control::index_t List::getSelectionIndex() const
        {
            Control::index_t rv(Control::npos);

            return (rv);
        }

        std::vector<Control::index_t> List::getSelectionIndices() const
        {
            return (std::vector<Control::index_t>());
        }

        Control::index_t List::getTopIndex() const
        {
            Control::index_t rv(Control::npos);

            return (rv);
        }

        Control::index_t List::indexOf(string const &string) const
        {
            Control::index_t rv(Control::npos);
            decltype(pimpl_->items_.begin()) it;

            if((it = std::find(pimpl_->items_.begin(), pimpl_->items_.end(), string)) != pimpl_->items_.end())
            {
                rv = std::distance(pimpl_->items_.begin(), it);
            }

            return (rv);
        }

        Control::index_t List::indexOf(string const &string, Control::index_t start) const
        {
            Control::index_t rv(Control::npos);

            return (rv);
        }

        bool List::isSelected(Control::index_t index) const
        {
            return (false);
        }

        void List::remove(Control::index_t index)
        {
            pimpl_->items_.erase(pimpl_->items_.begin() + index);
        }

        void List::remove(std::vector<Control::index_t> const &indices)
        {

        }

        void List::remove(Control::index_t start, Control::index_t end)
        {
            pimpl_->items_.erase(pimpl_->items_.begin() + start, pimpl_->items_.begin() + end);
        }

        void List::remove(string string)
        {

        }

        void List::removeAll()
        {
            pimpl_->items_.clear();
        }

        void List::removeSelectionListener(SelectionListener *listener)
        {

        }

        void List::select(Control::index_t index)
        {

        }

        void List::select(std::vector<Control::index_t> const &indices)
        {

        }

        void List::select(Control::index_t start, Control::index_t end)
        {

        }

        void List::selectAll()
        {

        }

        void List::setItem(Control::index_t index, string const &string)
        {

        }

        void List::setItems(std::vector<string> const &)
        {

        }

        void List::setSelection(Control::index_t index)
        {

        }

        void List::setSelection(std::vector<Control::index_t> const &indices)
        {

        }

        void List::setSelection(Control::index_t start, Control::index_t end)
        {

        }

        void List::setSelection(std::vector<string> const &indices)
        {

        }
        void List::setTopIndex(Control::index_t index)
        {

        }

        void List::showSelection()
        {

        }
    }
}
