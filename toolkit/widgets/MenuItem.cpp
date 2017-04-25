#include <terminal/toolkit/MenuItem.hpp>
#include <terminal/toolkit/Menu.hpp>

namespace terminal
{
    namespace toolkit
    {
        MenuItem::MenuItem(Menu *parent) :
                    Item(parent),
                    parent_(parent),
                    menu_(nullptr),
                    enabled_(true)
        {
        }

        MenuItem::~MenuItem()
        {

        }

        Menu *MenuItem::getParent() const
        {
            return parent_;
        }

        Menu *MenuItem::getMenu() const
        {
            return menu_;
        }

        bool MenuItem::getEnabled() const
        {
            return enabled_;
        }

        void MenuItem::setEnabled(bool enabled)
        {
            enabled_ = enabled;
        }

        void MenuItem::setMenu(Menu *menu)
        {
            menu_ = menu;
        }

        void MenuItem::setText(string const &)
        {

        }
    }
}

