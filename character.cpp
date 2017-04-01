#include "character.hpp"

#include <iostream>

Character::Character(int vitality, World *world)
{
    this->vitality = vitality;
    this->world = world;
  
}



int Character::getVitality()
{
    return vitality;
}
void Character::attack(Character* car)
{
int ran, dmg, crit;
ran = (rand() % 20) + 1;
crit = (rand() % 6) + 1;
dmg = atk - (rand() % 15);

if (ran>=car->deffence)
{
  if (ran==20)
  {
    car->setVitality(car->getVitality() - (dmg + crit));
  }else{
    car->setVitality(car->getVitality() - dmg);
  }

}
}


void Character::setVitality(int v)
{
    vitality = v;
}
