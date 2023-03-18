cmake_minimum_required(VERSION 3.25.1)

# Set a variable to refere to this
set(This ExampleTest)

# Dependencies
add_subdirectory(googletest)

# Add SOURCES (tests go without headers)
set(SOURCES
    ExampleTests.cpp
)

add_executable(${This} ${SOURCES})

target_link_libraries(${This} PUBLIC
    gtest_main      # provided by GoogleTest (main program to test)
    TestBlueprint   # what is going to be tested
)

# Tell CMake that this is a unit test
add_test(
    NAME ${This}
    COMMAND ${This}
)