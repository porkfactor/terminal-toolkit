#include <terminal/toolkit/Combo.hpp>
#include <algorithm>

namespace terminal
{
    namespace toolkit
    {
        struct Combo::impl
        {
            std::vector<string> items_;
        };

        Combo::Combo(Composite *parent) :
            Composite(parent),
            pimpl_(new impl())
        {
        }

        void Combo::add(string const &s)
        {
            pimpl_->items_.push_back(s);
        }

        void Combo::add(string const &s, Control::index_t index)
        {
            pimpl_->items_[index] = s;
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
            return pimpl_->items_[index];
        }

        uint32_t Combo::getItemCount() const
        {
            return pimpl_->items_.size();
        }

        uint32_t Combo::indexOf(string const &s) const
        {
            return indexOf(s, 0);
        }

        uint32_t Combo::indexOf(string const &s, Control::index_t index) const
        {
            uint32_t rv = -1;
            auto it = std::find(pimpl_->items_.begin() + index, pimpl_->items_.end(), s);

            if(it != pimpl_->items_.end())
            {
                rv = std::distance(pimpl_->items_.begin(), it);
            }

            return rv;
        }

        void Combo::remove(Control::index_t index)
        {
            if(index < pimpl_->items_.size())
            {
                pimpl_->items_.erase(pimpl_->items_.begin() + index);
            }
        }

        void Combo::remove(Control::index_t start, Control::index_t end)
        {
            pimpl_->items_.erase(pimpl_->items_.begin() + start, pimpl_->items_.begin() + end);
        }

        void Combo::remove(string const &s)
        {
            pimpl_->items_.erase(std::find(pimpl_->items_.begin(), pimpl_->items_.end(), s));
        }

        void Combo::removeAll()
        {
            pimpl_->items_.clear();
        }
    }
}

