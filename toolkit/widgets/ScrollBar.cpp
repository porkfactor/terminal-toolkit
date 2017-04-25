#include <terminal/toolkit/ScrollBar.hpp>
#include <terminal/toolkit/Scrollable.hpp>
#include <terminal/toolkit/Rectangle.hpp>
#include <terminal/toolkit/ttcurses.h>

namespace terminal
{
    namespace toolkit
    {
        ScrollBar::ScrollBar(Scrollable *parent) :
                    Widget(parent),
                    parent_(parent),
                    increment_(1),
                    maximum_(0),
                    minimum_(0),
                    page_increment_(0),
                    selection_(0)
        {

        }

        ScrollBar::~ScrollBar()
        {
        }

        Scrollable *ScrollBar::getParent() const
        {
            return parent_;
        }

        uint32_t ScrollBar::getMaximum() const
        {
            return maximum_;
        }

        uint32_t ScrollBar::getMinimum() const
        {
            return minimum_;
        }

        uint32_t ScrollBar::getIncrement() const
        {
            return increment_;
        }

        uint32_t ScrollBar::getPageIncrement() const
        {
            return page_increment_;
        }

        uint32_t ScrollBar::getSelection() const
        {
            return selection_;
        }

        void ScrollBar::setMaximum(uint32_t maximum)
        {
            maximum_ = maximum;
        }

        void ScrollBar::setMinimum(uint32_t minimum)
        {
            minimum_ = minimum;
        }

        void ScrollBar::setIncrement(uint32_t increment)
        {
            increment_ = increment;
        }

        void ScrollBar::setPageIncrement(uint32_t increment)
        {
            page_increment_ = increment;
        }

        void ScrollBar::setSelection(uint32_t selection)
        {
            selection_ = selection;
        }

        void ScrollBar::paint() const
        {
#if 0
            WINDOW *window = reinterpret_cast<WINDOW *>(getParent()->window());
            const Rectangle &r(getParent()->getBounds());
#endif
        }
    }
}
