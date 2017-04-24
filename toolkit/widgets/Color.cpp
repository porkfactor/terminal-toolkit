#include <terminal/toolkit/Color.hpp>
#include <terminal/toolkit/Rectangle.hpp>
#include <terminal/toolkit/ttcurses.h>

#if !defined (_XOPEN_SOURCE_EXTENDED)
#define _XOPEN_SOURCE_EXTENDED
#endif

#if defined (__linux__)
#include <ncursesw/curses.h>
#else
#include <curses.h>
#endif



namespace terminal {
  namespace toolkit {
    Color::Color(
        Color::color_t foreground,
        Color::color_t background,
        Color::attribute_t attribute) :
        foreground_(foreground),
        background_(background),
        attribute_(attribute)
    {

    }

    int Color::native() const
    {
        return COLOR_PAIR((foreground_ * COLORS) | background_);
    }
  }
}


