cmake_minimum_required(VERSION 3.28)
project(Lab_6_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab_6_2 main.cpp
        exceptions.h
        weapon.h
        weapon.cpp
        base_character.h
        base_character.cpp
        base_enemy.h
        base_enemy.cpp
        main_hero.h
        main_hero.cpp
)
