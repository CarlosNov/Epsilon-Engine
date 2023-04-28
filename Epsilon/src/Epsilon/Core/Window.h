#pragma once

#include "EpsilonPCHeader.h"

#include "Epsilon/Core/Core.h"
#include "Epsilon/Events/Event.h"

namespace Epsilon
{
	struct WindowProperties
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProperties(const std::string& title = "Epsilon Engine",
			unsigned int width = 1080,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{

		}
	};

	//Window interface
	class EPSILON_API Window
	{
	public: 
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Window Properties
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool HasVSync() const = 0;

		static Window* Create(const WindowProperties& props = WindowProperties());
	};
}
