#include "character.hpp"

#include <iostream>

Character::Character(int vitality, World *world)
{
    this->vitality = vitality;
    this->world = world;
    alive = true;

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
tour--;

if (ran>=car->deffence)
{
  if (ran==20)
  {
    car->setVitality(car->getVitality() - (dmg + crit));
  }else{
    car->setVitality(car->getVitality() - dmg);
  }
  if (car->getVitality()<=0)
    {
      car->alive = false;
      car->setVitality(0);
      world->world[car->getMapX()][car->getMapY()]->map[car->getX()][car->getY()]->setStyle(0);
    }

}
}


void Character::setVitality(int v)
{
    vitality = v;
}
