cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME Tale)

project(${PROJECT_NAME} VERSION 1.0.0 DESCRIPTION "Tale contains only the main method/exe")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(${CMAKE_CURRENT_LIST_DIR}/../)
include_directories(${CMAKE_CURRENT_LIST_DIR}/../../)

add_executable(${PROJECT_NAME}
    main.cpp
)

#target_link_libraries(${PROJECT_NAME} TaleLib)

if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /WX)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()