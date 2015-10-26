#ifndef TERMINAL_TOOLKIT_CURSES_H_
#define TERMINAL_TOOLKIT_CURSES_H_

#if !defined (_XOPEN_SOURCE_EXTENDED)
#define _XOPEN_SOURCE_EXTENDED
#endif

#if defined (__linux__)
#include <ncursesw/curses.h>
#else
#include <curses.h>
#endif

#endif
