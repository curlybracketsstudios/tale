#include "CBEntityComponentSystem/Core/EntityComponentDatabaseModifier.h"

#include "CBEntityComponentSystem/Core/EntitiesComponentsContainer.h"
#include "CBEntityComponentSystem/Core/Component/ComponentIndexGenerator.h"

//-------------------------------------------------------------------
// CONSTRUCTOR - DESTRUCTOR
//-------------------------------------------------------------------

cb::ecs::EntityComponentDatabaseModifier::EntityComponentDatabaseModifier
(
	std::shared_ptr<cb::ecs::EntitiesComponentsContainer> entitiesComponentsContainer,
	std::shared_ptr<cb::ecs::ComponentIndexGenerator> componentIndexGenerator
)
	: m_entities_components_container(entitiesComponentsContainer)
	, m_component_index_generator(componentIndexGenerator)
{
}

//-------------------------------------------------------------------
// PUBLIC
//-------------------------------------------------------------------

bool cb::ecs::EntityComponentDatabaseModifier::hasEntity(const cb::ecs::Entity& entity) const
{
	return m_entities_components_container->hasEntity(entity);
}

//-------------------------------------------------------------------

void cb::ecs::EntityComponentDatabaseModifier::removeEntity(const cb::ecs::Entity& entity)
{
	m_entities_components_container->removeEntity(entity);
}

//-------------------------------------------------------------------
// PROTECTED
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PRIVATE
//-------------------------------------------------------------------

std::shared_ptr<cb::ecs::ComponentsContainer> cb::ecs::EntityComponentDatabaseModifier::getComponentsContainerForEntity(const cb::ecs::Entity& entity)
{
	if (!m_entities_components_container->hasEntity(entity))
	{
		m_entities_components_container->addEntity(entity);
	}
	return m_entities_components_container->getComponentsContainerForEntity(entity);
}

//-------------------------------------------------------------------