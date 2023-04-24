#pragma once

#include "Epsilon/Events/Event.h"

namespace Epsilon
{
	class AppTick : public Event
	{
	public:
		AppTick() = default;

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class AppRender : public Event
	{
	public:
		AppRender() = default;

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class AppUpdate : public Event
	{
	public:
		AppUpdate() = default;

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}
