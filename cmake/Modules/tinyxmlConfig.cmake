#----tinyxml_PARAMETERS----#
set(tinyxml_FOUND TRUE)

set(tinyxml_INCLUDE_DIR ${TINYXML_HOME}/include)
set(tinyxml_LIB_DIR ${TINYXML_HOME}/lib)

if(WIN32)
  set(tinyxml_LIBS libtinyxml)
else()
  set(tinyxml_LIBS tinyxml)
endif()

#----tinyxml_PARAMETERS----#
