//-------------------------------------------------------------------
// CONSTRUCTOR - DESTRUCTOR
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PUBLIC
//-------------------------------------------------------------------

template <class T>
std::size_t cb::ecs::ComponentIndexGenerator::getComponentIndex()
{
	std::size_t component_index;
	std::type_index component_type_index(typeid(T));

	auto it_component_type = m_component_type_to_index.find(component_type_index);
	if (it_component_type != m_component_type_to_index.end())
	{
		component_index = it_component_type->second;
	}
	else
	{
		component_index = m_component_type_to_index.size();
		m_component_type_to_index.insert(std::make_pair(component_type_index, component_index));
	}

	return component_index;
}

//-------------------------------------------------------------------
// PROTECTED
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PRIVATE
//-------------------------------------------------------------------