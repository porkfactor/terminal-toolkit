macro(configure_msvc_runtime)
  # Set compiler options.
#  set(variables
#    CMAKE_C_FLAGS_DEBUG
#    CMAKE_C_FLAGS_MINSIZEREL
#    CMAKE_C_FLAGS_RELEASE
#    CMAKE_C_FLAGS_RELWITHDEBINFO
#    CMAKE_CXX_FLAGS_DEBUG
#    CMAKE_CXX_FLAGS_MINSIZEREL
#    CMAKE_CXX_FLAGS_RELEASE
#    CMAKE_CXX_FLAGS_RELWITHDEBINFO
#  )

#  foreach(variable ${variables})
#    if(${variable} MATCHES "/MDd")
#      string(REGEX REPLACE "/MDd" "/MD" ${variable} "${${variable}}")
#    endif()
#  endforeach()
endmacro()

message(STATUS "Windows-config loaded")

configure_msvc_runtime()

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_SHARED_MODULE_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /MD /EHsc")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MD /EHsc")

add_definitions(-DWINDOWS)
add_definitions(-DWIN32_LEAN_AND_MEAN)
add_definitions(-DNOCRYPT)
add_definitions(-D_SCL_SECURE_NO_WARNINGS)
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
  add_definitions(-DDEBUG)
endif()
