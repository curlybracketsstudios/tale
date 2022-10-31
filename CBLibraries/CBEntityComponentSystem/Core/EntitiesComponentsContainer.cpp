#include "CBEntityComponentSystem/Core/EntitiesComponentsContainer.h"

#include "CBEntityComponentSystem/Core/Component/ComponentsContainer.h"

//-------------------------------------------------------------------
// CONSTRUCTOR - DESTRUCTOR
//-------------------------------------------------------------------

cb::ecs::EntitiesComponentsContainer::EntitiesComponentsContainer()
	: m_entities_components_container(std::map<cb::ecs::Entity, std::shared_ptr<cb::ecs::ComponentsContainer> >())
{
}

//-------------------------------------------------------------------
// PUBLIC
//-------------------------------------------------------------------

void cb::ecs::EntitiesComponentsContainer::addEntity(const cb::ecs::Entity& entity)
{
	if (!hasEntity(entity))
	{
		insertEntityEntry(entity);
	}
}

//-------------------------------------------------------------------

void cb::ecs::EntitiesComponentsContainer::removeEntity(const cb::ecs::Entity& entity)
{
	if (hasEntity(entity))
	{
		removeEntityEntry(entity);
	}
}

//-------------------------------------------------------------------

bool cb::ecs::EntitiesComponentsContainer::hasEntity(const cb::ecs::Entity& entity) const
{
	return containsEntryForEntity(entity);
}

//-------------------------------------------------------------------

std::shared_ptr<cb::ecs::ComponentsContainer> cb::ecs::EntitiesComponentsContainer::getComponentsContainerForEntity(const cb::ecs::Entity& entity) const
{
	std::shared_ptr<cb::ecs::ComponentsContainer> components_container = std::make_shared<cb::ecs::ComponentsContainer>();
	if (hasEntity(entity))
	{
		components_container = getComponentsContainerFromKnownEntity(entity);
	}
	return components_container;
}

//-------------------------------------------------------------------

std::size_t cb::ecs::EntitiesComponentsContainer::getNumberOfEntities() const
{
	return m_entities_components_container.size();
}

//-------------------------------------------------------------------
// PROTECTED
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PRIVATE
//-------------------------------------------------------------------

std::shared_ptr<cb::ecs::ComponentsContainer> cb::ecs::EntitiesComponentsContainer::getComponentsContainerFromKnownEntity(const cb::ecs::Entity& entity) const
{
	return m_entities_components_container.find(entity)->second;
}

//-------------------------------------------------------------------

void cb::ecs::EntitiesComponentsContainer::removeEntityEntry(const cb::ecs::Entity& entity)
{
	m_entities_components_container.erase(entity);
}

//-------------------------------------------------------------------

void cb::ecs::EntitiesComponentsContainer::insertEntityEntry(const cb::ecs::Entity& entity)
{
	m_entities_components_container.insert(std::make_pair(entity, std::make_shared<cb::ecs::ComponentsContainer>()));
}

//-------------------------------------------------------------------

bool cb::ecs::EntitiesComponentsContainer::containsEntryForEntity(const cb::ecs::Entity& entity) const
{
	return m_entities_components_container.find(entity) != m_entities_components_container.end();
}

//-------------------------------------------------------------------