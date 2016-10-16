message(STATUS "SystemVariables found")

SetConfVariable(LIB_HOME LIB_HOME "/home/archive")
SetConfVariable(BUS BUS "64")
SetConfVariable(TOOLSET TOOLSET "clang")
SetConfVariable(OUTPUT_BASE OUTPUT_BASE ${CMAKE_BINARY_DIR})

CHECKVAR(LIB_HOME)
CHECKVAR(BUS)
CHECKVAR(TOOLSET)
CHECKVAR(OUTPUT_BASE)

SetConfVariable(LIBBASE LIB_BASE ${LIB_HOME}/${TOOLSET}/${BUS})
SetConfVariable(CURSES_HOME CURSES_DIR ${LIBBASE}/curses)
SetConfVariable(ICU_HOME ICU_DIR ${LIBBASE}/icu)
SetConfVariable(SSL_HOME SSL_DIR ${LIBBASE}/openssl)
SetConfVariable(BOOST_HOME BOOST_DIR ${LIBBASE}/boost)
SetConfVariable(ANTLR_HOME ANTLR_DIR ${LIBBASE}/antlr)
SetConfVariable(TINYXML_HOME TINYXML_DIR ${LIBBASE}/tinyxml)
SetConfVariable(ECLIPSEDIR ECLIPSEDIR ${LIB_HOME}/${BUS}/eclipse)
SetConfVariable(ORACLE_HOME ORACLE_HOME "")
SetConfVariable(INFORMIX_HOME INFORMIXDIR "")
SetConfVariable(DB2_HOME DB2DIR "")
SetConfVariable(JAVA_HOME JAVA_HOME "")
SetConfVariable(ODBC_HOME ODBC_HOME ${LIBBASE}/unixodbc)
SetConfVariable(IODBC_HOME IODBC_HOME ${LIBBASE}/iodbc)

set(InstallDir ${OUTPUT_BASE}/install)

