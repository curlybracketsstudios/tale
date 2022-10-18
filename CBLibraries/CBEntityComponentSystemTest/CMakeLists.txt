cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME CBEntityComponentSystemTest)

project(${PROJECT_NAME} VERSION 1.0.0 DESCRIPTION "CBEntityComponentSystemTest contains the tests for the CBEntityComponentSystem library")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(${CMAKE_CURRENT_LIST_DIR}/../)
include_directories(${CMAKE_CURRENT_LIST_DIR}/../../)

add_executable(${PROJECT_NAME}
	CBEntityComponentSystemTest.cpp
    EntityComponentDatabaseTest.cpp
 )

target_link_libraries(${PROJECT_NAME} CBEntityComponentSystem)

target_link_libraries(${PROJECT_NAME} gtest)
target_link_libraries(${PROJECT_NAME} gmock)

include_directories(${CMAKE_SOURCE_DIR}/../../../../ThirdParty/googletest/googletest/include/)

if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /WX)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

add_custom_command(TARGET ${PROJECT_NAME}
                   POST_BUILD
                   COMMAND ${PROJECT_NAME} --gtest_brief=1
                   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                   COMMENT "run ${PROJECT_NAME} in ${CMAKE_CURRENT_SOURCE_DIR}"
                   VERBATIM
)
