#include "CBEntityComponentSystem/Core/Component/ComponentsContainer.h"

//-------------------------------------------------------------------
// CONSTRUCTOR - DESTRUCTOR
//-------------------------------------------------------------------

cb::ecs::ComponentsContainer::ComponentsContainer(
	std::shared_ptr<cb::ecs::ComponentIndexGenerator> componentIndexGenerator
)
	: m_components(std::vector<std::shared_ptr<cb::ecs::Component> >())
	, m_component_index_generator(componentIndexGenerator)
{
}

//-------------------------------------------------------------------
// PUBLIC
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PROTECTED
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PRIVATE
//-------------------------------------------------------------------

void cb::ecs::ComponentsContainer::verifyAndUpdateComponentsContainerSize()
{
	if (containerIsTooSmall())
	{
		increaseContainerSize();
	}
}

//-------------------------------------------------------------------

bool cb::ecs::ComponentsContainer::containerIsTooSmall()
{
	return m_components.size() < getNumberOfPossibleComponents();
}

//-------------------------------------------------------------------

void cb::ecs::ComponentsContainer::increaseContainerSize()
{
	m_components.resize(getNumberOfPossibleComponents(), nullptr);
}

//-------------------------------------------------------------------

std::size_t cb::ecs::ComponentsContainer::getNumberOfPossibleComponents()
{
	return m_component_index_generator->getNumberOfComponents();
}

//-------------------------------------------------------------------

std::shared_ptr<cb::ecs::Component> cb::ecs::ComponentsContainer::getComponentAtIndex(std::size_t index) const
{
	return m_components[index];
}

//-------------------------------------------------------------------

void cb::ecs::ComponentsContainer::setComponentAtIndex(std::shared_ptr<cb::ecs::Component> component, std::size_t index)
{
	m_components[index] = component;
}

//-------------------------------------------------------------------

bool cb::ecs::ComponentsContainer::hasNoComponentAtIndex(std::size_t index)
{
	std::shared_ptr<cb::ecs::Component> component = getComponentAtIndex(index);
	return component == nullptr;
}

//-------------------------------------------------------------------