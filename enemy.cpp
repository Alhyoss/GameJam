#include "enemy.hpp"

Enemy::Enemy(World *world, Player *p) : Character(10, world, 15)
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
    Node* map[14][14];
    std::vector<Node*> opened;
    std::vector<Node*> closed;
    for(int i=0; i<14; i++)
    {
        for(int j=0; j<14; j++)
        {
            map[i][j] = new Node(i, j);
            if(world->world[getMapX()][getMapY()]->map[getX()][getY()]->getStyle()==1
                || world->world[getMapX()][getMapY()]->map[getX()][getY()]->getStyle()==2)
                closed.push_back(map[i][j]);
        }
    }
}
