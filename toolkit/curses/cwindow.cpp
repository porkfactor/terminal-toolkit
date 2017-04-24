#include <terminal/toolkit/ttcurses.h>
#include <terminal/toolkit/Rectangle.hpp>
#include <terminal/toolkit/Point.hpp>

#if !defined (_XOPEN_SOURCE_EXTENDED)
#define _XOPEN_SOURCE_EXTENDED
#endif

#if defined (__linux__)
#include <ncursesw/curses.h>
#else
#include <curses.h>
#endif

namespace terminal
{
    namespace toolkit
    {
        cwindow::cwindow(Rectangle const &r) :
            handle_(::newwin(r.y(), r.x(), r.height(), r.width()))
        {

        }

        cwindow::cwindow(cwindow const &parent, Rectangle const &r) :
            handle_(::derwin(static_cast<WINDOW *>(parent.handle()), r.y(), r.x(), r.height(), r.width()))
        {

        }

        cwindow::~cwindow()
        {
            delwin(static_cast<WINDOW *>(handle_));
        }

        void cwindow::initialize(void)
        {
            ::initscr();
            ::start_color();

            for(uint16_t f = 0; f < COLORS; f++)
            {
                for(uint16_t b = 0; b < COLORS; b++)
                {
                    ::init_pair((f * COLORS) + b, f, b);
                }
            }
        }

        void cwindow::terminate(void)
        {
            endwin();
        }

        void cwindow::refresh(void)
        {
            ::wrefresh(static_cast<WINDOW *>(handle_));
        }

        void cwindow::resize(Rectangle const &r)
        {
            ::wresize(static_cast<WINDOW *>(handle_), r.height(), r.width());
        }

        void cwindow::setCaret(Point const &p)
        {
            ::wmove(static_cast<WINDOW *>(handle_), p.y(), p.x());
        }

        int cwindow::getKey(int timeout)
        {
            ::timeout(timeout);
            ::raw();
            ::noecho();
            ::keypad(static_cast<WINDOW *>(handle_), TRUE);

            return ::wgetch(static_cast<WINDOW *>(handle_));
        }

        void cwindow::drawRectangle(Rectangle const &r, Color const &c)
        {
            wattrset(static_cast<WINDOW *>(handle_), COLOR_PAIR((COLOR_WHITE * COLORS) | COLOR_BLACK));

            for(auto y = 0; y < r.height(); y++)
            {
                for(auto x = 0; x < r.width(); x++)
                {
                    mvwaddch(static_cast<WINDOW *>(handle_), r.y() + y, r.x() + x, ' ');
                }
            }
        }

        void cwindow::drawText(string const &s, Rectangle const &r, Color const &c)
        {
            wattrset(static_cast<WINDOW *>(handle_), COLOR_PAIR((COLOR_WHITE * COLORS) | COLOR_BLACK));

            for(auto i = 0U; i < s.length(); i++)
            {
                mvwaddwstr(static_cast<WINDOW *>(handle_), r.y(), r.x(), s.c_str());
            }
        }
    }
}

