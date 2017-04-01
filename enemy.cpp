#include "enemy.hpp"

Enemy::Enemy(World *world, Player *player) : Character(10, world)
{
    setMapX(0);
    setMapY(0);
    setX(3);
    setY(3);
    world->world[getMapX()][getMapY()]->map[getX()][getY()]->setStyle(2);
}
