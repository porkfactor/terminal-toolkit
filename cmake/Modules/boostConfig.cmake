#----boost_PARAMETERS----#
set(boost_FOUND TRUE)
# set(boost_INCLUDE_DIR ${BOOST_HOME}/include)
# set(boost_LIB_DIR ${BOOST_HOME}/lib)

add_library(boost_date_time STATIC IMPORTED)
add_library(boost_filesystem STATIC IMPORTED)
add_library(boost_graph STATIC IMPORTED)
add_library(boost_iostreams STATIC IMPORTED)
add_library(boost_math_c99 STATIC IMPORTED)
add_library(boost_math_c99f STATIC IMPORTED)
add_library(boost_math_c99l STATIC IMPORTED)
add_library(boost_math_tr1 STATIC IMPORTED)
add_library(boost_math_tr1f STATIC IMPORTED)
add_library(boost_math_tr1l STATIC IMPORTED)
add_library(boost_program_options STATIC IMPORTED)
add_library(boost_random STATIC IMPORTED)
add_library(boost_regex STATIC IMPORTED)
add_library(boost_system STATIC IMPORTED)
add_library(boost_unit_test_framework STATIC IMPORTED)

if(WIN32)
  if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
    set(BUILD_MODE "gd-")
  else()
    set(BUILD_MODE "")
  endif()

  set(BOOST_SUFFIX "-${TOOLSET}0-mt-${BUILD_MODE}1_46_1.lib")

  set_target_properties(
    boost_date_time 
    PROPERTIES
    IMPORTED_LOCATION libboost_date_time${BOOST_SUFFIX}
  )

  set_target_properties(
    boost_filesystem
    PROPERTIES
    IMPORTED_LOCATION libboost_filesystem${BOOST_SUFFIX}
  )

  set_target_properties(
    boost_program_options
    PROPERTIES
    IMPORTED_LOCATION libboost_program_options${BOOST_SUFFIX}
  )

  set_target_properties(
    boost_regex
    PROPERTIES
    IMPORTED_LOCATION libboost_regex${BOOST_SUFFIX}
  )

  set_target_properties(
    boost_system
    PROPERTIES
    IMPORTED_LOCATION libboost_system${BOOST_SUFFIX}
  )

  set_target_properties(
    boost_unit_test_framework
    PROPERTIES
    IMPORTED_LOCATION libboost_unit_test_framework${BOOST_SUFFIX}
  )
else()
  set_target_properties(
    boost_filesystem 
    PROPERTIES
    IMPORTED_LOCATION ${BOOST_HOME}/lib/libboost_filesystem.a
  )

  set_target_properties(
    boost_graph 
    PROPERTIES
    IMPORTED_LOCATION ${BOOST_HOME}/lib/libboost_graph.a
  )

  set_target_properties(
    boost_program_options
    PROPERTIES
    IMPORTED_LOCATION ${BOOST_HOME}/lib/libboost_program_options.a
  )

  set_target_properties(
    boost_regex
    PROPERTIES
    IMPORTED_LOCATION ${BOOST_HOME}/lib/libboost_regex.a
  )
  
  set_target_properties(
    boost_system
    PROPERTIES
    IMPORTED_LOCATION ${BOOST_HOME}/lib/libboost_system.a
  )

  set_target_properties(
    boost_unit_test_framework
    PROPERTIES
    IMPORTED_LOCATION ${BOOST_HOME}/lib/libboost_unit_test_framework.a
  )
endif()


