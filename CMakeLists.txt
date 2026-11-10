
cmake_minimum_required(VERSION 3.20)
project(mutationSim LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_ASM_STANDARD_REQUIRED ON)

add_subdirectory(src/core)

add_executable(headless src/headless/main.cpp)
target_link_libraries(headless PRIVATE core)

enable_testing()
add_subdirectory(test)

include(FetchContent)
set(SFML_BUILD_AUDIO OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_NETWORK OFF CACHE BOOL "" FORCE)

FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.1)
FetchContent_MakeAvailable(SFML)

add_subdirectory(src/app)
