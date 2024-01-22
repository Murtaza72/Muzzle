#include "mzpch.h"
#include "Application.h"

#include "Muzzle/Events/AppEvent.h"
#include "Muzzle/Log.h"

namespace Muzzle {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			MZ_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			MZ_TRACE(e);
		}

		while (true);
	}
}