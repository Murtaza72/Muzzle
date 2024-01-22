#pragma once

#include "Core.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Muzzle {

	class MUZZLE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// core log macros
#define MZ_CORE_TRACE(...)		::Muzzle::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MZ_CORE_INFO(...)		::Muzzle::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MZ_CORE_WARN(...)		::Muzzle::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MZ_CORE_ERROR(...)		::Muzzle::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MZ_CORE_CRITICAL(...)	::Muzzle::Log::GetCoreLogger()->critical(__VA_ARGS__)

// client log macros
#define MZ_TRACE(...)			::Muzzle::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MZ_INFO(...)			::Muzzle::Log::GetClientLogger()->info(__VA_ARGS__)
#define MZ_WARN(...)			::Muzzle::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MZ_ERROR(...)			::Muzzle::Log::GetClientLogger()->error(__VA_ARGS__)
#define MZ_CRITICAL(...)		::Muzzle::Log::GetClientLogger()->critical(__VA_ARGS__)
