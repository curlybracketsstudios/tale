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
		class EntityComponentDatabase
		{
		public:
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT										EntityComponentDatabase();

		public:
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	bool								hasEntity(const cb::ecs::Entity& entity) const;
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	void								removeEntity(const cb::ecs::Entity& entity);

/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/template <class T, typename... Args>
										std::shared_ptr<T>					addComponentToEntity(const cb::ecs::Entity& entity, Args... args);
/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/template <class T>
										std::shared_ptr<T>					getComponentFromEntity(const cb::ecs::Entity& entity);
/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/template <class T>
										bool								hasComponentForEntity(const cb::ecs::Entity& entity);

		private:
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	cb::ecs::ComponentsContainer&		getValidComponentsContainerForEntity(const cb::ecs::Entity& entity);
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	void								addComponentsContainerForEntity(const cb::ecs::Entity& entity);
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	cb::ecs::ComponentsContainer&		getExistingComponentsContainerForEntity(const cb::ecs::Entity& entity);

/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/template <class T, typename... Args>
										void								addNewComponentOfTypeToEntityComponentsContainer(const cb::ecs::Entity& entity, Args... args);
/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/template <class T>
										std::shared_ptr<T>					getExistingComponentForKnownEntity(const cb::ecs::Entity& entity);
/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/template <class T>
										bool								knownEntityHasComponent(const cb::ecs::Entity& entity);
/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/template <class T>
										std::size_t							getIndexForComponent();
/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/template <class T, typename... Args>
										std::shared_ptr<T>					createComponentOfType(Args... args);


		private:
			std::map<cb::ecs::Entity, cb::ecs::ComponentsContainer>		m_entity_components;
			std::shared_ptr<cb::ecs::ComponentIndexGenerator>			m_component_index_generator;
		};
	}
}

#include "CBEntityComponentSystem/Core/EntityComponentDatabase.tpp"