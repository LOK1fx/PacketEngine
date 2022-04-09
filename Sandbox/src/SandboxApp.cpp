#include <PacketEngine.h>

class Sandbox : public PacketEngine::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{
	}
};

PacketEngine::Application* PacketEngine::CreateApplication()
{
	return new Sandbox();
}