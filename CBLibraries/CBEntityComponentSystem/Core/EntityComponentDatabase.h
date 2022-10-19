#pragma once

#include "CBEntityComponentSystem/CBEntityComponentSystemLibrary.h"

#include "CBEntityComponentSystem/Core/Entity.h"

#include <set>

namespace cb
{
	namespace ecs
	{
		class EntityComponentDatabase
		{
		public:
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT							EntityComponentDatabase();

		public:
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	cb::ecs::Entity			createEntity();
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	bool					hasEntity(const cb::ecs::Entity& entity) const;
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	void					removeEntity(const cb::ecs::Entity& entity);


		private:
			std::set<cb::ecs::Entity>		m_all_entities;
		};
	}
}