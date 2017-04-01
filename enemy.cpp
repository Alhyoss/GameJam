#include "enemy.hpp"

#include <iostream>

Enemy::Enemy(World *world, Player *p) : Character(100, world)
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
    for(int i=0; i<14; i++)
    {
        for(int j=0; j<14; j++)
        {
            map[i][j] = new Node(i, j);
            if(world->world[getMapX()][getMapY()]->map[i][j]->style==1
                || world->world[getMapX()][getMapY()]->map[i][j]->style==2)
                map[i][j]->open = 0;
            else
                map[i][j]->open = 1;
        }
    }
    Node *current = map[getX()][getY()];
    current->gCost = 0;
    current->hCost = abs(getX()-player->getX())+abs(getY()-player->getY());
    current->fCost = current->gCost + current->hCost;
    opened.push_back(current);
    current->open = 2;

    struct closerToEnd
    {
        inline bool operator() (const Node* n1, const Node* n2)
        {
            return (n1->fCost > n2->fCost);
        }
    };

    while(true)
    {
        std::sort(opened.begin(), opened.end(), closerToEnd());
        current = opened[opened.size()-1];
        std::cout << current->x << ", " << current->y << std::endl;
        if(current->x == player->getX() && current->y == player->getY())
        {
            path.clear();
            backTrace(current);
            break;
        }
        opened.pop_back();
        current->open = 0;
        std::vector<Node*> neighbours;
        if(current->y != 0)
            neighbours.push_back(map[current->x][current->y-1]);
        if(current->x != 0)
            neighbours.push_back(map[current->x-1][current->y]);
        if(current->x != 13)
            neighbours.push_back(map[current->x+1][current->y]);
        if(current->y != 13)
            neighbours.push_back(map[current->x][current->y+1]);
        for(Node* n : neighbours)
        {
            if(n->open == 0)
                continue;

            if(n->gCost > current->gCost+1 || n->open == 1)
            {
                n->gCost = current->gCost+1;
                n->hCost = abs(n->x-player->getX())+abs(n->y-player->getY());
                n->fCost = n->gCost + n->hCost;
                n->parent = current;
                if(n->open == 1)
                {
                    n->open = 2;
                    opened.push_back(n);
                }
            }
        }
    }
}

void Enemy::backTrace(Node *end)
{
    if(end != NULL)
    {
        path.push_back(end);
        backTrace(end->parent);
    }
}
