
add_executable(simulationApp src/main.cpp)

add_library(app STATIC
    src/Application.cpp
    src/Simulation.cpp
    src/Controller.cpp
    src/RenderHandler.cpp
)

target_include_directories(app PUBLIC include)
target_link_libraries(app PRIVATE core sfml-graphics sfml-window sfml-system ImGui-SFML::ImGui-SFML)

target_link_libraries(simulationApp PRIVATE app)

