#pragma once

#include "CBEntityComponentSystem/CBEntityComponentSystemLibrary.h"

#include "CBEntityComponentSystem/Core/Component/ComponentIndexGenerator.h"
#include "CBEntityComponentSystem/Core/EntitiesComponentsContainer.h"

namespace cb
{
	namespace ecs
	{
		class Entity;
		class EntityComponentDatabaseQuerier
		{
		public:
			CBENTITYCOMPONENTSYSTEMSHARED_EXPORT													EntityComponentDatabaseQuerier(
																										std::shared_ptr<cb::ecs::EntitiesComponentsContainer> entitiesComponentsContainer = std::make_shared<cb::ecs::EntitiesComponentsContainer>(),
																										std::shared_ptr<cb::ecs::ComponentIndexGenerator> componentIndexGenerator = std::make_shared<cb::ecs::ComponentIndexGenerator>()
																									);

		private:
			std::shared_ptr<cb::ecs::EntitiesComponentsContainer>		m_entities_components_container;
			std::shared_ptr<cb::ecs::ComponentIndexGenerator>			m_component_index_generator;
		};
	}
}