#pragma once

#include "Core.h"

namespace Muzzle {

	class MUZZLE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}
