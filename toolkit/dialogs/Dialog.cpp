#include <terminal/toolkit/Dialog.hpp>

namespace terminal
{
    namespace toolkit
    {
        Dialog::Dialog(Shell *parent) :
                    parent_(parent)
        {

        }

        Dialog::~Dialog()
        {

        }

        Shell *Dialog::getParent() const
        {
            return parent_;
        }

        string const &Dialog::getText() const
        {
            return text_;
        }

        void Dialog::setText(string const &text)
        {
            text_ = text;
        }
    }
}
