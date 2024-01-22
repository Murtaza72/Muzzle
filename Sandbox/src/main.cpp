#include <mzpch.h>
#include <Muzzle.h>

class Sandbox : public Muzzle::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};

Muzzle::Application* Muzzle::CreateApplication()
{
	return new Sandbox();
}