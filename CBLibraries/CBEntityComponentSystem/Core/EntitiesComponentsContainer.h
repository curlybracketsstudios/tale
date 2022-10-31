#pragma once

#include "CBEntityComponentSystem/CBEntityComponentSystemLibrary.h"

#include "CBEntityComponentSystem/Core/Entity.h"

#include <map>
#include <memory>

namespace cb
{
	namespace ecs
	{
		class ComponentsContainer;
		class EntitiesComponentsContainer
		{
		public:
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT													EntitiesComponentsContainer();

		public:
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	void											addEntity(const cb::ecs::Entity& entity);
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	void											removeEntity(const cb::ecs::Entity& entity);
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	bool											hasEntity(const cb::ecs::Entity& entity) const;
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	std::size_t										getNumberOfEntities() const;

CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	std::shared_ptr<cb::ecs::ComponentsContainer>	getComponentsContainerForEntity(const cb::ecs::Entity& entity) const;

		private:
										std::shared_ptr<cb::ecs::ComponentsContainer>	getComponentsContainerFromKnownEntity(const cb::ecs::Entity& entity) const;
										void											removeEntityEntry(const cb::ecs::Entity& entity);
										void											insertEntityEntry(const cb::ecs::Entity& entity);
										bool											containsEntryForEntity(const cb::ecs::Entity& entity) const;

		private:
			std::map<cb::ecs::Entity, std::shared_ptr<cb::ecs::ComponentsContainer> > m_entities_components_container;
		};
	}
}