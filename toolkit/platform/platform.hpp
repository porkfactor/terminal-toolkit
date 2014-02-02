#ifndef _TERMINAL_TOOLKIT_PLATFORM_H
#define _TERMIANL_TOOLKIT_PLATFORM_H

#if defined (_WIN32) && defined(DLL__TERMINAL_TOOLKIT)
#define DLLEXPORT __declspec(dllexport)
#define DLLIMPORT __declspec(dllimport)
#else
#define DLLEXPORT
#define DLLIMPORT
#endif

#endif
