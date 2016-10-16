#ifndef TERMINAL_TOOLKIT_WIDGET_HPP_
#define TERMINAL_TOOLKIT_WIDGET_HPP_

#include <cstdlib>
#include <stdint.h>
#include "Types.hpp"

namespace terminal
{
    namespace toolkit
    {
        class Display;
        class Event;
        class Listener;

        class Widget
        {
        public:
            Widget(Widget *parent);
            virtual ~Widget();

            virtual Display *getDisplay() const;

            virtual bool isDisposed() const;
            virtual bool isListening(int event) const;

            virtual void addListener(int event, Listener *);
            virtual void notifyListeners(int event, Event const &) const;
            virtual void removeListener(int event, Listener *);

            virtual void paint() const = 0;

        private:
            struct impl;
            impl *pimpl_;
        };
    }
}

#endif
