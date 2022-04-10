#include "pcktpch.h"
#include "Application.h"

#include "PacketEngine/Events/ApplicationEvent.h"
#include "PacketEngine/Log.h"

namespace PacketEngine
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}