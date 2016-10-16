#ifndef TERMINAL_TOOLKIT_KEYLISTENER_HPP_
#define TERMINAL_TOOLKIT_KEYLISTENER_HPP_

#include <terminal/toolkit/EventListener.hpp>

namespace terminal
{
    namespace toolkit
    {
        class KeyEvent;

        class KeyListener: public EventListener
        {
        public:
            virtual void keyPressed(const KeyEvent &) = 0;
            virtual void keyReleased(const KeyEvent &) = 0;
            virtual void keyTyped(const KeyEvent &) = 0;

        private:
        };
    }
}

#endif
