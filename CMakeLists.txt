cmake_minimum_required(VERSION 2.8)
project(RPG)

find_package(SDL 1.2 REQUIRED)
include_directories(${SDL_INCLUDE_DIR})

add_executable(rpg
.gitignore
Archer.cpp
Archer.hpp
Combat.cpp
Combat.hpp
data/Background_Test.bmp
data/Placeholder_Enemy.bmp
data/Test.bmp
data/hero_sprite_test.bmp
Enemy.cpp
Enemy.hpp
Framework.cpp
Framework.hpp
Game.cpp
Game.hpp
Log.cpp
Log.hpp
Mage.cpp
Mage.hpp
Player.cpp
Player.hpp
README.md
RPG.vcproj
Random.cpp
Random.hpp
Singleton.hpp
Sprite.cpp
Sprite.hpp
Timer.cpp
Timer.hpp
Warrior.cpp
Warrior.hpp
main.cpp
)

target_link_libraries(rpg ${SDL_LIBRARY})
