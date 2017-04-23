#ifndef TERMINAL_TOOLKIT_EVENT_HPP_
#define TERMINAL_TOOLKIT_EVENT_HPP_

#include <cstdint>
#include "Types.hpp"
#include "Keys.hpp"

namespace terminal
{
    namespace toolkit
    {
        class Display;
        class Widget;

        class Event
        {
        public:
            Event() :
                widget(nullptr),
                display(nullptr),
                key(Key::INVALID)
            {

            }

            Display *display;
            Widget *widget;

            Key key;
        };
    }
}

#endif
