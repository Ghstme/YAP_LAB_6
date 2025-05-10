#ifndef BASE_ENEMY_H
#define BASE_ENEMY_H

#include "base_character.h"
#include "weapon.h"
#include <iostream>

class BaseEnemy : public BaseCharacter {
private:
    Weapon weapon;

public:
    BaseEnemy(double pos_x = 0, double pos_y = 0, const Weapon& weapon = Weapon(), int hp = 100);
    
    void hit(BaseCharacter& target);
    
    friend std::ostream& operator<<(std::ostream& os, const BaseEnemy& enemy);
};

#endif // BASE_ENEMY_H