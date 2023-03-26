#include <PacketEngine.h>

class ExampleLayer : public PacketEngine::Layer
{
public:
	ExampleLayer() : Layer("Example")
	{

	}

	void OnUpdate() override
	{
		
	}

	void OnEvent(PacketEngine::Event& event) override
	{
		//PACKET_INFO("{0}", event);
	}
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