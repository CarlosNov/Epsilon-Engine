#pragma once

#include "Core.h"

namespace Epsilon
{
	class EPSILON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}