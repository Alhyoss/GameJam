#include "character.hpp"

#include <iostream>

Character::Character(int vitality, World *world)
{
    this->vitality = vitality;
    this->world = world;
}

int Character::attack(Character *car)
{
    return 1;
}

int Character::getVitality()
{
    return vitality;
}

void Character::setVitality(int v)
{
    vitality = v;
}
