#include "CBEntityComponentSystem/Core/EntityComponentDatabaseQuerier.h"

//-------------------------------------------------------------------
// CONSTRUCTOR - DESTRUCTOR
//-------------------------------------------------------------------

cb::ecs::EntityComponentDatabaseQuerier::EntityComponentDatabaseQuerier
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

//-------------------------------------------------------------------
// PROTECTED
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PRIVATE
//-------------------------------------------------------------------