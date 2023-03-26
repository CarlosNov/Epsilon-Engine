#pragma once

#ifdef EPS_PLATFORM_WINDOWS

extern Epsilon::Application* Epsilon::CreateApplication();

int main(int argc, char** argv)
{
	printf("hola mundo");
	auto app = Epsilon::CreateApplication();
	app->Run();
	delete app;
}

#endif