//-------------------------------------------------------------------
// CONSTRUCTOR - DESTRUCTOR
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PUBLIC
//-------------------------------------------------------------------

template <class T>
std::size_t cb::ecs::ComponentIndexGenerator::getComponentIndex()
{
	if(doesNotHaveTypeIndexForComponent<T>())
	{
		addTypeIndexForComponent<T>();
	}
	return getComponentIndexForComponentTypeIndex<T>();
}

//-------------------------------------------------------------------
// PROTECTED
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PRIVATE
//-------------------------------------------------------------------

template <class T>
bool cb::ecs::ComponentIndexGenerator::doesNotHaveTypeIndexForComponent()
{
	std::type_index component_type_index = createTypeIndexForComponent<T>();
	auto it_component_type = m_component_type_to_index.find(component_type_index);
	return it_component_type == m_component_type_to_index.end();
}

//-------------------------------------------------------------------

template <class T>
void cb::ecs::ComponentIndexGenerator::addTypeIndexForComponent()
{
	std::type_index component_type_index = createTypeIndexForComponent<T>();
	m_component_type_to_index.insert(std::make_pair(component_type_index, m_component_type_to_index.size()));
}

//-------------------------------------------------------------------

template <class T>
std::size_t cb::ecs::ComponentIndexGenerator::getComponentIndexForComponentTypeIndex()
{
	return m_component_type_to_index[createTypeIndexForComponent<T>()];
}

//-------------------------------------------------------------------

template <class T>
std::type_index cb::ecs::ComponentIndexGenerator::createTypeIndexForComponent()
{
	return std::type_index(typeid(T));
}

//-------------------------------------------------------------------