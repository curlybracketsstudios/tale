#include "CBEntityComponentSystem/Core/Component/ComponentsContainer.h"

//-------------------------------------------------------------------
// CONSTRUCTOR - DESTRUCTOR
//-------------------------------------------------------------------

cb::ecs::ComponentsContainer::ComponentsContainer(std::size_t initialSize)
	: m_components(std::vector<std::shared_ptr<cb::ecs::Component> >(initialSize))
{
}

//-------------------------------------------------------------------
// PUBLIC
//-------------------------------------------------------------------

void cb::ecs::ComponentsContainer::addComponentAtIndex(std::shared_ptr<cb::ecs::Component> component, std::size_t index)
{
	if (!hasComponentAtIndex(index))
	{
		setComponentAtIndex(component, index);
	}
}

//-------------------------------------------------------------------

std::shared_ptr<cb::ecs::Component> cb::ecs::ComponentsContainer::getComponentAtIndex(std::size_t index)
{
	verifyAndUpdateComponentsContainerSize(index);
	return m_components[index];
}

//-------------------------------------------------------------------

bool cb::ecs::ComponentsContainer::hasComponentAtIndex(std::size_t index)
{
	return getComponentAtIndex(index) != nullptr;
}

//-------------------------------------------------------------------
// PROTECTED
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PRIVATE
//-------------------------------------------------------------------

void cb::ecs::ComponentsContainer::verifyAndUpdateComponentsContainerSize(std::size_t lastPossibleIndex)
{
	if (containerIsTooSmall(lastPossibleIndex))
	{
		increaseContainerSize(lastPossibleIndex);
	}
}

//-------------------------------------------------------------------

bool cb::ecs::ComponentsContainer::containerIsTooSmall(std::size_t lastPossibleIndex)
{
	return m_components.size() < lastPossibleIndex + 1;
}

//-------------------------------------------------------------------

void cb::ecs::ComponentsContainer::increaseContainerSize(std::size_t lastPossibleIndex)
{
	m_components.resize(lastPossibleIndex + 1, nullptr);
}

//-------------------------------------------------------------------

void cb::ecs::ComponentsContainer::setComponentAtIndex(std::shared_ptr<cb::ecs::Component> component, std::size_t index)
{
	m_components[index] = component;
}

//-------------------------------------------------------------------