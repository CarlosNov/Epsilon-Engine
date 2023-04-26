#pragma once

#include "Epsilon/Core.h"
#include "Epsilon/Log.h"

#ifdef EPS_ENABLE_ASSERTS

	#define EPS_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { EPS##type##LOG_ERROR(msg); EPS_DEBUGBREAK(); } }
	#define EPS_INTERNAL_ASSERT_WITH_MSG(type, check, ...) EPS_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__))
	#define EPS_INTERNAL_ASSERT_WITHOUT_MSG(type, check) EPS_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", EPS_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	// If there is only one argument, the macro expands to a call to EPS_INTERNAL_ASSERT_WITHOUT_MSG.
	// If there are two arguments, the macro expands to a call to EPS_INTERNAL_ASSERT_WITH_MSG.
	#define EPS_INTERNAL_ASSERT_GET_MACRO(arg1, arg2, macro, ...) macro
	#define EPS_INTERNAL_ASSERT__CHECK_MACRO(...) EPS_EXPAND_MACRO(EPS_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__, EPS_INTERNAL_ASSERT_WITH_MSG, EPS_INTERNAL_ASSERT_WITHOUT_MSG)

	#define EPS_ASSERT(...) EPS_EXPAND_MACRO(EPS_INTERNAL_ASSERT__CHECK_MACRO(__VA_ARGS__)(_, __VA_ARGS__))
	#define EPS_CORE_ASSERT(...) EPS_EXPAND_MACRO(EPS_INTERNAL_ASSERT__CHECK_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__))
#else
	#define EPS_ASSERT(...)
	#define EPS_CORE_ASSERT(...)
#endif