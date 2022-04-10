#include "pcktpch.h"
#include "WindowsWindow.h"

namespace PacketEngine
{
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		PACKET_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			// TODO: GLFW
			int succes = 1;
			PACKET_CORE_ASSERT(succes, "Could not initialize GLFW!");

			s_GLFWInitialized = true;
		}

		SetVSync(true);
	}

	void WindowsWindow::Shutdown()
	{

	}

	void WindowsWindow::OnUpdate()
	{
		
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
		{

		}
		else
		{

		}

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSyncOn() const
	{
		return m_Data.VSync;
	}
}