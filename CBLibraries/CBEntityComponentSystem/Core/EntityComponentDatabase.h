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
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT							EntityComponentDatabase();

		public:
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	bool					hasEntity(const cb::ecs::Entity& entity) const;
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	void					removeEntity(const cb::ecs::Entity& entity);

/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/template <class T>
										std::shared_ptr<T>		addComponentToEntity(const cb::ecs::Entity& entity);
/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/template <class T>
										std::shared_ptr<T>		getComponentFromEntity(const cb::ecs::Entity& entity);

		private:
			std::map<cb::ecs::Entity, cb::ecs::ComponentsContainer>		m_entity_components;
		};
	}
}

#include "CBEntityComponentSystem/Core/EntityComponentDatabase.tpp"