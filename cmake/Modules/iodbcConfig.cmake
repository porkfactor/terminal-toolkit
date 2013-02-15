if(NOT WIN32)
	set(iodbc_FOUND TRUE)
	set(iodbc_INCLUDE_DIR ${IODBC_HOME}/include) #I didn't found anything useful in builds2 for these settings
	set(iodbc_LIB_DIR ${IODBC_HOME}/lib)
ENDIF()