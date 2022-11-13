#pragma once

#include "CBEntityComponentSystem/CBEntityComponentSystemLibrary.h"

#include <memory>
#include <vector>

namespace cb
{
	namespace ecs
	{
		class Component;
		class ComponentsContainer
		{
		public:
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT											ComponentsContainer(std::size_t initialSize = 0);

		public:
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	void									addComponentAtIndex(std::shared_ptr<cb::ecs::Component> component, std::size_t index);
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	std::shared_ptr<cb::ecs::Component>		getComponentAtIndex(std::size_t index);
CBENTITYCOMPONENTSYSTEMSHARED_EXPORT	bool									hasComponentAtIndex(std::size_t index);

		private:
										void									verifyAndUpdateComponentsContainerSize(std::size_t lastPossibleIndex);
										bool									containerIsTooSmall(std::size_t lastPossibleIndex);
										void									increaseContainerSize(std::size_t lastPossibleIndex);

										void									setComponentAtIndex(std::shared_ptr<cb::ecs::Component> component, std::size_t index);

		private:
			std::vector<std::shared_ptr<cb::ecs::Component> >		m_components;
		};
	}
}