#pragma once

#include "Event.h"

namespace Muzzle {

	class MUZZLE_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height)
		{
		}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		virtual int GetCategoryFlags() const override { return EventCategoryApplication; }

		EVENT_CLASS_TYPE(WindowResize)

	private:
		unsigned int m_Width, m_Height;
	};

	class MUZZLE_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		virtual int GetCategoryFlags() const override { return EventCategoryApplication; }

		EVENT_CLASS_TYPE(WindowClose)
	};

	class MUZZLE_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		virtual int GetCategoryFlags() const override { return EventCategoryApplication; }

		EVENT_CLASS_TYPE(AppTick)
	};

	class MUZZLE_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		virtual int GetCategoryFlags() const override { return EventCategoryApplication; }

		EVENT_CLASS_TYPE(AppUpdate)
	};

	class MUZZLE_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		virtual int GetCategoryFlags() const override { return EventCategoryApplication; }

		EVENT_CLASS_TYPE(AppRender)
	};
}