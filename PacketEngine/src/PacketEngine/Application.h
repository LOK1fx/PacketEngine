#pragma once

#include "Core.h"

#include "Window.h"
#include "PacketEngine/LayerStack.h"
#include "Events/Event.h"
#include "PacketEngine/Events/ApplicationEvent.h"

#include "PacketEngine/ImGui/ImGuiLayer.h"

namespace PacketEngine
{
	class PACKET_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		static inline Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;

		LayerStack m_LayerStack;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}