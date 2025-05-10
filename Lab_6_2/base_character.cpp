#include "base_character.h"

BaseCharacter::BaseCharacter(double pos_x, double pos_y, int hp) 
    : pos_x(pos_x), pos_y(pos_y), hp(hp) {}

void BaseCharacter::move(double delta_x, double delta_y) {
    pos_x += delta_x;
    pos_y += delta_y;
}

bool BaseCharacter::is_alive() const {
    return hp > 0;
}

void BaseCharacter::get_damage(int amount) {
    hp -= amount;
}

double BaseCharacter::get_x() const { return pos_x; }
double BaseCharacter::get_y() const { return pos_y; }
int BaseCharacter::get_hp() const { return hp; }