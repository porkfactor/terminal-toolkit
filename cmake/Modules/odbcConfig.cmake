#----odbc_PARAMETERS----#
set(odbc_FOUND TRUE)

add_library(libodbc STATIC IMPORTED)
add_library(libodbcinst STATIC IMPORTED)

if(WIN32)
  set_target_properties(
    libodbc
    PROPERTIES
    IMPORTED_LOCATION odbc32.lib
  )

  set_target_properties(
    libodbcinst
    PROPERTIES
    IMPORTED_LOCATION advapi32.lib
  )
else()
  set(odbc_include_dir ${ODBC_HOME}/include)
 
  set_target_properties(
    libodbc
    PROPERTIES
    IMPORTED_LOCATION ${ODBC_HOME}/lib/libodbc.a
  )

  set_target_properties(
    libodbcinst
    PROPERTIES
    IMPORTED_LOCATION ${ODBC_HOME}/lib/libodbcinst.a
  )
endif()

#----odbc_PARAMETERS----#
