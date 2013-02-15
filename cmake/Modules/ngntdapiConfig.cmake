#----ngntdapi_PARAMETERS----#
set(ngntdapi_FOUND TRUE)
set(ngntdapi_INCLUDE_DIR ${TDAPI_HOME}/include)

add_library(ngntdapi SHARED IMPORTED)

set_target_properties(ngntdapi 
  PROPERTIES 
  IMPORTED_LOCATION ${TDAPI_HOME}/libtdapi
)

#----ngntdapi_PARAMETERS----#