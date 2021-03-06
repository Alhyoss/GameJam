#ifndef _ENNEMI_HPP_
#define _ENNEMI_HPP_ 1

#include "character.hpp"
#include "../World/world.hpp"
#include "player.hpp"
#include <cmath>

class Node
{
    public:
        Node()
        {
            parent = NULL;
        }

        Node(int x, int y) : Node()
        {
            this->x = x;
            this->y = y;
        }

        Node(int f, int h, int g, int x, int y) : Node(x, y)
        {
            fCost = f;
            hCost = h;
            gCost = g;
        }
        Node *parent;
        int x, y;
        int fCost, hCost, gCost;
        int open;
};

class Enemy : public Character
{
    public:
        Enemy(World *world, Player *p);
        void move();
        void searchPath();
        void backTrace(Node *end);

    private:
        Player *player;
        std::vector<Node*> path;
};

#endif
