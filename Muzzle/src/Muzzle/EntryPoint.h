#pragma once

#include <iostream>

#ifdef MZ_PLATFORM_WINDOWS

extern Muzzle::Application* Muzzle::CreateApplication();

int main(int argc, char** argv)
{
	std::cout << "Hello from Muzzle Engine" << std::endl;

	auto application = Muzzle::CreateApplication();
	application->Run();
	delete application;
}

#endif
