message(STATUS "UpdateProps Started")
message(STATUS "workDir:${workDir}")
file(GLOB_RECURSE fileLst "${workDir}/*build.properties" "${workDir}/*plugin.properties")
message(STATUS "fileLst:${fileLst}")
foreach(item IN LISTS fileLst)
	message(STATUS "item:${item}")
	file(READ ${item} fileCont)
	string(REPLACE "$version.number" "${prgVer}.${majorVer}" fileCont ${fileCont})
	string(REPLACE "$build.hash" "${gitHash}" fileCont ${fileCont})
	string(REPLACE "$build.number" "${minorVer}" fileCont ${fileCont})
	string(REPLACE "$build.date" "${BUILDDATE}" fileCont ${fileCont})
	string(REPLACE "$build.year" "${BUILDYEAR}" fileCont ${fileCont})
	file(WRITE ${item} ${fileCont})
endforeach()
