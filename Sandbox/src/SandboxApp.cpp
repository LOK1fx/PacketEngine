#include <PacketEngine.h>

class ExampleLayer : public PacketEngine::Layer
{
public:
	ExampleLayer() : Layer("Example")
	{
		
	}

	void OnUpdate() override
	{
		if (PacketEngine::Input::IsKeyPressed(PCT_KEY_W))
		{
			PACKET_TRACE("W key is pressed!");

			m_YPos += 0.01f;
		}
		if (PacketEngine::Input::IsKeyPressed(PCT_KEY_A))
		{
			PACKET_TRACE("A key is pressed!");

			m_XPos -= 0.01f;
		}
		if (PacketEngine::Input::IsKeyPressed(PCT_KEY_S))
		{
			PACKET_TRACE("S key is pressed!");

			m_YPos -= 0.01f;
		}
		if (PacketEngine::Input::IsKeyPressed(PCT_KEY_D))
		{
			PACKET_TRACE("D key is pressed!");

			m_XPos += 0.01f;
		}

		if (PacketEngine::Input::IsMouseButtonPressed(PCT_MOUSE_BUTTON_4))
		{
			PACKET_INFO("{0}, {1}", m_XPos, m_YPos);
		}
	}

	void OnEvent(PacketEngine::Event& event) override
	{
		
	}
private:
	float m_XPos = 0.0f;
	float m_YPos = 0.0f;
};

class Sandbox : public PacketEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new PacketEngine::ImGuiLayer());
	}

	~Sandbox()
	{
	}
};

PacketEngine::Application* PacketEngine::CreateApplication()
{
	return new Sandbox();
}