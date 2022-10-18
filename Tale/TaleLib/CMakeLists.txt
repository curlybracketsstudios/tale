cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME TaleLib)

project(${PROJECT_NAME} VERSION 1.0.0 DESCRIPTION "TaleLib contains the Tale library classes")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include_directories(${CMAKE_CURRENT_LIST_DIR}/../)
include_directories(${CMAKE_CURRENT_LIST_DIR}/../../)


add_library(${PROJECT_NAME} STATIC
)

if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /WX)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()