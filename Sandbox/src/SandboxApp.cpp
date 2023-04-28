#include <Epsilon.h>
#include <Epsilon/Core/EntryPoint.h>

class Sandbox : public Epsilon::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Epsilon::Application* Epsilon::CreateApplication()
{
	return new Sandbox();
}