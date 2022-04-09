#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace PacketEngine
{
	class PACKET_API Log
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

// Core logger
#define PACKET_CORE_TRACE(...) ::PacketEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PACKET_CORE_ERROR(...) ::PacketEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PACKET_CORE_WARN(...)  ::PacketEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PACKET_CORE_INFO(...)  ::PacketEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PACKET_CORE_FATAL(...) ::PacketEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client logger
#define PACKET_TRACE(...) ::PacketEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PACKET_ERROR(...) ::PacketEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define PACKET_WARN(...)  ::PacketEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PACKET_INFO(...)  ::PacketEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define PACKET_FATAL(...) ::PacketEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)