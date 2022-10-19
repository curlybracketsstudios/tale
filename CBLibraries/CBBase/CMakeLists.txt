cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME CBBase)

project(${PROJECT_NAME} VERSION 1.0.0 DESCRIPTION "CBBase is the library containing the classes for basic concepts")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set (BOOST_ROOT ${CMAKE_CURRENT_LIST_DIR}/../../../../ThirdParty/Boost/)
set (BOOST_INCLUDEDIR ${CMAKE_CURRENT_LIST_DIR}/../../../../ThirdParty/Boost/include)
set (BOOST_LIBRARYDIR ${CMAKE_CURRENT_LIST_DIR}/../../../../ThirdParty/Boost/lib)
set (BOOST_MIN_VERSION "1.68.0")
set(Boost_USE_MULTITHREADED ON )
find_package(Boost ${BOOST_MIN_VERSION} REQUIRED)
if (NOT Boost_FOUND)
  message(FATAL_ERROR "Fatal error: Boost (version >= 1.68) required.")
else()
  message(STATUS "Setting up BOOST")
  message(STATUS " Includes - ${Boost_INCLUDE_DIRS}")
  message(STATUS " Library  - ${Boost_LIBRARY_DIRS}")
endif (NOT Boost_FOUND)

add_library(${PROJECT_NAME} SHARED
	GUID/GUID.cpp
	GUID/GUID.h
	CBBaseLibrary.h
)

target_compile_definitions(${PROJECT_NAME} PRIVATE CBBASE_LIBRARY)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/.)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../../)

target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIRS})

if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /WX)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()