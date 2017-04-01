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
    Node* map[14][14];
    std::vector<Node*> opened;
    std::vector<Node*> closed;
    for(int i=0; i<14; i++)
    {
        for(int j=0; j<14; j++)
        {
            map[i][j] = new Node(i, j);
            if(world->world[getMapX()][getMapY()]->map[getX()][getY()]->style==1
                || world->world[getMapX()][getMapY()]->map[getX()][getY()]->style==2)
                closed.push_back(map[i][j]);
        }
    }
    Node *current = map[getX()][getY()];
    current->gCost = 0;
    current->hCost = abs(getX()-player->getX())+abs(getY()-player->getY());
    current->fCost = current->gCost + current->hCost;
    opened.push_back(current);
}
