#include "pcktpch.h"
#include "Application.h"

#include "PacketEngine/Events/ApplicationEvent.h"
#include "PacketEngine/Log.h"

namespace PacketEngine
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		PACKET_TRACE(e);

		while (true);
	}
}