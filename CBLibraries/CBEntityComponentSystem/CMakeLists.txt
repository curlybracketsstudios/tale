cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME CBEntityComponentSystem)

project(${PROJECT_NAME} VERSION 1.0.0 DESCRIPTION "CBEntityComponentSystem is the library containing the classes for working with an ECS")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(${PROJECT_NAME} SHARED	
	Core/Component/ComponentIndexGenerator.cpp
	Core/Component/ComponentIndexGenerator.h
	Core/Component/ComponentIndexGenerator.tpp
	Core/Component/ComponentsContainer.cpp
	Core/Component/ComponentsContainer.h
	Core/Component.cpp
	Core/Component.h
	Core/Entity.cpp
	Core/Entity.h
	Core/EntityComponentDatabaseModifier.cpp
	Core/EntityComponentDatabaseModifier.h
	Core/EntityComponentDatabaseModifier.tpp
	Core/EntityComponentDatabaseQuerier.cpp
	Core/EntityComponentDatabaseQuerier.h
	Core/EntitiesComponentsContainer.cpp
	Core/EntitiesComponentsContainer.h
	Core/EntityFactory.cpp
	Core/EntityFactory.h
	CBEntityComponentSystemLibrary.h
)

target_compile_definitions(${PROJECT_NAME} PRIVATE CBENTITYCOMPONENTSYSTEM_LIBRARY)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/.)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../../)

target_link_libraries(${PROJECT_NAME} CBBase)

if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /WX)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()