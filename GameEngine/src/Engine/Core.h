#pragma once

/*
* Defines dll macro for building
* When building the Engine, it will use dllexport
* When building the application, it will use dllimport
* (Defined in: ProjectProperties -> C/C++ -> Preprocessor -> Preprocessor Definitions)
*/

#ifdef ENGINE_PLATFORM_WINDOWS
#ifdef ENGINE_BUILD_DLL
#define ENGINE_API __declspec(dllexport)
#else 
#define ENGINE_API __declspec(dllimport)
#endif
#else
#error Engine only supports Windows!
#endif
