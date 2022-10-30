#pragma once

#include "CBEntityComponentSystem/CBEntityComponentSystemLibrary.h"

#include "CBEntityComponentSystem/Core/Entity.h"

namespace cb
{
	namespace ecs
	{
		class EntityFactory
		{
		public:
																EntityFactory();

		public:
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT static cb::ecs::Entity		createEntity();
		};
	}
}