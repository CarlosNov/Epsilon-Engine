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
