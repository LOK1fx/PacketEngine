#pragma once

#ifdef PACKET_PLATFORM_WINDOWS
	#ifdef PACKET_BUILD_DLL
		#define PACKET_API __declspec(dllexport)
	#else
		#define PACKET_API __declspec(dllimport)
	#endif
#else
	#error PacketEngine only supports Windows platform!
#endif