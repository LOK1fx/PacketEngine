#pragma once

#include "Core.h"

namespace PacketEngine
{
	class PACKET_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}