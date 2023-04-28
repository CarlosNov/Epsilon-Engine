#pragma once

#include "Epsilon/Events/Event.h"
#include "Epsilon/Events/KeyEvent.h"

#ifdef EPS_PLATFORM_WINDOWS

extern Epsilon::Application* Epsilon::CreateApplication();

int main(int argc, char** argv)
{
	Epsilon::Log::Init();

	auto app = Epsilon::CreateApplication();
	app->Run();
	delete app;
}

#endif