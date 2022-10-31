#include "CBEntityComponentSystem/Core/ComponentIndexGenerator.h"

//-------------------------------------------------------------------
// CONSTRUCTOR - DESTRUCTOR
//-------------------------------------------------------------------

cb::ecs::ComponentIndexGenerator::ComponentIndexGenerator()
	: m_component_type_to_index(std::unordered_map<std::type_index, std::size_t>())
{
}

//-------------------------------------------------------------------
// PUBLIC
//-------------------------------------------------------------------

std::size_t cb::ecs::ComponentIndexGenerator::getNumberOfComponents() const
{
	return m_component_type_to_index.size();
}

//-------------------------------------------------------------------
// PROTECTED
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PRIVATE
//-------------------------------------------------------------------