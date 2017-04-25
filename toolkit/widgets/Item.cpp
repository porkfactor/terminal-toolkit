#include <terminal/toolkit/Item.hpp>
#include <string>

namespace terminal
{
    namespace toolkit
    {
        Item::Item(Widget *parent) :
            Widget(parent)
        {
        }

        Item::~Item()
        {

        }

        string const &Item::getText() const
        {
            return text_;
        }

        void Item::setText(string const &text)
        {
            text_ = text;
        }
    }
}

