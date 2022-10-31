#include "CBEntityComponentSystem/Core/ComponentsContainer.h"

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