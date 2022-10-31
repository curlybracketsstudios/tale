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

CBENTITYCOMPONENTSYSTEMSHARED_EXPORT		std::size_t				getNumberOfComponents() const;

		private:
/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/	template <class T>
											bool					doesNotHaveTypeIndexForComponent();
/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/	template <class T>
											void					addTypeIndexForComponent();
/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/	template <class T>
											std::size_t				getComponentIndexForComponentTypeIndex();
/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/	template <class T>
											std::type_index			createTypeIndexForComponent();

		private:
			std::unordered_map<std::type_index, std::size_t>		m_component_type_to_index;
		};
	}
}

#include "CBEntityComponentSystem/Core/ComponentIndexGenerator.tpp"