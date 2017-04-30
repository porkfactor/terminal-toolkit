#include <terminal/toolkit/Group.hpp>
#include <terminal/toolkit/Rectangle.hpp>
#include <terminal/toolkit/Point.hpp>

namespace terminal
{
    namespace toolkit
    {
        Group::Group(Composite *parent) :
            Composite(parent)
        {

        }

        Group::~Group()
        {
        }

        void Group::setText(string const &text)
        {
            text_ = text;
        }

        string const &Group::getText() const
        {
            return text_;
        }

        Point Group::computeSize(uint32_t x, uint32_t y, bool) const
        {
            return Point(0, 0);
        }

        Rectangle Group::computeTrim(uint32_t x, uint32_t y, uint32_t width, uint32_t height) const
        {
            return Rectangle(x - 1, y - 1, width + 2, height + 2);
        }

        Rectangle Group::getClientArea() const
        {
            const Rectangle bounds(getBounds());

            return Rectangle(bounds.x() + 1, bounds.y() + 1, bounds.width() - 2, bounds.height() - 2);
        }

        void Group::paint() const
        {
#if 0
            cwindow &window { window() };

            wattrset(pimpl_->window_, color());
            box(pimpl_->window_, 0, 0);
            mvwaddstr(reinterpret_cast<WINDOW *>(pimpl_->window_), 0, 2, reinterpret_cast<const char *>(pimpl_->text_.c_str()));
#endif

            Composite::paint();
        }
    }
}

