#include <terminal/toolkit/Group.hpp>
#include <terminal/toolkit/Rectangle.hpp>
#include <terminal/toolkit/Point.hpp>
#include <ncursesw/curses.h>

namespace terminal
{
    namespace toolkit
    {
        struct Group::impl
        {
            impl(Composite *parent) :
                        window_(0)
            {
                if(parent)
                {
                    window_ = ::derwin(reinterpret_cast<WINDOW *>(parent->window()), 0, 0, 0, 0);
                }
            }

            ~impl()
            {
                if(window_)
                {
                    ::delwin(window_);
                }
            }

            string text_;
            WINDOW *window_;
        };

        Group::Group(Composite *parent) :
                    Composite(parent),
                    pimpl_(new impl(parent))
        {

        }

        Group::~Group()
        {
            delete pimpl_;
        }

        void Group::setText(string const &text)
        {
            pimpl_->text_ = text;
        }

        string const &Group::getText() const
        {
            return (pimpl_->text_);
        }

        Point Group::computeSize(uint32_t x, uint32_t y, bool) const
        {
            return (Point(0, 0));
        }

        Rectangle Group::computeTrim(uint32_t x, uint32_t y, uint32_t width, uint32_t height) const
        {
            return (Rectangle(x - 1, y - 1, width + 2, height + 2));
        }

        Rectangle Group::getClientArea() const
        {
            const Rectangle bounds(getBounds());

            return (Rectangle(bounds.x() + 1, bounds.y() + 1, bounds.width() - 2, bounds.height() - 2));
        }

        void Group::paint() const
        {
            wattrset(pimpl_->window_, color());
            box(pimpl_->window_, 0, 0);
            mvwaddstr(reinterpret_cast<WINDOW *>(pimpl_->window_), 0, 2, reinterpret_cast<const char *>(pimpl_->text_.c_str()));

            Composite::paint();
        }
    }
}

