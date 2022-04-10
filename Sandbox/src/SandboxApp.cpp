#include <PacketEngine.h>

class Sandbox : public PacketEngine::Application
{
public:
	Sandbox()
	{
		PACKET_INFO("Hello, world!");
		PACKET_ERROR("Errr");
	}

	~Sandbox()
	{
	}
};

PacketEngine::Application* PacketEngine::CreateApplication()
{
	return new Sandbox();
}