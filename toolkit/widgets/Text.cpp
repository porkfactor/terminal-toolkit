#include <terminal/toolkit/Text.hpp>
#include <terminal/toolkit/Point.hpp>
#include <terminal/toolkit/Rectangle.hpp>
#include <terminal/toolkit/Keys.hpp>
#include <terminal/toolkit/Color.hpp>
#include <terminal/toolkit/ttcurses.h>

namespace terminal
{
    namespace toolkit
    {
        struct Text::impl
        {
            impl() :
                caret_position_(0, 0),
                text_limit_(10)
            {
            }

            Point caret_position_;
            uint32_t text_limit_;
            string text_;
        };

        Text::Text(Composite *parent) :
            Scrollable(parent),
            pimpl_(new impl())
        {
        }

        Text::~Text()
        {
            delete pimpl_;
        }

        /* Clipboard */
        void Text::cut()
        {

        }

        void Text::copy()
        {

        }

        void Text::paste()
        {

        }

        /* Control-specific behaviour */
        void Text::clearSelection()
        {

        }

        uint32_t Text::getCaretLineNumber() const
        {
            return pimpl_->caret_position_.y();
        }

        Point Text::getCaretLocation() const
        {
            return pimpl_->caret_position_;
        }

        uint32_t Text::getCaretPosition() const
        {
            return pimpl_->caret_position_.x();
        }

        uint32_t Text::getLineCount() const
        {
            return 0;
        }

        Point Text::getSelection() const
        {
            return Point(0, 0);
        }

        uint32_t Text::getSelectionCount() const
        {
            return 0;
        }

        string Text::getSelectionText() const
        {
            return L"";
        }

        string const &Text::getText() const
        {
            return pimpl_->text_;
        }

        size_t Text::getTextLimit() const
        {
            return pimpl_->text_limit_;
        }

        void Text::setSelection(uint32_t, uint32_t)
        {

        }

        void Text::setSelection(Point const &)
        {

        }

        void Text::setText(string const &text)
        {
            pimpl_->text_ = text;
        }

        void Text::setTextLimit(size_t limit)
        {
            pimpl_->text_limit_ = limit;
        }

        void Text::paint() const
        {
            window().drawRectangle(getBounds(), Color());
            window().drawText(pimpl_->text_, getBounds(), Color());

            window().setCaret(Point { getBounds().x() + pimpl_->caret_position_.x(), getBounds().y() + pimpl_->caret_position_.y() } );
        }

        bool Text::handleKeyEvent(Key const &key)
        {
            switch(key.vk())
            {
            case Key::BACKSPACE:
                if(pimpl_->caret_position_.x() > 0)
                {
                    pimpl_->caret_position_ = Point(pimpl_->caret_position_.x() - 1, pimpl_->caret_position_.y());
                    pimpl_->text_.erase(pimpl_->caret_position_.x(), 1);
                }
                break;

            case Key::DOWN:
                if(pimpl_->caret_position_.x() < pimpl_->text_.length())
                {
                    pimpl_->text_.erase(pimpl_->caret_position_.x(), 1);
                }
                break;

            case Key::LEFT:
                if(pimpl_->caret_position_.x() > 0)
                {
                    pimpl_->caret_position_ = Point(pimpl_->caret_position_.x() - 1, pimpl_->caret_position_.y());
                }
                break;

            case Key::RIGHT:
                if(pimpl_->caret_position_.x() < this->getBounds().width())
                {
                    pimpl_->caret_position_ = Point(pimpl_->caret_position_.x() + 1, pimpl_->caret_position_.y());
                }
                break;

            case Key::ENTER:
                break;

            default:
                if(pimpl_->text_.length() < pimpl_->text_limit_)
                {
                    pimpl_->text_.insert(pimpl_->text_.begin() + pimpl_->caret_position_.x(), static_cast<string::value_type>(key.code()));
                    pimpl_->caret_position_ = Point(pimpl_->caret_position_.x() + 1, pimpl_->caret_position_.y());
                }
                break;
            }

            return false;
        }
    }
}
