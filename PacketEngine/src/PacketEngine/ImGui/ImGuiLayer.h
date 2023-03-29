#pragma once

#include "PacketEngine/Layer.h"

#include "PacketEngine/Events/ApplicationEvent.h"
#include "PacketEngine/Events/KeyEvent.h"
#include "PacketEngine/Events/MouseEvent.h"

namespace PacketEngine
{
	class PACKET_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}