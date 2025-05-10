#include "base_enemy.h"
#include <iostream>

BaseEnemy::BaseEnemy(double pos_x, double pos_y, const Weapon& weapon, int hp)
    : BaseCharacter(pos_x, pos_y, hp), weapon(weapon) {}

void BaseEnemy::hit(BaseCharacter& target) {
    weapon.hit(*this, target);
}

std::ostream& operator<<(std::ostream& os, const BaseEnemy& enemy) {
    os << "Враг на позиции (" << enemy.pos_x << ", " << enemy.pos_y 
       << ") с оружием " << enemy.weapon;
    return os;
}