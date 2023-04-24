#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Epsilon
{
	class EPSILON_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core Log Macros
#define EPS_CORE_LOG_TRACE(...)		::Epsilon::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define EPS_CORE_LOG_INFO(...)		::Epsilon::Log::GetCoreLogger()->info(__VA_ARGS__)
#define EPS_CORE_LOG_WARN(...)		::Epsilon::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define EPS_CORE_LOG_ERROR(...)		::Epsilon::Log::GetCoreLogger()->error(__VA_ARGS__)
#define EPS_CORE_LOG_CRITICAL(...)  ::Epsilon::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client Log Macros
#define EPS_LOG_TRACE(...)			::Epsilon::Log::GetClientLogger()->trace(__VA_ARGS__)
#define EPS_LOG_INFO(...)			::Epsilon::Log::GetClientLogger()->info(__VA_ARGS__)
#define EPS_LOG_WARN(...)			::Epsilon::Log::GetClientLogger()->warn(__VA_ARGS__)
#define EPS_LOG_ERROR(...)			::Epsilon::Log::GetClientLogger()->error(__VA_ARGS__)
#define EPS_LOG_CRITICAL(...)		::Epsilon::Log::GetClientLogger()->critical(__VA_ARGS__)