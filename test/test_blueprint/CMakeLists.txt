cmake_minimum_required(VERSION 3.25.1)

# Set a variable to refere to this
set(This TestBlueprint)

# Set the name of the project and what language to use
project(${This} CXX)

# Set the version of the language (let the build system generator know)
set(CMAKE_CXX_STANDARD 17)

# Settings for libraries that are going to be mixed together into executables
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
#
# Position Independent Code (PIC) is a feature of some compilers that allows
# the code to be loaded at any memory address, without requiring it to be
# linked to a specific address. This can be useful for shared libraries,
# because it allows the library to be loaded into any part of memory, 
# without causing conflicts with other shared libraries or the executable.

enable_testing()

# Dependencies
add_subdirectory(test)
# Note. Every subdirectory is expected to have a `CMakeLists.txt`

# Add HEADERS
include_directories(include)

# Add SOURCES
set(SOURCES
    src/Example.cpp
)

add_library(${This} STATIC ${SOURCES})
#
# `Library` means it is going to be linked with other things to form programs.
# This is important when we run test: GoogleTest will be the main program and
# it will import the other code as libraries.
# ----------------------------------------------------------------------------
# Precisely: we'll split the code in two pieces, the actual code and the tests.
# The test will be a program itself, in which the tested code will be imported
# as library.