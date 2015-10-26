################################################
#this part is default Win configuration file
#

message(STATUS "SunOS-config loaded")

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64 -xcode=pic32")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64 -xcode=pic32 -library=stlport4")

add_definitions(-DSOLARIS -DPIC)

#disable RPATH usage
SET(CMAKE_SKIP_BUILD_RPATH TRUE)
