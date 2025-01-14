cmake_minimum_required(VERSION 3.10)

project(EmptyBaseOptimizationTest VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/utils)

add_executable(EBOExample src/ebo_example.cpp)
add_executable(CompressedPairExample src/compressed_pair_example.cpp)
add_executable(NoUniqueAddressExample src/no_unique_address_example.cpp)
