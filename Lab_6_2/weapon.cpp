#include "weapon.h"
#include "base_character.h"
#include <cmath>
#include <iostream>

Weapon::Weapon(const std::string& name, int damage, int range) 
    : name(name), damage(damage), range(range) {}

void Weapon::hit(BaseCharacter& actor, BaseCharacter& target) {
    if (!target.is_alive()) {
        std::cout << "Враг уже повержен" << std::endl;
        return;
    }
    
    double distance = sqrt(pow(actor.get_x() - target.get_x(), 2) + 
                      pow(actor.get_y() - target.get_y(), 2));
    
    if (distance > range) {
        std::cout << "Враг слишком далеко для оружия " << name << std::endl;
        return;
    }
    
    std::cout << "Врагу нанесен урон оружием " << name 
              << " в размере " << damage << std::endl;
    target.get_damage(damage);
}

std::ostream& operator<<(std::ostream& os, const Weapon& weapon) {
    os << weapon.name;
    return os;
}

std::istream& operator>>(std::istream& is, Weapon& weapon) {
    is >> weapon.name >> weapon.damage >> weapon.range;
    return is;
}

const std::string& Weapon::getName() const { return name; }
int Weapon::getDamage() const { return damage; }
int Weapon::getRange() const { return range; }