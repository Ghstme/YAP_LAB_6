#ifndef MAIN_HERO_H
#define MAIN_HERO_H

#include "base_character.h"
#include "weapon.h"
#include "exceptions.h"
#include <vector>
#include <string>
#include <iostream>

class BaseEnemy;

class MainHero : public BaseCharacter {
private:
    std::string name;
    std::vector<Weapon> weapons;
    size_t current_weapon_index;

public:
    MainHero(double pos_x = 0, double pos_y = 0, const std::string& name = "Герой", int hp = 100);
    
    void hit(BaseEnemy& target);
    void add_weapon(const Weapon& weapon);
    void next_weapon();
    void heal(int amount);
    
    const std::string& getName() const;
};

#endif // MAIN_HERO_H