#include <terminal/toolkit/Item.hpp>
#include <string>

namespace terminal
{
    namespace toolkit
    {
        struct Item::impl
        {
            string text_;
        };

        Item::Item(Widget *parent) :
            Widget(parent),
            pimpl_(new impl())
        {
        }

        Item::~Item()
        {

        }

        string const &Item::getText() const
        {
            return (pimpl_->text_);
        }

        void Item::setText(string const &text)
        {
            pimpl_->text_ = text;
        }
    }
}

