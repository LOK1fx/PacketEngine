#pragma once

#ifdef PACKET_PLATFORM_WINDOWS

extern PacketEngine::Application* PacketEngine::CreateApplication();

int main(int argc, char** argv)
{
	PacketEngine::Log::Init();
	PACKET_CORE_INFO("Initialized Log!");
	PACKET_WARN("Initialized Log!");

	auto app = PacketEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif