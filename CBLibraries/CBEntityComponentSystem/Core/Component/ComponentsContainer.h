#pragma once

#include "CBEntityComponentSystem/CBEntityComponentSystemLibrary.h"

#include "CBEntityComponentSystem/Core/Component/ComponentIndexGenerator.h"

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
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT												ComponentsContainer(
																						std::shared_ptr<cb::ecs::ComponentIndexGenerator> componentIndexGenerator = std::make_shared<cb::ecs::ComponentIndexGenerator>()
																						);

		public:
/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/	template <class T>
											std::shared_ptr<T>						addComponent();
/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/	template <class T>
											std::shared_ptr<T>						getComponent();

		private:
/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/	template <class T>
											std::size_t								getComponentIndex();
/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/	template <class T>
											std::shared_ptr<T>						getTypedComponentAtIndex(std::size_t index);
/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/	template <class T>
											std::shared_ptr<T>						createTypedComponent();

/*CBENTITYCOMPONENTSYSTEMSHARED_EXPORT*/	template <class T>
											std::size_t								createValidComponentIndex();

CBENTITYCOMPONENTSYSTEMSHARED_EXPORT		void									verifyAndUpdateComponentsContainerSize();
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT		bool									containerIsTooSmall();
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT		void									increaseContainerSize();
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT		std::size_t								getNumberOfPossibleComponents();

CBENTITYCOMPONENTSYSTEMSHARED_EXPORT		std::shared_ptr<cb::ecs::Component>		getComponentAtIndex(std::size_t index) const;
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT		void									setComponentAtIndex(std::shared_ptr<cb::ecs::Component> component, std::size_t index);
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT		bool									hasNoComponentAtIndex(std::size_t index);

	


		private:
			std::vector<std::shared_ptr<cb::ecs::Component> >		m_components;
			std::shared_ptr<cb::ecs::ComponentIndexGenerator>		m_component_index_generator;
		};
	}
}

#include "CBEntityComponentSystem/Core/Component/ComponentsContainer.tpp"