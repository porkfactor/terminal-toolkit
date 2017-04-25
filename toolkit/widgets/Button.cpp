#include <terminal/toolkit/Button.hpp>
#include <terminal/toolkit/Composite.hpp>
#include <terminal/toolkit/Point.hpp>
#include <terminal/toolkit/Rectangle.hpp>
#include <terminal/toolkit/KeyEvent.hpp>
#include <terminal/toolkit/SelectionListener.hpp>
#include <terminal/toolkit/SelectionEvent.hpp>
#include <terminal/toolkit/ttcurses.h>

namespace terminal
{
    namespace toolkit
    {
        Button::Button(Composite *parent) :
            Control(parent),
            greyed_(false),
            selection_(false)
        {

        }

        Button::~Button()
        {
        }

        Point Button::computeSize(uint32_t, uint32_t, bool = false) const
        {
            return Point(0, 0);
        }

        bool Button::getGreyed() const
        {
            return greyed_;
        }

        bool Button::getSelection() const
        {
            return selection_;
        }

        void Button::setGreyed(bool greyed)
        {
            greyed_ = greyed;
        }

        void Button::setSelection(bool selection)
        {
            selection_ = selection;
        }

        bool Button::setFocus()
        {
            return (Control::setFocus());
        }

        string const &Button::getText() const
        {
            return (text_);
        }

        void Button::setText(const string &text)
        {
            text_ = text;
        }

        void Button::addSelectionListener(SelectionListener *listener)
        {
            selectionListeners_.push_back(listener);
        }

        void Button::removeSelectionListener(SelectionListener *listener)
        {

        }

        void Button::paint() const
        {
#if 0
            Rectangle r(getBounds());
            WINDOW *window = reinterpret_cast<WINDOW *>(getParent()->window());



            wattrset(window, color() | A_REVERSE);
            mvwaddwstr(window, r.y(), r.x(), text_.c_str());
#endif
        }

        bool Button::handleKeyEvent(Key const &key)
        {
            bool rv = false;

            switch(key.vk())
            {
            case Key::ENTER:
                for(auto i : selectionListeners_)
                {
                    i->widgetSelected(SelectionEvent(Event()));
                }
                rv = true;
                break;

            default:
                break;
            }

            return (rv);
        }
    }
}
