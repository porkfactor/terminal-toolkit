#----curses_PARAMETERS----#
set(curses_FOUND TRUE)
# set(curses_INCLUDE_DIR ${CURSES_HOME}/include)
# set(curses_LIB_DIR ${CURSES_HOME}/lib)

if(WIN32)
	set(curses_LIBS panel${DBGPOSTFIX} pdcurses${DBGPOSTFIX})
elseif(APPLE)
	set(curses_LIBS curses)
else()
	set(curses_LIBS ncursesw)
endif()
#----curses_PARAMETERS----#
