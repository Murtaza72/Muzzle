#pragma once

#ifdef MZ_PLATFORM_WINDOWS
#	ifdef MZ_BUILD_DLL
#		define MUZZLE_API __declspec(dllexport)
#	else
#		define MUZZLE_API __declspec(dllimport)
#	endif
#else
#	error Muzzle only supports Windows!
#endif

#define BIT(x) (1 << x)