#include "mzpch.h"
#include "Application.h"

#include "Muzzle/Events/AppEvent.h"
#include "Muzzle/Log.h"

#include <GLFW/glfw3.h>

namespace Muzzle {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (true)
		{
			m_Window->OnUpdate();
			glClearColor(1, 0, 1, 0);
			glClear(GL_COLOR_BUFFER_BIT);
		}
	}
}