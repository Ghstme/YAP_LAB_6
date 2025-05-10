#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>
#include "exceptions.h"

class Weapon {
private:
    std::string name;
    int damage;
    int range;

public:
    Weapon(const std::string& name = "", int damage = 0, int range = 0);
    
    void hit(class BaseCharacter& actor, class BaseCharacter& target);
    
    friend std::ostream& operator<<(std::ostream& os, const Weapon& weapon);
    friend std::istream& operator>>(std::istream& is, Weapon& weapon);
    
    const std::string& getName() const;
    int getDamage() const;
    int getRange() const;
};

#endif // WEAPON_H