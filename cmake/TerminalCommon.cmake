message(STATUS "TelesoftCommon")

set(configFound)

MACRO(DUMPVAR varName)
  message(STATUS "${varName}:${${varName}}")
ENDMACRO()

MACRO(CHECKENVVAR Var)
  if(NOT ${Var})
    message(SEND_ERROR "Environment variable ${Var} is not set")
  endif()
ENDMACRO()

MACRO(CHECKVAR Var)
  if(NOT ${Var})
    message(SEND_ERROR "Variable ${Var} should be set to continue")
  endif()
ENDMACRO()

MACRO(DisableTarget targetName)
  set(${targetName}_DISABLE ON)
ENDMACRO()

MACRO(SetConfVariable varName envVarName defaultVal)
  if(NOT DEFINED ${varName})
    set(envVal $ENV{${envVarName}})
    if(envVal)
      file(TO_CMAKE_PATH ${envVal} envVal)
      set(${varName} ${envVal})
    else()
      set(${varName} ${defaultVal})
    endif()
  endif()
ENDMACRO()


set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/Config ${CMAKE_CURRENT_LIST_DIR}/Modules $ENV{CMAKE_CURRENT_LIST_DIR})

if(WIN32)
  FILE(TO_CMAKE_PATH $ENV{USERPROFILE} userProfile)
  LIST(APPEND CMAKE_MODULE_PATH ${userProfile})#appending userhome directory to modules search path
else()
  LIST(APPEND CMAKE_MODULE_PATH "~")
endif()

DUMPVAR(CMAKE_MODULE_PATH)

include(UserVariables OPTIONAL RESULT_VARIABLE userVariablesExists)
if(NOT userVariablesExists)
  message(STATUS "UserVariables.cmake not found at:${CMAKE_MODULE_PATH}")
endif()

include(${CMAKE_CURRENT_LIST_DIR}/SystemVariables.cmake)

if(BUS EQUAL 64)
  set(BUS64 ON) #define extra variables for easier usage
else()
  set(BUS32 ON) #define extra variables for easier usage
ENDIF()

set(ConfigName "${CMAKE_SYSTEM}_config")

include(${ConfigName} OPTIONAL RESULT_VARIABLE configFound)
if(NOT configFound)
  message(STATUS "File \"${ConfigName}\" not found")
  set(ConfigName "${CMAKE_SYSTEM_NAME}_config")
  message(STATUS "Will look for \"${ConfigName}\"")
  include(${ConfigName} OPTIONAL RESULT_VARIABLE configFound)
  if(NOT configFound)
    message(STATUS "File \"${ConfigName}\" not found")  
  endif()
endif()
#----End configs support section

#----Profiles support section
set(userProfileName UserProfile)
include(${userProfileName} OPTIONAL RESULT_VARIABLE userProfileFound)
if(NOT userProfileFound)
  message(STATUS "User specific profile file \"${userProfileName}.cmake\" not found at:${CMAKE_MODULE_PATH}")
endif()
#----End profiles support section


MACRO(MAX RESULT ITEMS)
  SET(LST ${ARGV})
  LIST(REMOVE_ITEM LST RESULT)
  LIST(SORT LST)
  list(REVERSE LST)
  list(GET LST 0 ${RESULT})
ENDMACRO(MAX)

MACRO(MIN RESULT ITEMS)
  SET(LST ${ARGV})
  LIST(REMOVE_ITEM LST RESULT)
  LIST(SORT LST)
  list(GET LST 0 ${RESULT})
ENDMACRO(MIN)

MACRO(MacroTraceOn macroName)
  SET(${macroName}_TRACE ON)
ENDMACRO()

FUNCTION(TRACE_MSG traceVarName msgString)
if(${traceVarName}_TRACE)
  message(STATUS ${msgString})
endif()
ENDFUNCTION(TRACE_MSG)

###QFindLibraryRoot###Macro
MACRO(QFindLibraryRoot macro_libRootToSet macro_searchPattern macro_rootPathToFind macro_possibleSuffixes macro_errorMessage)
  set(macro_libRootToSet)

if(QFindLibraryRoot_TRACE)  
  message(STATUS "QFindLibraryRoot(${ARGV0}, ${ARGV1}, ${ARGV2}, ${ARGV3}, ${ARGV4}")
endif()
  
  find_path(${macro_libRootToSet} NAMES ${macro_searchPattern} HINTS ${macro_rootPathToFind} PATH_SUFFIXES ${macro_possibleSuffixes})
  if(${macro_libRootToSet})
  else()
    message(${macro_errorMessage})
  endif()
ENDMACRO(QFindLibraryRoot)

MACRO(ShowPackageParts package)
TRACE_MSG(ShowPackageParts "ShowPackageParts(${ARGV})")

if(NOT ${package}_FOUND)
  find_package(${package} REQUIRED PATHS ${CMAKE_MODULE_PATH})
endif()

MESSAGE(STATUS "\"${package}\" parts:${${package}_PARTS}")
ENDMACRO()

MACRO(TDUsePackage package)
  set(TDUsePackageParams ${ARGV})

  if(NOT ${package}_FOUND)
    find_package(${package} REQUIRED PATHS ${CMAKE_MODULE_PATH})
    set($package}_FOUND TRUE)#set to true to avoid multiple inclusion
  endif()

  if(${package}_INCLUDE_DIR)
    include_directories(${${package}_INCLUDE_DIR})
  endif()

  if(${package}_LIB_DIR)
    link_directories(${${package}_LIB_DIR})
  endif()
  
  LIST(FIND TDUsePackageParams PART partIdx)

  if(partIdx EQUAL -1)
    if(${package}_LIBS)
      LIST(APPEND QuerixCommonLibs ${${package}_LIBS})
      if(QuerixCommonLibs)
        LIST(REMOVE_DUPLICATES QuerixCommonLibs)
      endif()
    endif()
  else()
    list(LENGTH TDUsePackageParams argsCount)
    math(EXPR argsCount "${argsCount} - 1")
    foreach(idx RANGE 1 ${argsCount})
      if(idx GREATER partIdx)
        list(GET TDUsePackageParams ${idx} item)

        if(DEFINED ${package}_${item}_LIBS)
          set(partLibs ${${package}_${item}_LIBS})
          
          LIST(APPEND QuerixCommonLibs ${partLibs})
          if(QuerixCommonLibs)
            LIST(REMOVE_DUPLICATES QuerixCommonLibs)
          endif()
        else()
          message(SEND_ERROR "Uknown package \"${package}\" part \"${item}\" was used")
        endif()
      endif()
    endforeach()
  endif()
ENDMACRO(TDUsePackage)

