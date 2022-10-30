#pragma once

#include "CBEntityComponentSystem/CBEntityComponentSystemLibrary.h"

namespace cb
{
	namespace ecs
	{
		class Component
		{
		public:
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT				Component();
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT virtual		~Component() = default;
		};
	}
}