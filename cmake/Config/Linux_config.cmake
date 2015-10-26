################################################
#this part is default Win configuration file
#

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_SHARED_MODULE_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

add_definitions(-std=c++0x)

if(BUS64)
  add_definitions(-m64)
else()
  add_definitions(-m32)
endif()

add_definitions(-DLINUX -fPIC)

SET(CMAKE_SKIP_BUILD_RPATH TRUE)
