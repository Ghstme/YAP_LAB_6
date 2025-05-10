#include "main_hero.h"
#include "base_enemy.h"
#include <iostream>

MainHero::MainHero(double pos_x, double pos_y, const std::string& name, int hp)
    : BaseCharacter(pos_x, pos_y, hp), name(name), current_weapon_index(0) {}

void MainHero::hit(BaseEnemy& target) {
    if (weapons.empty()) {
        throw NoWeaponException();
    }
    weapons[current_weapon_index].hit(*this, target);
}

void MainHero::add_weapon(const Weapon& weapon) {
    weapons.push_back(weapon);
    if (weapons.size() == 1) {
        current_weapon_index = 0;
    }
    std::cout << "Подобрал " << weapon << std::endl;
}

void MainHero::next_weapon() {
    if (weapons.empty()) {
        throw NoWeaponException();
    }
    if (weapons.size() == 1) {
        std::cout << "У меня только одно оружие" << std::endl;
        return;
    }
    current_weapon_index = (current_weapon_index + 1) % weapons.size();
    std::cout << "Сменил оружие на " << weapons[current_weapon_index] << std::endl;
}

void MainHero::heal(int amount) {
    hp += amount;
    if (hp > 200) hp = 200;
    std::cout << "Полечился, теперь здоровья " << hp << std::endl;
}

const std::string& MainHero::getName() const { return name; }