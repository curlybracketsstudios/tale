cmake_minimum_required(VERSION 3.15)

project(TaleAllLibraries)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../Binaries/${CMAKE_GENERATOR}/${CMAKE_BUILD_TYPE})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
	set(CMAKE_EXE_LINKER_FLAGS    "${CMAKE_EXE_LINKER_FLAGS} /MANIFEST:NO")
	set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} /MANIFEST:NO")
	set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /MANIFEST:NO")
endif()

# CMake appends /W3 by default, and having /W3 followed by /W4 will result in
# cl : Command line warning D9025 : overriding '/W3' with '/W4'.  Since this is
# a command line warning and not a compiler warning, it cannot be suppressed except
# by fixing the command line.
if(MSVC)
    string(REGEX REPLACE " /W3" " /W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()

add_subdirectory(Tale/TaleExe)
#add_subdirectory(Tale/TaleLib)
add_subdirectory(Tale/TaleTest)


add_subdirectory(../../ThirdParty/googletest googletest_build/files)