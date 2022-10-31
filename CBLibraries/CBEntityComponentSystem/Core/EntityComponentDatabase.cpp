#include "CBEntityComponentSystem/Core/EntityComponentDatabase.h"

#include "CBEntityComponentSystem/Core/Component/ComponentIndexGenerator.h"

//-------------------------------------------------------------------
// CONSTRUCTOR - DESTRUCTOR
//-------------------------------------------------------------------

cb::ecs::EntityComponentDatabase::EntityComponentDatabase()
	: m_entity_components(std::map<cb::ecs::Entity, cb::ecs::ComponentsContainer>())
	, m_component_index_generator(std::make_shared<cb::ecs::ComponentIndexGenerator>())
{
}

//-------------------------------------------------------------------
// PUBLIC
//-------------------------------------------------------------------

bool cb::ecs::EntityComponentDatabase::hasEntity(const cb::ecs::Entity& entity) const
{
	return m_entity_components.find(entity) != m_entity_components.end();
}

//-------------------------------------------------------------------

void cb::ecs::EntityComponentDatabase::removeEntity(const cb::ecs::Entity& entity)
{
	auto it_entity = m_entity_components.find(entity);
	if (it_entity != m_entity_components.end())
	{
		m_entity_components.erase(it_entity);
	}
}

//-------------------------------------------------------------------
// PROTECTED
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PRIVATE
//-------------------------------------------------------------------

cb::ecs::ComponentsContainer& cb::ecs::EntityComponentDatabase::getValidComponentsContainerForEntity(const cb::ecs::Entity& entity)
{
	if (!hasEntity(entity))
	{
		addComponentsContainerForEntity(entity);
	}
	return getExistingComponentsContainerForEntity(entity);
}

//-------------------------------------------------------------------

void cb::ecs::EntityComponentDatabase::addComponentsContainerForEntity(const cb::ecs::Entity& entity)
{
	m_entity_components.insert(std::make_pair(entity, cb::ecs::ComponentsContainer(m_component_index_generator->getNumberOfComponents())));
}

//-------------------------------------------------------------------

cb::ecs::ComponentsContainer& cb::ecs::EntityComponentDatabase::getExistingComponentsContainerForEntity(const cb::ecs::Entity& entity)
{
	return m_entity_components[entity];
}

//-------------------------------------------------------------------