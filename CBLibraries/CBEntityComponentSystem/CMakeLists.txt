cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME CBEntityComponentSystem)

project(${PROJECT_NAME} VERSION 1.0.0 DESCRIPTION "CBEntityComponentSystem is the library containing the classes for working with an ECS")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(${PROJECT_NAME} SHARED
	CBEntityComponentSystemLibrary.h
	EntityComponentDatabase.cpp
	EntityComponentDatabase.h
)

target_compile_definitions(${PROJECT_NAME} PRIVATE CBENTITYCOMPONENTSYSTEM_LIBRARY)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/.)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../../)

if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /WX)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()