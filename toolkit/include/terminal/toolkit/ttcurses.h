#ifndef TERMINAL_TOOLKIT_CURSES_H_
#define TERMINAL_TOOLKIT_CURSES_H_

#include <terminal/toolkit/Types.hpp>

namespace terminal
{
    namespace toolkit
    {
        class Rectangle;
        class Point;
        class Color;

        class cwindow final
        {
        public:
            cwindow(cwindow const &parent, Rectangle const &);
            cwindow(Rectangle const &);
            ~cwindow();

            int getKey(int timeout = -1);

            void refresh(void);
            void resize(Rectangle const &);

            void drawRectangle(Rectangle const &, Color const &);
            void drawText(string const &, Rectangle const &, Color const &);

            void setCaret(Point const &p);

            void *handle(void) const { return handle_; };

            /* temporary crap exposure */
            static void initialize();
            static void terminate();

            void bell();

        private:
            void *handle_;
        };
    }
}

#endif
