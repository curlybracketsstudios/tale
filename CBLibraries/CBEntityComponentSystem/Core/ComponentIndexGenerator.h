#pragma once

#include "CBEntityComponentSystem/CBEntityComponentSystemLibrary.h"

#include "CBEntityComponentSystem/CBEntityComponentSystemLibrary.h"

#include <typeindex>
#include <typeinfo>
#include <unordered_map>

namespace cb
{
	namespace ecs
	{
		class ComponentIndexGenerator
		{
		public:
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT								ComponentIndexGenerator();

		public:
/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/	template <class T>
											std::size_t				getComponentIndex();

		private:
			std::unordered_map<std::type_index, std::size_t>		m_component_type_to_index;
		};
	}
}

#include "CBEntityComponentSystem/Core/ComponentIndexGenerator.tpp"