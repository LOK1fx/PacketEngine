#include "pcktpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace PacketEngine
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) : m_WindowHandle(windowHandle)
	{
		PACKET_CORE_ASSERT(windowHandle, "m_WindowHandle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		PACKET_CORE_ASSERT(status, "Failed to intialize Glad!");

		PACKET_CORE_INFO("OpenGL Info:");
		PACKET_CORE_INFO("    Vendor: {0}", glGetString(GL_VENDOR));
		PACKET_CORE_INFO("    Renderer: {0}", glGetString(GL_RENDERER));
		PACKET_CORE_INFO("    Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}