#include <terminal/toolkit/Menu.hpp>
#include <terminal/toolkit/MenuItem.hpp>
#include <terminal/toolkit/Control.hpp>
#include <algorithm>

namespace terminal
{
    namespace toolkit
    {
        Menu::Menu(Control *parent) :
            Widget(parent)
        {
        }

        Menu::Menu(Menu *parent) :
            Widget(parent)
        {
        }

        Menu::Menu(MenuItem *item) :
            Widget(item->getParent())
        {
        }

        Menu::~Menu()
        {

        }

        MenuItem *Menu::getDefaultItem() const
        {
            return (0);
        }

        uint32_t Menu::getItemCount() const
        {
            return (items_.size());
        }

        std::vector<MenuItem *> Menu::getItems() const
        {
            return (items_);
        }

        MenuItem *Menu::getItem(Control::index_t index) const
        {
            MenuItem *rv = 0;

            if(index < items_.size())
            {
                rv = items_[index];
            }

            return (rv);
        }

        int32_t Menu::indexOf(const MenuItem *item) const
        {
            int32_t rv = -1;
            auto it = std::find(items_.begin(), items_.end(), item);

            if(it != items_.end())
            {
                rv = std::distance(items_.begin(), it);
            }

            return (rv);
        }

        void Menu::paint() const
        {

        }
    }
}

