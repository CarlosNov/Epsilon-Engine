#include <Epsilon.h>

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