#include <terminal/toolkit/Combo.hpp>
#include <algorithm>

namespace terminal
{
    namespace toolkit
    {
        Combo::Combo(Composite *parent) :
            Composite(parent)
        {
        }

        void Combo::add(string const &s)
        {
            items_.push_back(s);
        }

        void Combo::add(string const &s, Control::index_t index)
        {
            items_[index] = s;
        }

        void Combo::addModifyListener(ModifyListener *listener)
        {

        }

        void Combo::addSelectionListener(SelectionListener *listener)
        {

        }

        void Combo::addVerifyListener(VerifyListener *listener)
        {

        }

        void Combo::clearSelection()
        {

        }

        void Combo::copy()
        {

        }

        void Combo::cut()
        {

        }

        void Combo::paste()
        {

        }

        string Combo::getItem(Control::index_t index) const
        {
            return items_[index];
        }

        uint32_t Combo::getItemCount() const
        {
            return items_.size();
        }

        uint32_t Combo::indexOf(string const &s) const
        {
            return indexOf(s, 0);
        }

        uint32_t Combo::indexOf(string const &s, Control::index_t index) const
        {
            uint32_t rv = -1;
            auto it = std::find(items_.begin() + index, items_.end(), s);

            if(it != items_.end())
            {
                rv = std::distance(items_.begin(), it);
            }

            return rv;
        }

        void Combo::remove(Control::index_t index)
        {
            if(index < items_.size())
            {
                items_.erase(items_.begin() + index);
            }
        }

        void Combo::remove(Control::index_t start, Control::index_t end)
        {
            items_.erase(items_.begin() + start, items_.begin() + end);
        }

        void Combo::remove(string const &s)
        {
            items_.erase(std::find(items_.begin(), items_.end(), s));
        }

        void Combo::removeAll()
        {
            items_.clear();
        }
    }
}

