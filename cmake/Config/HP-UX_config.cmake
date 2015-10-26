################################################
#this part is default Win configuration file
#

message(STATUS "Linux-config loaded")

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} +DD64 -Ae -Wl,+s -fPIC")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} +DD64 -AA -Wl,+s -fPIC")

add_definitions(-DHPUX -DPIC)

#disable RPATH usage
SET(CMAKE_SKIP_BUILD_RPATH TRUE)
