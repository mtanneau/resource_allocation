cmake_minimum_required(VERSION 3.14)
project(resource_allocation)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories

# Add libraries (if any)

# Main executable
add_executable(resource_allocation)
target_sources(resource_allocation
  PRIVATE
    src/main.cpp
    src/problem_data.cpp
)

# Testing
enable_testing()

# Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.17.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Test executable
add_executable(test_problem_data)
target_link_libraries(test_problem_data GTest::gtest_main)
# TODO: create library and link to test executable, instead of linking all the source code
target_sources(test_problem_data
  PRIVATE
    tests/test_problem_data.cpp
    src/problem_data.cpp
  
  PRIVATE
    FILE_SET HEADERS
    BASE_DIRS src
    FILES
      src/problem_data.hpp
)

# Define test data directory as a compile definition
target_compile_definitions(test_problem_data PRIVATE TEST_DATA_DIR="${PROJECT_SOURCE_DIR}/tests/data")

# Register test
include(GoogleTest)
gtest_discover_tests(test_problem_data)
