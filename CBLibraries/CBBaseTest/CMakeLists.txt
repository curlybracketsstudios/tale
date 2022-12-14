cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME CBBaseTest)

project(${PROJECT_NAME} VERSION 1.0.0 DESCRIPTION "CBBaseTest contains the tests for the CBBase library")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(${CMAKE_CURRENT_LIST_DIR}/../)
include_directories(${CMAKE_CURRENT_LIST_DIR}/../../)

add_executable(${PROJECT_NAME}
	GUID/GUIDTest.cpp
	CBBaseTest.cpp
 )

target_link_libraries(${PROJECT_NAME} CBBase)

target_link_libraries(${PROJECT_NAME} gtest)
target_link_libraries(${PROJECT_NAME} gmock)

include_directories(${CMAKE_SOURCE_DIR}/../../../../ThirdParty/googletest/googletest/include/)

if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /WX)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

add_custom_target(Run_${PROJECT_NAME} ALL COMMAND ${PROJECT_NAME} --gtest_brief=1)