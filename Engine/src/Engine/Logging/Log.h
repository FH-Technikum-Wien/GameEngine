#pragma once

#include <memory>

#include "../Core.h"
#include "spdlog/spdlog.h"

namespace Engine {

	/// <summary>
	/// Wrapper for spdlog::logger
	/// </summary>
	class ENGINE_API Log
	{
	public:
		/// <summary>
		/// Initializes the spdlogger.
		/// </summary>
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

}


// Core log macros for convenience
#define LOG_CORE_TRACE(...)    ::Engine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LOG_CORE_INFO(...)     ::Engine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_CORE_WARN(...)     ::Engine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_CORE_ERROR(...)    ::Engine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_CORE_CRITICAL(...) ::Engine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros for convenience
#define LOG_TRACE(...)    ::Engine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)     ::Engine::Log::GetClientLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)     ::Engine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)    ::Engine::Log::GetClientLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...) ::Engine::Log::GetClientLogger()->critical(__VA_ARGS__)
