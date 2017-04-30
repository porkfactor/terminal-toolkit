#include <terminal/toolkit/Composite.hpp>
#include <terminal/toolkit/Point.hpp>
#include <terminal/toolkit/Keys.hpp>
#include <terminal/toolkit/ttcurses.h>
#include <vector>
#include <algorithm>

namespace terminal
{
    namespace toolkit
    {
        Composite::Composite(Composite *parent) :
            Scrollable(parent),
            focus_(nullptr)
        {

        }

        Composite::~Composite()
        {

        }

        void Composite::addChild(Control *child)
        {
            children_.push_back(child);
            // TODO: this is not the way to do it
            tab_list_.push_back(child);
        }

        Point Composite::computeSize(uint32_t, uint32_t, bool) const
        {
            return Point(0, 0);
        }

        void Composite::layout(bool, bool)
        {

        }

        Layout *Composite::getLayout() const
        {
            return nullptr;
        }

        bool Composite::setFocus()
        {
            return Control::setFocus();
        }

        void Composite::setLayout(Layout *)
        {

        }

        void Composite::setLayoutDeferred(bool)
        {

        }

        void Composite::paint() const
        {
            std::for_each(children_.begin(), children_.end(), [](Control *c) { c->paint(); });

            window().refresh();
        }

        const std::vector<Control *> &Composite::getChildren() const
        {
            return children_;
        }

        const std::vector<Control *> &Composite::getTabList() const
        {
            return tab_list_;
        }

        Control *Composite::getFocusControl() const
        {
            return focus_;
        }

        bool Composite::focusFirst()
        {
            bool rv { false };

            if((rv = !tab_list_.empty()) == true)
            {
                focus_ = *tab_list_.begin();
                focus_->setFocus();
            }

            return rv;
        }

        bool Composite::focusLast()
        {
            bool rv { false };

            if((rv = !tab_list_.empty()) == true)
            {
                focus_ = *tab_list_.rbegin();
                focus_->setFocus();
            }

            return rv;
        }

        bool Composite::focusNext()
        {
            bool rv { false };

            auto end { tab_list_.end() };
            for(auto i = tab_list_.begin(); i != end; ++i)
            {
                if(*i == focus_)
                {
                    auto j { i + 1 };

                    if(j != end)
                    {
                        rv = ((focus_ = *j) != nullptr);
                    }
                }
            }

            return rv;
        }

        bool Composite::focusPrevious()
        {
            bool rv { false };

            auto end { tab_list_.end() };
            for(auto i = tab_list_.begin(); i != end; ++i)
            {
                if(*i == focus_)
                {
                    auto j { i - 1 };

                    if(j != end)
                    {
                        rv = ((focus_ = *j) != nullptr);
                    }
                }
            }

            return rv;
        }

        bool Composite::handleKeyEvent(Key const &key)
        {
            bool rv { false };

            switch(key.vk())
            {
            case Key::ENTER:
            case Key::TAB:
                rv = focusNext() || focusFirst();
                break;

            default:
                break;
            }

            return rv;
        }
    }
}
