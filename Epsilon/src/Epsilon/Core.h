#pragma once

#ifdef EPS_PLATFORM_WINDOWS
	#ifdef EPS_BUILD_DLL
		#define EPSILON_API __declspec(dllexport)
	#else
		#define EPSILON_API __declspec(dllimport)
	#endif
#else
	#error Epsilon only supports Windows!
#endif

#ifdef EPS_DEBUG
	#if defined(EPS_PLATFORM_WINDOWS)
		#define EPS_DEBUGBREAK() __debugbreak()
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define EPS_ENABLE_ASSERTS
#else
	#define HZ_DEBUGBREAK()
#endif

#define DEFINE_BIT(x) (1 << x)

#define EPS_EXPAND_MACRO(x) x
#define EPS_STRINGIFY_MACRO(x) #x
