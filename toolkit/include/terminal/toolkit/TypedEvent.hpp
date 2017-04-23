#ifndef TERMINAL_TOOLKIT_TYPEDEVENT_HPP_
#define TERMINAL_TOOLKIT_TYPEDEVENT_HPP_

#include "Event.hpp"

namespace terminal
{
    namespace toolkit
    {
        class TypedEvent
        {
        public:
            TypedEvent(Event const &e) :
                display_(e.display),
                widget_(e.widget)
            {

            }

            Display *display_;
            Widget *widget_;
        };
    }
}

#endif
