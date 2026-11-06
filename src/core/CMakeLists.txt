add_library(core STATIC
        src/Genome.cpp
        src/Creature.cpp
        src/World.cpp
        src/Evolution.cpp
)

target_include_directories(core PUBLIC include)