#pragma once

#include "CBEntityComponentSystem/CBEntityComponentSystemLibrary.h"

namespace cb
{
	namespace ecs
	{
		class Entity
		{
		public:
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT				Entity();

		public:
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	bool		isNull();
										void		setIsNull(bool isNull);

		private:
			bool	m_is_null;
		};
	}
}