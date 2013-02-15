#----zlib_PARAMETERS----#
set(zlib_FOUND TRUE)
set(zlib_INCLUDE_DIR ${RESOURCEBASE}/zlib/include)

if(WIN32)
	set(zlib_LIB_DIR ${RESOURCEBASE}/zlib/lib)
	set(zlib_LIBS zlib)
elseif(APPLE)
	set(zlib_INCLUDE_DIR ${ZLIB_HOME}/include)
	set(zlib_LIB_DIR ${ZLIB_HOME}/lib)
	set(zlib_LIBS z)
else()
	set(zlib_INCLUDE_DIR ${RESOURCEBASE}/zlib/include)
	set(zlib_LIB_DIR ${RESOURCEBASE}/zlib/lib)
	set(zlib_LIBS z)
endif()
#----zlib_PARAMETERS----#