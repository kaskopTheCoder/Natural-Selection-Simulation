
cmake_minimum_required(VERSION 3.20)
project(mutationSim LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_ASM_STANDARD_REQUIRED ON)

add_subdirectory(src/core)

add_executable(headless src/headless/main.cpp)
target_link_libraries(headless PRIVATE core)

enable_testing()
add_subdirectory(test)
