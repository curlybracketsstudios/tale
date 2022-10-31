#include "CBEntityComponentSystem/Core/EntityComponentDatabase.h"

#include "CBEntityComponentSystem/Core/EntitiesComponentsContainer.h"
#include "CBEntityComponentSystem/Core/Component/ComponentIndexGenerator.h"

//-------------------------------------------------------------------
// CONSTRUCTOR - DESTRUCTOR
//-------------------------------------------------------------------

cb::ecs::EntityComponentDatabase::EntityComponentDatabase()
	: m_entities_components_container(std::make_shared<cb::ecs::EntitiesComponentsContainer>())
	, m_component_index_generator(std::make_shared<cb::ecs::ComponentIndexGenerator>())
{
}

//-------------------------------------------------------------------
// PUBLIC
//-------------------------------------------------------------------

bool cb::ecs::EntityComponentDatabase::hasEntity(const cb::ecs::Entity& entity) const
{
	return m_entities_components_container->hasEntity(entity);
}

//-------------------------------------------------------------------

void cb::ecs::EntityComponentDatabase::removeEntity(const cb::ecs::Entity& entity)
{
	m_entities_components_container->removeEntity(entity);
}

//-------------------------------------------------------------------
// PROTECTED
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PRIVATE
//-------------------------------------------------------------------

std::shared_ptr<cb::ecs::ComponentsContainer> cb::ecs::EntityComponentDatabase::getComponentsContainerForEntity(const cb::ecs::Entity& entity)
{
	if (!m_entities_components_container->hasEntity(entity))
	{
		m_entities_components_container->addEntity(entity);
	}
	return m_entities_components_container->getComponentsContainerForEntity(entity);
}