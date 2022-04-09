#include <PacketEngine.h>

class Sandbox : public PacketEngine::Application
{
public:
	Sandbox()
	{
		PACKET_INFO("Hello, world!");
	}

	~Sandbox()
	{
	}
};

PacketEngine::Application* PacketEngine::CreateApplication()
{
	return new Sandbox();
}