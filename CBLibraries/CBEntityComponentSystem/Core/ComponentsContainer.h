#pragma once

#include "CBEntityComponentSystem/CBEntityComponentSystemLibrary.h"

#include <memory>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <vector>

namespace cb
{
	namespace ecs
	{
		class Component;
		class ComponentsContainer
		{
		public:
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT								ComponentsContainer();

		public:
/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/	template <class T>
											std::shared_ptr<T>		addComponent();
/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/	template <class T>
											std::shared_ptr<T>		getComponent();
/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/	template <class T>
											std::size_t				getComponentIndex();

		private:
			std::vector<std::shared_ptr<cb::ecs::Component> >		m_components;
			std::unordered_map<std::type_index, std::size_t>		m_component_type_to_index;

		};
	}
}

#include "CBEntityComponentSystem/Core/ComponentsContainer.tpp"