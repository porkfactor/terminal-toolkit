#ifndef TERMINAL_TOOLKIT_FOCUSEVENT_HPP_
#define TERMINAL_TOOLKIT_FOCUSEVENT_HPP_

#include <terminal/toolkit/TypedEvent.hpp>

namespace terminal
{
    namespace toolkit
    {
        class FocusEvent: public TypedEvent
        {
        public:
            FocusEvent(const Event &e) :
                TypedEvent(e)
            {

            }
        };
    }
}

#endif
