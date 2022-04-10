#pragma once

#include "Core.h"
#include "Events/Event.h"

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