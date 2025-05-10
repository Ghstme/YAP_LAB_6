#include "main_hero.h"
#include "base_enemy.h"
#include "weapon.h"
#include "exceptions.h"
#include <iostream>
#include <windows.h>

void battleDemo() {
    MainHero hero(0, 0, "Артур", 150);

    Weapon sword("Меч", 30, 5);
    Weapon bow("Лук", 20, 15);

    hero.add_weapon(sword);
    hero.add_weapon(bow);

    BaseEnemy enemy1(3, 4, Weapon("Топор", 25, 3), 80);
    BaseEnemy enemy2(10, 0, Weapon("Копье", 15, 8), 60);

    std::cout << "\n=== Начало битвы ===\n";

    try {
        std::cout << "\nБой с врагом 1:\n";
        std::cout << enemy1 << std::endl;
        hero.hit(enemy1);
        hero.hit(enemy1);
        hero.next_weapon();
        hero.hit(enemy1);
    } catch (const GameException& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    hero.move(7, 0);

    try {
        std::cout << "\nБой с врагом 2:\n";
        std::cout << enemy2 << std::endl;
        hero.hit(enemy2);
        hero.hit(enemy2);
        hero.hit(enemy2);
    } catch (const GameException& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    hero.heal(50);

    std::cout << "\n=== Битва завершена ===\n";
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    try {
        battleDemo();
    } catch (const std::exception& e) {
        std::cerr << "Неожиданная ошибка: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}