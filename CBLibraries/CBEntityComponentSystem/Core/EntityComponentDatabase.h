#pragma once

#include "CBEntityComponentSystem/CBEntityComponentSystemLibrary.h"

#include "CBEntityComponentSystem/Core/Entity.h"

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
		};
	}
}