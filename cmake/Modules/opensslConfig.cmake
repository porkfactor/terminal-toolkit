#----openssl_PARAMETERS----#
set(openssl_FOUND TRUE)
set(openssl_INCLUDE_DIR ${SSL_HOME}/include)
set(openssl_LIB_DIR ${SSL_HOME}/lib)

if(WIN32)
	set(openssl_LIBS libeay32${DBGPOSTFIX} ssleay32${DBGPOSTFIX})
else()
	set(openssl_LIBS ssl${DBGPOSTFIX} crypto${DBGPOSTFIX})
endif()
#----openssl_PARAMETERS----#
