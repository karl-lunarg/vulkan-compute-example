cmake_minimum_required (VERSION 3.8)
project(vulkan_compute_example)

option(VULKAN_COMPUTE_EXAMPLE_BUILD_TESTS "Build tests for vulkan compute example" ON)
option(VULKAN_COMPUTE_EXAMPLE_BUILD_BENCHMARKS "Build benchmarks for vulkan compute example" ON)

set(CMAKE_CXX_STANDARD 14)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/config)
enable_testing()

add_subdirectory(src)
add_subdirectory(test)
