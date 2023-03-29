#pragma once

#ifdef PACKET_PLATFORM_WINDOWS
#if PACKET_DYNAMIC_LINK
	#ifdef PACKET_BUILD_DLL
		#define PACKET_API __declspec(dllexport)
	#else
		#define PACKET_API __declspec(dllimport)
	#endif
#else
	#define PACKET_API
#endif
#else
	#error PacketEngine only supports Windows platform!
#endif

#ifdef PACKET_ENABLE_ASSERTS
	#define PACKET_ASSERT(x, ...) { if(!(x)) { PACKET_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define PACKET_CORE_ASSERT(x, ...) { if(!(x)) { PACKET_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define PACKET_ASSERT(x, ...)
	#define PACKET_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define PACKET_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)