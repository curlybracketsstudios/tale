//-------------------------------------------------------------------
// CONSTRUCTOR - DESTRUCTOR
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PUBLIC
//-------------------------------------------------------------------

template<class T>
std::shared_ptr<T> cb::ecs::ComponentsContainer::addComponent()
{
	std::size_t component_index = createValidComponentIndex<T>();
	if (hasNoComponentAtIndex(component_index))
	{
		setComponentAtIndex(createTypedComponent<T>(), component_index);
	}
	return getTypedComponentAtIndex<T>(component_index);
}

//-------------------------------------------------------------------

template<class T>
std::shared_ptr<T> cb::ecs::ComponentsContainer::getComponent()
{
	std::size_t component_index = createValidComponentIndex<T>();
	return getTypedComponentAtIndex<T>(component_index);
}

//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PROTECTED
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PRIVATE
//-------------------------------------------------------------------

template <class T>
std::size_t cb::ecs::ComponentsContainer::createValidComponentIndex()
{
	std::size_t component_index = getComponentIndex<T>();
	verifyAndUpdateComponentsContainerSize();
	return component_index;
}

//-------------------------------------------------------------------

template <class T>
std::size_t cb::ecs::ComponentsContainer::getComponentIndex()
{
	return m_component_index_generator->getComponentIndex<T>();
}

//-------------------------------------------------------------------

template <class T>
std::shared_ptr<T> cb::ecs::ComponentsContainer::getTypedComponentAtIndex(std::size_t index)
{
	return std::dynamic_pointer_cast<T>(getComponentAtIndex(index));
}

//-------------------------------------------------------------------

template <class T>
std::shared_ptr<T> cb::ecs::ComponentsContainer::createTypedComponent()
{
	return std::make_shared<T>();
}

//-------------------------------------------------------------------