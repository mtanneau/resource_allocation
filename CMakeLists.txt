cmake_minimum_required(VERSION 3.10)
project(resource_allocation VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Library for file parsing
add_library(file_parser src/file_parser.cpp)

# Main executable
add_executable(resource_allocation src/main.cpp)
target_link_libraries(resource_allocation file_parser)

# Testing
enable_testing()

# Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Test executable
add_executable(test_file_parser tests/test_file_parser.cpp)
target_link_libraries(test_file_parser file_parser gtest_main)

# Register test
add_test(NAME test_file_parser COMMAND test_file_parser)
