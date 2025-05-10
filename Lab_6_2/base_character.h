#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H

#include <iostream>

class BaseCharacter {
protected:
    double pos_x;
    double pos_y;
    int hp;

public:
    BaseCharacter(double pos_x = 0, double pos_y = 0, int hp = 100);
    
    virtual void move(double delta_x, double delta_y);
    bool is_alive() const;
    void get_damage(int amount);
    
    double get_x() const;
    double get_y() const;
    int get_hp() const;
};

#endif // BASE_CHARACTER_H