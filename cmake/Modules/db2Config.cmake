
#----db2_PARAMETERS----#
set(db2_FOUND TRUE)
set(db2_INCLUDE_DIR ${DB2_HOME}/include)
if(WIN32)
	if(BUS EQUAL 64)
		set(db2_LIB_DIR ${DB2_HOME}/lib/Win64)
	else()
		set(db2_LIB_DIR ${DB2_HOME}/lib)
	endif()
else()
	set(db2_LIB_DIR ${DB2_HOME}/lib)
endif()

if(WIN32)
	set(db2_LIBS db2api db2cli)
else()
	set(db2_LIBS db2)
endif()
#----db2_PARAMETERS----#