################################################
#this part is default Win configuration file
#

message(STATUS "AIX-config loaded")

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -X64")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -X64")

add_definitions(-DAIX -DPIC)

#disable RPATH usage
SET(CMAKE_SKIP_BUILD_RPATH TRUE)
