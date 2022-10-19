#pragma once

#include "CBBase/CBBaseLibrary.h"

#include <boost/uuid/uuid.hpp>

namespace cb
{
	namespace base
	{
		class GUID
		{
		public:
CBBASESHARED_EXPORT						GUID();

		public:
CBBASESHARED_EXPORT	bool				isNull() const;

		public:
			boost::uuids::uuid		m_value;
		};

CBBASESHARED_EXPORT cb::base::GUID		createGUID();
	}
}