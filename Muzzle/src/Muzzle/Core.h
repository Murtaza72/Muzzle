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

#ifdef MZ_ENABLE_ASSERTS
#	define MZ_ASSERT(x, ...) { if (!(x)) { MZ_ERROR("Assertion failed {0}", __VA_ARGS__); __debugbreak(); } }
#	define MZ_CORE_ASSERT(x, ...) { if (!(x)) { MZ_CORE_ERROR("Assertion failed {0}", __VA_ARGS__); __debugbreak(); } }
#else
#	define MZ_CORE_ASSERT(x, ...)
#	define MZ_ASSERT(x, ...)
#endif 