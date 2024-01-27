#include "mzpch.h"
#include "WindowsWindow.h"

namespace Muzzle {

	static bool s_Initialised = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	Muzzle::WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	Muzzle::WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void Muzzle::WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		MZ_CORE_INFO("Creating Window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_Initialised)
		{
			int success = glfwInit();
			MZ_CORE_ASSERT(success, "GLFW Initialization failed!");

			s_Initialised = true;
		}

		m_Window = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	void Muzzle::WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void Muzzle::WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void Muzzle::WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool Muzzle::WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}