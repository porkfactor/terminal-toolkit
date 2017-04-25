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
        Text::Text(Composite *parent) :
            Scrollable(parent),
            caret_position_(0, 0),
            text_limit_(10)
        {
        }

        Text::~Text()
        {
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
            return caret_position_.y();
        }

        Point const &Text::getCaretLocation() const
        {
            return caret_position_;
        }

        uint32_t Text::getCaretPosition() const
        {
            return caret_position_.x();
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
            return text_;
        }

        size_t Text::getTextLimit() const
        {
            return text_limit_;
        }

        void Text::setSelection(uint32_t, uint32_t)
        {

        }

        void Text::setSelection(Point const &)
        {

        }

        void Text::setText(string const &text)
        {
            text_ = text;
        }

        void Text::setTextLimit(size_t limit)
        {
            text_limit_ = limit;
        }

        void Text::paint() const
        {
            cwindow &w { window() };

            w.drawRectangle(getBounds(), Color());
            w.drawText(text_, getBounds(), Color());

            w.setCaret(Point { getBounds().x() + caret_position_.x(), getBounds().y() + caret_position_.y() } );
        }

        bool Text::handleKeyEvent(Key const &key)
        {
            switch(key.vk())
            {
            case Key::BACKSPACE:
                if(caret_position_.x() > 0)
                {
                    caret_position_ = Point(caret_position_.x() - 1, caret_position_.y());
                    text_.erase(caret_position_.x(), 1);
                }
                break;

            case Key::DELETE:
                if(caret_position_.x() < text_.length())
                {
                    text_.erase(caret_position_.x(), 1);
                }
                break;

            case Key::LEFT:
                if(caret_position_.x() > 0)
                {
                    caret_position_ = Point(caret_position_.x() - 1, caret_position_.y());
                }
                break;

            case Key::RIGHT:
                if(caret_position_.x() < this->getBounds().width())
                {
                    caret_position_ = Point(caret_position_.x() + 1, caret_position_.y());
                }
                break;

            case Key::ENTER:
                break;

            default:
                if(text_.length() < text_limit_)
                {
                    text_.insert(text_.begin() + caret_position_.x(), static_cast<string::value_type>(key.code()));
                    caret_position_ = Point(caret_position_.x() + 1, caret_position_.y());
                }
                break;
            }

            return false;
        }
    }
}
