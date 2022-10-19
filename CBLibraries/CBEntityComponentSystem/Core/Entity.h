#pragma once

#include "CBEntityComponentSystem/CBEntityComponentSystemLibrary.h"

#include "CBBase/GUID/GUID.h"

namespace cb
{
	namespace ecs
	{
		class Entity
		{
		public:
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT							Entity();

		public:
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	bool					isNull();

										void					setGuid(const cb::base::GUID& guid);
										const cb::base::GUID&	guid() const;

		private:
			cb::base::GUID	m_guid;
		};

CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	bool		operator==(const cb::ecs::Entity& lhs, const cb::ecs::Entity& rhs);
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	bool		operator!=(const cb::ecs::Entity& lhs, const cb::ecs::Entity& rhs);
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	bool		operator<(const cb::ecs::Entity& lhs, const cb::ecs::Entity & rhs);
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	bool		operator>(const cb::ecs::Entity& lhs, const cb::ecs::Entity& rhs);
	}
}