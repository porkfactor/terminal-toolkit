#ifndef TERMINAL_TOOLKIT_KEYEVENT_HPP_
#define TERMINAL_TOOLKIT_KEYEVENT_HPP_

#include "TypedEvent.hpp"
#include "Keys.hpp"
#include <stdint.h>

namespace terminal
{
    namespace toolkit
    {
        class KeyEvent: public TypedEvent
        {
        public:
            KeyEvent(Event const &e) :
                TypedEvent(e),
                key_(e.key)
            {

            }

            Key key() const { return key_; };

            Key key_;
        };
    }
}

#endif
