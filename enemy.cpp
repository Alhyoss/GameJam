#include "enemy.hpp"

Enemy::Enemy(World *world, Player *p) : Character(10, world)
{
    player = p;
    setMapX(0);
    setMapY(0);
    setX(3);
    setY(3);
    world->world[getMapX()][getMapY()]->map[getX()][getY()]->setStyle(2);
}

void Enemy::searchPath()
{
    
    std::vector<Node*> opened;
    std::vector<Node*> closed;
}
