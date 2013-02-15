set(oracle_FOUND TRUE)

if(WIN32)
  set(oracle_INCLUDE_DIR ${ORACLE_HOME}/oci/include)
  set(oracle_LIB_DIR ${ORACLE_HOME}/oci/lib/msvc)
  set(oracle_LIBS oci ociw32 oraocci11)
else
  set(oracle_INCLUDE_DIR ${ORACLE_HOME}/rdbms/public)
  set(oracle_LIB_DIR ${ORACLE_HOME}/lib)
  set(oracle_LIBS clntsh)
endif()

