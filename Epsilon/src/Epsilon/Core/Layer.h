#pragma once

#include "Epsilon/Core/Core.h"
#include "Epsilon/Events/Event.h"

namespace Epsilon
{
	class EPSILON_API Layer
	{
	public: 
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		const std::string& GetName() { return m_LayerName; }

	protected:
		std::string m_LayerName;
	};
}