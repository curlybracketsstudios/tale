#pragma once

#include "CBEntityComponentSystem/CBEntityComponentSystemLibrary.h"

#include <boost/uuid/uuid.hpp>

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

										void					setGuid(const boost::uuids::uuid& uuid);
										boost::uuids::uuid		guid() const;

		private:
			boost::uuids::uuid	m_id;
		};

CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	bool		operator==(const cb::ecs::Entity& lhs, const cb::ecs::Entity& rhs);
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	bool		operator!=(const cb::ecs::Entity& lhs, const cb::ecs::Entity& rhs);
	}
}