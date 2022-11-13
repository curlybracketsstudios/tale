#pragma once

#include "CBEntityComponentSystem/CBEntityComponentSystemLibrary.h"

#include <memory>

namespace cb
{
	namespace ecs
	{
		class ComponentIndexGenerator;
		class Entity;
		class EntitiesComponentsContainer;
		class EntityComponentDatabaseQuerier
		{
		public:
			CBENTITYCOMPONENTSYSTEMSHARED_EXPORT													EntityComponentDatabaseQuerier(
																										std::shared_ptr<cb::ecs::EntitiesComponentsContainer> entitiesComponentsContainer = nullptr,
																										std::shared_ptr<cb::ecs::ComponentIndexGenerator> componentIndexGenerator = nullptr
																									);

		private:
			std::shared_ptr<cb::ecs::EntitiesComponentsContainer>		m_entities_components_container;
			std::shared_ptr<cb::ecs::ComponentIndexGenerator>			m_component_index_generator;
		};
	}
}