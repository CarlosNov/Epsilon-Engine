#pragma once

#include "Epsilon/Core/Core.h"
#include "Epsilon/Core/Window.h"
#include "Epsilon/Core/LayerStack.h"
#include "Epsilon/Events/Event.h"
#include "Epsilon/Events/WindowEvent.h"

namespace Epsilon
{
	class EPSILON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& event);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& event);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	Application* CreateApplication();
}