
#----informix_PARAMETERS----#
set(informix_FOUND TRUE)
set(informix_INCLUDE_DIR ${INFORMIX_HOME}/incl/esql  ${INFORMIX_HOME}/incl)
set(informix_LIB_DIR ${INFORMIX_HOME}/lib ${INFORMIX_HOME}/lib/esql)

FILE(TO_NATIVE_PATH ${INFORMIX_HOME} informixDirNative)
SET(oldInformixDir $ENV{INFORMIXDIR})
SET(oldPath $ENV{PATH})

SET(ENV{INFORMIXDIR} "${informixDirNative}")#setting proper environment for Informix tools
if(WIN32)
	set(PATHES_SEP ";")
	set(PATH_SEP "\\")
else()
	set(PATHES_SEP ":")
	set(PATH_SEP "/")
endif()

SET(ENV{PATH} "$ENV{PATH}${PATHES_SEP}${INFORMIX_HOME}${PATH_SEP}lib")#setting proper environment for Informix tools

execute_process(COMMAND ${INFORMIX_HOME}/bin/esql -libs RESULT_VARIABLE result OUTPUT_VARIABLE infLibs)

SET(ENV{PATH} "${oldPath}")
SET(ENV{INFORMIXDIR} "${oldInformixDir}")

if(NOT result EQUAL 0)
	message(SEND_ERROR "${INFORMIX_HOME}/bin/esql execution error:${result}")
else()
	set(informix_LIBS)
	if(WIN32)
		string(REPLACE "Libraries to be used:\n" "" infLibs ${infLibs})#removes not needed part
	
		separate_arguments(infLibs WINDOWS_COMMAND "${infLibs}")
		
		foreach(item IN LISTS infLibs)
			file(TO_CMAKE_PATH ${item} item)
			string(REPLACE "\"" "" item ${item})
			string(STRIP ${item} item)
			if(IS_ABSOLUTE ${item})
				file(RELATIVE_PATH shortItem ${INFORMIX_HOME}/lib  ${item})
			else()
				set(shortItem ${item})
			endif()
			LIST(APPEND informix_LIBS ${shortItem})
		endforeach()
	else()
		string(REPLACE "-l" "" infLibs ${infLibs})
		string(REPLACE "\n" ";" infLibs ${infLibs})
		set(informix_LIBS ${infLibs})
	endif()
endif()
#----informix_PARAMETERS----#
