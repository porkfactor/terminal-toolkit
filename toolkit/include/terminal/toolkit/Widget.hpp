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
            typedef std::size_t size_type;
            typedef int event_type;

            Widget(Widget *parent);
            virtual ~Widget();

            virtual Display *getDisplay() const;

            virtual bool isDisposed() const;
            virtual bool isListening(int event) const;

            /**
             * @brief Add an event listener
             *
             * @param eventType
             * @param listener
             */
            virtual void addListener(event_type eventType, Listener *listener);

            /**
             * @brief Notify listeners
             *
             * @param eventType
             * @param event
             */
            virtual void notifyListeners(event_type eventType, Event const &event) const;

            /**
             * @brief Remove an event listener
             *
             * @param eventType
             * @param listener
             */
            virtual void removeListener(event_type eventType, Listener *listener);

            virtual void paint() const = 0;

        private:
            struct impl;
            impl *pimpl_;
        };
    }
}

#endif
