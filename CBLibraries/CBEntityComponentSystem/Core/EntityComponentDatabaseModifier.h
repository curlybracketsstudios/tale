#pragma once

#include "CBEntityComponentSystem/CBEntityComponentSystemLibrary.h"

#include "CBEntityComponentSystem/Core/Component/ComponentsContainer.h" 
#include "CBEntityComponentSystem/Core/Entity.h"

#include <map>
#include <memory>
#include <vector>

namespace cb
{
	namespace ecs
	{
		class Component;
		class ComponentsContainer;
		class EntitiesComponentsContainer;
		class EntityComponentDatabaseModifier
		{
		public:
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT													EntityComponentDatabaseModifier(
																							std::shared_ptr<cb::ecs::EntitiesComponentsContainer> entitiesComponentsContainer = std::make_shared<cb::ecs::EntitiesComponentsContainer>(),
																							std::shared_ptr<cb::ecs::ComponentIndexGenerator> componentIndexGenerator = std::make_shared<cb::ecs::ComponentIndexGenerator>()
																						);

		public:
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	bool											hasEntity(const cb::ecs::Entity& entity) const;
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	void											removeEntity(const cb::ecs::Entity& entity);

/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/template <class T, typename... Args>			
										std::shared_ptr<T>								addComponentToEntity(const cb::ecs::Entity& entity, Args... args);
										template <class T>
										void											addComponentToEntity(const cb::ecs::Entity& entity, std::shared_ptr<T> component);
/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/template <class T>
										std::shared_ptr<T>								getComponentFromEntity(const cb::ecs::Entity& entity);
/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/template <class T>
										bool											hasComponentForEntity(const cb::ecs::Entity& entity);

		private:
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	std::shared_ptr<cb::ecs::ComponentsContainer>	getComponentsContainerForEntity(const cb::ecs::Entity& entity);
/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/template <class T>
										std::size_t										getIndexForComponent();
/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/template <class T, typename... Args>
										std::shared_ptr<T>								createComponentOfType(Args... args);


		private:
			std::shared_ptr<cb::ecs::EntitiesComponentsContainer>		m_entities_components_container;
			std::shared_ptr<cb::ecs::ComponentIndexGenerator>			m_component_index_generator;
		};
	}
}

#include "CBEntityComponentSystem/Core/EntityComponentDatabaseModifier.tpp"