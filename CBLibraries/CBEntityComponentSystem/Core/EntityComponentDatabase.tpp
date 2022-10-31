//-------------------------------------------------------------------
// CONSTRUCTOR - DESTRUCTOR
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PUBLIC
//-------------------------------------------------------------------

template<class T, typename... Args>
std::shared_ptr<T> cb::ecs::EntityComponentDatabase::addComponentToEntity(const cb::ecs::Entity& entity, Args... args)
{
	addNewComponentOfTypeToEntityComponentsContainer<T, Args...>(entity, args...);
	return getComponentFromEntity<T>(entity);
}

//-------------------------------------------------------------------

template<class T>
std::shared_ptr<T> cb::ecs::EntityComponentDatabase::getComponentFromEntity(const cb::ecs::Entity& entity)
{
	std::shared_ptr<T> component = nullptr;
	if (hasComponentForEntity<T>(entity))
	{
		component = getExistingComponentForKnownEntity<T>(entity);
	}
	return component;
}

//-------------------------------------------------------------------

template <class T>
bool cb::ecs::EntityComponentDatabase::hasComponentForEntity(const cb::ecs::Entity& entity)
{
	return hasEntity(entity) && knownEntityHasComponent<T>(entity);
}

//-------------------------------------------------------------------
// PROTECTED
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PRIVATE
//-------------------------------------------------------------------

template <class T, typename... Args>
void cb::ecs::EntityComponentDatabase::addNewComponentOfTypeToEntityComponentsContainer(const cb::ecs::Entity& entity, Args... args)
{
	cb::ecs::ComponentsContainer& components_container = getValidComponentsContainerForEntity(entity);
	components_container.addComponentAtIndex(createComponentOfType<T, Args...>(args...), getIndexForComponent<T>());
}

//-------------------------------------------------------------------

template <class T>
std::shared_ptr<T> cb::ecs::EntityComponentDatabase::getExistingComponentForKnownEntity(const cb::ecs::Entity& entity)
{
	cb::ecs::ComponentsContainer& components_container = getValidComponentsContainerForEntity(entity);
	return std::dynamic_pointer_cast<T>(components_container.getComponentAtIndex(getIndexForComponent<T>()));
}

//-------------------------------------------------------------------

template <class T>
bool cb::ecs::EntityComponentDatabase::knownEntityHasComponent(const cb::ecs::Entity& entity)
{
	cb::ecs::ComponentsContainer& components_container = getValidComponentsContainerForEntity(entity);
	return components_container.hasComponentAtIndex(getIndexForComponent<T>());
}

//-------------------------------------------------------------------

template <class T>
std::size_t cb::ecs::EntityComponentDatabase::getIndexForComponent()
{
	return m_component_index_generator->getComponentIndex<T>();
}

//-------------------------------------------------------------------

template <class T, typename... Args>
std::shared_ptr<T> cb::ecs::EntityComponentDatabase::createComponentOfType(Args... args)
{
	return std::make_shared<T>(args...);
}

//-------------------------------------------------------------------