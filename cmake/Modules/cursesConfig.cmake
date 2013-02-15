#----curses_PARAMETERS----#
set(curses_FOUND TRUE)
set(curses_INCLUDE_DIR ${CURSES_HOME}/include)
set(curses_LIB_DIR ${CURSES_HOME}/lib)

if(WIN32)
	set(curses_LIBS panel${DBGPOSTFIX} pdcurses${DBGPOSTFIX})
elseif(APPLE)
	set(curses_LIBS form  menu ncurses panel)
else()
	set(curses_LIBS ncurses panel)
endif()
#----curses_PARAMETERS----#