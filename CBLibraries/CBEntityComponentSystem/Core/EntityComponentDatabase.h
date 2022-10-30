#pragma once

#include "CBEntityComponentSystem/CBEntityComponentSystemLibrary.h"

#include "CBEntityComponentSystem/Core/Entity.h"

#include <map>
#include <memory>
#include <vector>

namespace cb
{
	namespace ecs
	{
		class Component;
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
			std::map<cb::ecs::Entity, std::vector<std::shared_ptr<cb::ecs::Component> > >		m_entity_components;
		};
	}
}

#include "CBEntityComponentSystem/Core/EntityComponentDatabase.tpp"