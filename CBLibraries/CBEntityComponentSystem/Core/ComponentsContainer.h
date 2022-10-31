#pragma once

#include "CBEntityComponentSystem/CBEntityComponentSystemLibrary.h"

#include "CBEntityComponentSystem/Core/ComponentIndexGenerator.h"

#include <memory>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <vector>

namespace cb
{
	namespace ecs
	{
		class Component;
		class ComponentsContainer
		{
		public:
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT								ComponentsContainer(
																		std::shared_ptr<cb::ecs::ComponentIndexGenerator> componentIndexGenerator = std::make_shared<cb::ecs::ComponentIndexGenerator>()
																		);

		public:
/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/	template <class T>
											std::shared_ptr<T>		addComponent();
/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/	template <class T>
											std::shared_ptr<T>		getComponent();

		private:
			std::vector<std::shared_ptr<cb::ecs::Component> >		m_components;
			std::shared_ptr<cb::ecs::ComponentIndexGenerator>		m_component_index_generator;
		};
	}
}

#include "CBEntityComponentSystem/Core/ComponentsContainer.tpp"