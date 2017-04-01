#include "character.hpp"

#include <iostream>

Character::Character(int vitality, World *world, int deffence)
{
    this->vitality = vitality;
    this->world = world;
    this->deffence=deffence;
}



int Character::getVitality()
{
    return vitality;
}

void Character::setVitality(int v)
{
    vitality = v;
}
