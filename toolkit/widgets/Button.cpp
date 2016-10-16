#include <terminal/toolkit/Button.hpp>
#include <terminal/toolkit/Composite.hpp>
#include <terminal/toolkit/Point.hpp>
#include <terminal/toolkit/Rectangle.hpp>
#include <terminal/toolkit/SelectionListener.hpp>
#include <terminal/toolkit/SelectionEvent.hpp>
#include <terminal/toolkit/ttcurses.h>

namespace terminal
{
    namespace toolkit
    {
        struct Button::impl
        {
            impl() :
                    greyed_(false), selection_(false)
            {
            }

            string text_;
            bool greyed_;
            bool selection_;
            std::vector<SelectionListener *> selectionListeners_;
        };

        Button::Button(Composite *parent) :
            Control(parent),
            pimpl_(new impl())
        {

        }

        Button::~Button()
        {
            delete pimpl_;
        }

        Point Button::computeSize(uint32_t, uint32_t, bool = false) const
        {
            return Point(0, 0);
        }

        bool Button::getGreyed() const
        {
            return pimpl_->greyed_;
        }

        bool Button::getSelection() const
        {
            return pimpl_->selection_;
        }

        void Button::setGreyed(bool greyed)
        {
            pimpl_->greyed_ = greyed;
        }

        void Button::setSelection(bool selection)
        {
            pimpl_->selection_ = selection;
        }

        bool Button::setFocus()
        {
            return (Control::setFocus());
        }

        string const &Button::getText() const
        {
            return (pimpl_->text_);
        }

        void Button::setText(const string &text)
        {
            pimpl_->text_ = text;
        }

        void Button::addSelectionListener(SelectionListener *listener)
        {
            pimpl_->selectionListeners_.push_back(listener);
        }

        void Button::removeSelectionListener(SelectionListener *listener)
        {

        }

        void Button::paint() const
        {
            Rectangle r(getBounds());
            WINDOW *window = reinterpret_cast<WINDOW *>(getParent()->window());

            wattrset(window, color() | A_REVERSE);
            mvwaddwstr(window, r.y(), r.x(), pimpl_->text_.c_str());
        }

        bool Button::handleKeyEvent(int key, Event const &event)
        {
            bool rv = false;

            switch(key)
            {
            case '\n':
            case ' ':
                for(auto i : pimpl_->selectionListeners_)
                {
                    i->widgetSelected(SelectionEvent(event));
                }
                rv = true;
                break;
            }

            return (rv);
        }
    }
}
