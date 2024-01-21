#pragma once

#ifdef MZ_PLATFORM_WINDOWS

extern Muzzle::Application* Muzzle::CreateApplication();

int main(int argc, char** argv)
{
	Muzzle::Log::Init();
	MZ_CORE_ERROR("Hello from Muzzle Engine");
	MZ_INFO("Hello from Application");

	auto application = Muzzle::CreateApplication();
	application->Run();
	delete application;
}

#endif
