cmake_minimum_required(VERSION 3.25.1)

# Settings
set(This CppProject)
project(${This} CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

# Dependencies
add_subdirectory(test)

# Add HEADERS
include_directories(include)

# Add SOURCES
set(SOURCES
    src/Palindrome_int.cpp
)

add_library(${This} STATIC ${SOURCES})

# To make also the main executable (other than the GTests)
add_executable(main main.cpp)
target_link_libraries(main ${This})