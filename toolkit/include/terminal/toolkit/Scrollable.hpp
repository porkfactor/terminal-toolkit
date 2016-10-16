#ifndef TERMINAL_TOOLKIT_ISCROLLABLE_HPP_
#define TERMINAL_TOOLKIT_ISCROLLABLE_HPP_

#include <terminal/toolkit/Control.hpp>

namespace terminal
{
    namespace toolkit
    {
        class ScrollBar;

        class Scrollable: public Control
        {
        public:
            Scrollable(Composite *);
            virtual ~Scrollable();

            Rectangle computeTrim(uint32_t, uint32_t, uint32_t, uint32_t);
            Rectangle getClientArea() const;
            ScrollBar *getHorizontalBar() const;
            ScrollBar *getVerticalBar() const;
        };
    }
}

#endif
