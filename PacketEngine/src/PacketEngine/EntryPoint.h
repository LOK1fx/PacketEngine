#pragma once

#ifdef PACKET_PLATFOTM_WINDOWS

extern PacketEngine::Application* PacketEngine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = PacketEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif