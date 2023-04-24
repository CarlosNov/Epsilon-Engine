#pragma once

#include "Epsilon/Events/Event.h"
#include "Epsilon/Events/KeyEvent.h"

#ifdef EPS_PLATFORM_WINDOWS

extern Epsilon::Application* Epsilon::CreateApplication();

int main(int argc, char** argv)
{
	Epsilon::Log::Init();
	EPS_CORE_LOG_TRACE("Core Initialization!");
	EPS_CORE_LOG_INFO("Core Initialization!");
	EPS_CORE_LOG_WARN("Core Initialization!");
	EPS_CORE_LOG_ERROR("Core Initialization!");
	EPS_CORE_LOG_CRITICAL("Core Initialization!");

	EPS_LOG_TRACE("Client Initialized!");
	Epsilon::KeyPressedEvent e = Epsilon::KeyPressedEvent(1);
	Epsilon::EventDispatcher dispatcher(e);
	dispatcher.Dispatch<Epsilon::KeyPressedEvent>([](Epsilon::KeyPressedEvent e) {EPS_LOG_TRACE(e.toString()); return true; });

	auto app = Epsilon::CreateApplication();
	app->Run();
	delete app;
}

#endif