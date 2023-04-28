#pragma once

#include "Core.h"
#include "Window.h"
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
	private:
		bool OnWindowClose(WindowCloseEvent& event);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();
}