cmake_minimum_required(VERSION 3.25.1)

# Settings
set(This Tests)

# Dependencies
add_subdirectory(googletest)

# Add SOURCES (tests go without headers)
set(SOURCES
    TestPalindrome_int.cpp
    TestRemoveElement.cpp
)

add_executable(${This} ${SOURCES})
target_link_libraries(${This} PUBLIC gtest_main CppProject)

add_test(
    NAME ${This}
    COMMAND ${This}
)